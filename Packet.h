//
// Created by Matt on 12/09/2016.
//

#ifndef NETWORKING_TUTORIALS_PACKET_H
#define NETWORKING_TUTORIALS_PACKET_H

#include <cstdint>
#include "UDPAddress.h"
#include "PacketSerialiser.h"

class Packet {
public:
    enum Type {
        handshake
    };

    Packet();

    Packet(char *data, unsigned int dataSize);

    void setType(Type type);

    int deserialise(PacketSerialiser *serialiser);

    char *serialise(PacketSerialiser *serialiser);

    UDPAddress *getSender();

    const Type getType();

    union {
        struct Handshake {
            int version;
        } handshakeData;
    };

private:
    UDPAddress *sender;
    Type type;
};


#endif //NETWORKING_TUTORIALS_PACKET_H
