//
// Created by Matt on 12/09/2016.
//

#ifndef NETWORKING_TUTORIALS_PACKET_H
#define NETWORKING_TUTORIALS_PACKET_H

#include <cstdint>
#include "UDPAddress.h"

class Packet {
public:
    enum Type {
        handshake
    };

    Packet();

    void setType(Type type);

    UDPAddress *getSender();

    const Type getType();

    union data {
        struct handshake {

        };
    };

private:
    UDPAddress *sender;
    Type type;
};


#endif //NETWORKING_TUTORIALS_PACKET_H
