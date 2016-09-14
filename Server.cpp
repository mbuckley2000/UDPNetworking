//
// Created by Matt on 12/09/2016.
//

#include <iostream>
#include "Server.h"

Packet *Server::getPacket() {
    std::cout << "Waiting to receive packet" << std::endl;
    while (true) {
        if (socket->receive() != 0) {
            std::cout << "Received packet. Deserialising" << std::endl;
            Packet packet = Packet(socket->getReceivedData(), socket->getReceivedDataSize());
            std::cout << "Received packet of type: " << packet.getType() << std::endl;
            return &packet;
        }
    }
}

Server::Server(UDPSocket *socket) : socket(socket) {
    running = true;
}

bool Server::sendPacket(UDPAddress *addr, Packet *packet) {
    //Send
    std::cout << "Sending packet of type: " << packet->getType() << std::endl;
    char *buffer = (char *) calloc(1, 1024);
    PacketSerialiser serialiser = PacketSerialiser(buffer, 1024);
    packet->serialise(&serialiser);
    socket->send(addr, serialiser.getBuffer(), serialiser.getBufferSize());
}

bool Server::sendHandshake(UDPAddress *addr) {
    Packet packet = Packet();
    packet.setType(packet.handshake);
    sendPacket(addr, &packet);

}

bool Server::update() {
    Packet *packet = getPacket();

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
    return false;
}

bool Server::isRunning() {
    return running;
}