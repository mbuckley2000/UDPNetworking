//
// Created by Matt on 12/09/2016.
//

#include <iostream>
#include "Packet.h"

Packet::Packet() {}

void Packet::setType(Type packetType) {
    type = packetType;
}

const Packet::Type Packet::getType() {
    return type;
}

UDPAddress *Packet::getSender() {
    return sender;
}

Packet::Packet(char *data, unsigned int dataSize) {
    PacketSerialiser serialiser = PacketSerialiser(data, dataSize);
    deserialise(&serialiser);
}

int Packet::deserialise(PacketSerialiser *serialiser) {
    type = (Type) serialiser->readInt();
    switch (type) {
        case handshake: {
            data.handshakeData.version = serialiser->readInt();
            return 0;
        }

        default: {
            std::cerr << "Unrecognised packet type" << std::endl;
            return 1;
        }
    }
}

char *Packet::serialise(PacketSerialiser *serialiser) {
    serialiser->writeInt((int) type);
    switch (type) {
        case handshake: {
            serialiser->writeInt(data.handshakeData.version);
            break;
        }

        default: {
            std::cerr << "Unrecognised packet type" << std::endl;
            break;
        }
    }

    return serialiser->getBuffer();
}
