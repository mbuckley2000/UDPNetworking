//
// Created by Matt on 13/09/2016.
//

#include <iostream>
#include "SerialiserTests.h"
#include "PacketSerialiser.h"
#include "Packet.h"

void SerialiserTests::runtests() {
    //Write
    char *serBuffer = (char *) calloc(1024, 1);

    PacketSerialiser serialiser = PacketSerialiser(serBuffer, 100);
    Packet packet = Packet();
    packet.setType(packet.handshake);
    packet.data.handshakeData.version = 123;
    char *buffer = packet.serialise(&serialiser);

    //Read
    Packet packet2 = Packet();
    PacketSerialiser serialiser2 = PacketSerialiser(buffer, 100);
    packet2.deserialise(&serialiser2);
    if (packet2.getType() == packet2.handshake) {
        std::cout << "WORKED" << std::endl;
    }
}