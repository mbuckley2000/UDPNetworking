//
// Created by Matt on 12/09/2016.
//

#include <iostream>
#include "Server.h"
#include "BitPacker.h"

Packet *Server::getPacket() {
    while (true) {
        if (socket->receive()) {
            BitPacker bitPacker = BitPacker(socket->getReceivedData(), socket->getReceivedDataSize());
            return bitPacker.unpack();
        }
    }
}

Server::Server(UDPSocket *socket) : socket(socket) {
    running = true;
}

bool Server::sendPacket(UDPAddress *addr, Packet *packet) {
    //Send
    BitPacker bitPacker = BitPacker(packet);
    char *data = bitPacker.pack(packet);
    int dataSize = bitPacker.getPackedDataSize();
    socket->send(addr, data, dataSize);
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