//
// Created by Matt on 15/09/2016.
//

#include <iostream>
#include "ConnectionHandler.h"

ConnectionHandler::ConnectionHandler(UDPSocket *socket) : socket(socket) {
    connectionMap = std::map<UDPAddress *, Connection>();
}

int ConnectionHandler::processPacket(Packet *packet) {
    std::cout << "Processing packet in the connection handler" << std::endl;

    //Determine owner, add it to their queue
    UDPAddress *sender = packet->getSender();
    if (connectionMap.find(sender) != connectionMap.end()) {
        //ConnectionMap contains sender
        std::cout << "Sender already connected, forwarding packet to their connection's packet queue: " << std::endl;
        connectionMap.at(sender).addPacket(packet);
    } else {
        //Create connection and forward it to them
        std::cout << "New sender. Creating connection" << std::endl;
        connectionMap.insert(std::make_pair(sender, Connection(sender, socket)));
        connectionMap.at(sender).addPacket(packet);
    }
}