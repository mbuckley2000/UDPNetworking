//
// Created by Matt on 12/09/2016.
//

#include <iostream>
#include "Server.h"

Packet *Server::getPacket() {
    if (socket->receive() == 1) {
        std::cout << "Received packet. Deserialising" << std::endl;
        Packet packet = Packet(socket->getReceivedData(), (unsigned int) socket->getReceivedDataSize());
        std::cout << "Received packet of type: " << packet.getType() << std::endl;
        return &packet;
    }

    return nullptr;
}

Server::Server(UDPSocket *socket) : socket(socket) {
    running = true;
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
    Packet *packet = getPacket();

    if (packet != nullptr) {
        switch (packet->getType()) {
            case packet->handshake: {
                //Make connection, starts in handshake mode
                //sendHandshake(packet->getSender());
                std::cout << "HANDSHAKE RECEIVED" << std::endl;
                break;
            }

            default: {
                std::cerr << "UNRECOGNISED PACKET TYPE" << std::endl;
                break;
            }
        }
    }

    return false;
}

bool Server::isRunning() {
    return running;
}