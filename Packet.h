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

    UDPAddress getSender();

    void setSender(UDPAddress sender);

    const Type getType();

    union Data {
        struct Handshake {
            int version;
        } handshakeData;
    };

    Type type;
    Data data;

private:
    UDPAddress sender = UDPAddress(0, 0);
};


#endif //NETWORKING_TUTORIALS_PACKET_H
