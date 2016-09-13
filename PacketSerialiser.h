//
// Created by Matt on 13/09/2016.
//

#ifndef NETWORKING_TUTORIALS_PACKETSERIALISER_H
#define NETWORKING_TUTORIALS_PACKETSERIALISER_H


#include "Packet.h"

class PacketSerialiser {
public:
    PacketSerialiser(Packet *packet);

    PacketSerialiser(char *data, unsigned int dataSize);

    Packet *deserialise();

    char *serialise();

    int writeBool(bool data);

    bool readBool();

    int writeInt(int data);

    int readInt();

    int writeFloat(float data);

    float readFloat();

    int writeChar(char data);

    char readChar();

private:
    char *buffer;
    unsigned int bufferSize;
    unsigned int byteIndex;
};


#endif //NETWORKING_TUTORIALS_PACKETSERIALISER_H
