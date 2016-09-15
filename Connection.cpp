//
// Created by Matt on 10/09/2016.
//

#include <iostream>
#include "Connection.h"

Connection::Connection(UDPAddress remoteAddress, UDPSocket *socket) : remoteAddress(remoteAddress), socket(socket) {
    packetQueue = std::queue<Packet *>();
}

int Connection::connect() {
    unsigned short timeout = 10; //Seconds before aborting
    while(!connected) {
        //Connect
    }
}

bool Connection::isConnected() {
    return connected;
}

void Connection::addPacket(Packet *packet) {
    packetQueue.push(packet);
}

void Connection::sendPacket(Packet *packet) {
    std::cout << "Sending packet of type: " << packet->getType() << std::endl;
    char *buffer = (char *) calloc(sizeof(char), 1024);
    PacketSerialiser serialiser = PacketSerialiser(buffer, sizeof(char) * 1024);
    packet->serialise(&serialiser);
    socket->send(remoteAddress, serialiser.getBuffer(), serialiser.getLength());
}

bool Connection::hasPacket() {
    return !packetQueue.empty();
}

Packet *Connection::getPacket() {
    Packet *p = packetQueue.front();
    packetQueue.pop();
    return p;
}

UDPAddress Connection::getAddress() {
    return remoteAddress;
}
