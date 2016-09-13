//
// Created by Matt on 12/09/2016.
//

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