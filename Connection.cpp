//
// Created by Matt on 10/09/2016.
//

#include "Connection.h"

Connection::Connection(UDPAddress *remoteAddress) : remoteAddress(remoteAddress) {
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

void Connection::update() {
    //Process packet queue
}
