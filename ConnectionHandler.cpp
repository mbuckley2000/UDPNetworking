//
// Created by Matt on 15/09/2016.
//

#include <iostream>
#include "ConnectionHandler.h"

ConnectionHandler::ConnectionHandler(UDPSocket *socket) : socket(socket) {
    connections = std::list<Connection>();
}

int ConnectionHandler::processPacket(Packet *packet) {
    std::cout << "Processing packet in the connection handler" << std::endl;
    //Determine owner, add it to their queue

    UDPAddress sender = packet->getSender();

    bool hit = false;

    for (std::list<Connection>::iterator ci = connections.begin(); ci != connections.end(); ci++) {
        std::cout << ci->getAddress().getIntegerIP() << ", " << sender.getIntegerIP() << std::endl;
        if (ci->getAddress().getIntegerIP() == sender.getIntegerIP() &&
            ci->getAddress().getPort() == sender.getPort()) {
            //We have a match. Connection set contains the packet sender
            std::cout << "Sender already connected, forwarding packet to their connection's packet queue: "
                      << std::endl;
            ci->addPacket(packet);
            hit = true;
            break;
        }
    }

    if (!hit) {
        //Connection doesn't exist in set
        //Create connection and forward it to them
        std::cout << "New sender. Creating connection" << std::endl;
        Connection newConnection = Connection(sender, socket);
        newConnection.addPacket(packet);
        connections.push_back(newConnection);
    }
}