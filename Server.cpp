//
// Created by Matt on 12/09/2016.
//

#include <iostream>
#include "Server.h"

void Server::processIncomingPackets() {
    if (socket->receive() != 0) {
        //std::cout << "Received packet. Deserialising" << std::endl;
        Packet packet = Packet();
        PacketSerialiser serialiser = PacketSerialiser(socket->getReceivedData(),
                                                       (unsigned int) socket->getReceivedDataSize());
        packet.setSender(socket->getLastSender());
        if (packet.deserialise(&serialiser) == 0) {
            std::cout << "Received packet of type: " << packet.getType() << " From Sender: "
                      << packet.getSender()->getA() << "." << packet.getSender()->getB() << "."
                      << packet.getSender()->getC() << "." << packet.getSender()->getD() << ":"
                      << packet.getSender()->getPort() << std::endl;
            //connectionHandler->processPacket(&packet);
        } else {
            std::cerr << "Failed to deserialise packet" << std::endl;
        }
    }
}

Server::Server(UDPSocket *socket) : socket(socket) {
    running = true;
    ConnectionHandler c = ConnectionHandler(socket);
    connectionHandler = &c;
}

bool Server::update() {
    processIncomingPackets();
    return false;
}

bool Server::isRunning() {
    return running;
}