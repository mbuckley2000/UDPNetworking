//
// Created by Matt on 12/09/2016.
//

#include <iostream>
#include "Server.h"

Packet *Server::processIncomingPackets() {
    if (socket->receive() == 1) {
        std::cout << "Received packet. Deserialising" << std::endl;
        Packet packet = Packet();
        PacketSerialiser serialiser = PacketSerialiser(socket->getReceivedData(),
                                                       (unsigned int) socket->getReceivedDataSize());
        if (packet.deserialise(&serialiser) == 0) {
            std::cout << "Received packet of type: " << packet.getType() << std::endl;
            //Determine owner, add it to their queue
            UDPAddress *sender = packet.getSender();
            if (connectionMap.find(sender) != connectionMap.end()) {
                //ConnectionMap contains sender
                connectionMap[sender].addPacket(&packet);
            } else {
                //Add to server queue
                packetQueue.push(&packet);
            }
        } else {
            std::cerr << "Failed to deserialise packet" << std::endl;
        }
    }
    return nullptr;
}

Server::Server(UDPSocket *socket) : socket(socket) {
    running = true;
    connectionMap = std::map<UDPAddress *, Connection>();
    packetQueue = std::queue<Packet *>();
}

bool Server::sendPacket(UDPAddress *addr, Packet *packet) {
    //Send
    std::cout << "Sending packet of type: " << packet->getType() << std::endl;
    char *buffer = (char *) calloc(sizeof(char), 1024);
    PacketSerialiser serialiser = PacketSerialiser(buffer, sizeof(char) * 1024);
    packet->serialise(&serialiser);
    socket->send(addr, serialiser.getBuffer(), serialiser.getLength());
}

bool Server::sendHandshake(UDPAddress *addr) {
    Packet packet = Packet();
    packet.setType(packet.handshake);
    sendPacket(addr, &packet);
}

bool Server::update() {
    processIncomingPackets();
    processPacketQueue();

    //Update all connections
    std::map<UDPAddress *, Connection>::iterator i = connectionMap.begin();
    while (i != connectionMap.end()) {
        i->second.update();
        i++;
    }
    return false;
}

void Server::processPacketQueue() {
    for (Packet *packet : packetQueue) {
        if (packet != nullptr) {
            switch (packet->getType()) {
                case packet->handshake: {
                    UDPAddress *sender = packet->getSender();
                    connectionMap.insert(std::make_pair(sender, Connection(sender)));
                    sendHandshake(sender);
                    std::cout << "HANDSHAKE RECEIVED. CONNECTION STARTED" << std::endl;
                    break;
                }

                default: {
                    std::cerr << "UNRECOGNISED PACKET TYPE" << std::endl;
                    break;
                }
            }
        }
    }
}

bool Server::isRunning() {
    return running;
}