//
// Created by Matt on 13/09/2016.
//

#include <iostream>
#include "SerialiserTests.h"
#include "PacketSerialiser.h"
#include "Packet.h"

void SerialiserTests::runtests() {
    //Write
    char *serBuffer = (char *) calloc(1, 1024);

    PacketSerialiser serialiser = PacketSerialiser(serBuffer, 100);
    Packet packet = Packet();
    packet.setType(packet.handshake);
    packet.data.handshakeData.version = 123;
    char *buffer = packet.serialise(&serialiser);



    //Read
    Packet packet2 = Packet(buffer, 100);
    std::cout << packet2.getType() << std::endl;
    std::cout << packet2.handshake << std::endl;
    std::cout << packet2.data.handshakeData.version << std::endl;

    if (packet2.getType() == packet2.handshake) {
        std::cout << "WORKED" << std::endl;
    }
}