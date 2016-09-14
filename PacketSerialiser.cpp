//
// Created by Matt on 13/09/2016.
//

#include "PacketSerialiser.h"

PacketSerialiser::PacketSerialiser(char *data, unsigned int dataSize) {
    buffer = data;
    bufferSize = dataSize;
    byteIndex = 0;

    //std::cout << data[0] << std::endl;
}

int PacketSerialiser::writeBool(bool data) {
    if (byteIndex + sizeof(bool) < bufferSize) {
        buffer[byteIndex] = data;
        byteIndex += sizeof(bool);
        return 0;
    }
    return 1;
}

bool PacketSerialiser::readBool() {
    bool read = buffer[byteIndex];
    byteIndex += sizeof(bool);
    return read;
}

int PacketSerialiser::writeInt(int data) {
    if (byteIndex + sizeof(int) < bufferSize) {
        buffer[byteIndex] = data;
        byteIndex += sizeof(int);
        return 0;
    }
    return 1;
}

int PacketSerialiser::readInt() {
    int read = buffer[byteIndex];
    byteIndex += sizeof(int);
    return read;
}

int PacketSerialiser::writeFloat(float data) {
    if (byteIndex + sizeof(float) < bufferSize) {
        buffer[byteIndex] = data;
        byteIndex += sizeof(float);
        return 0;
    }
    return 1;
}

float PacketSerialiser::readFloat() {
    float read = buffer[byteIndex];
    byteIndex += sizeof(float);
    return read;
}

int PacketSerialiser::writeChar(char data) {
    if (byteIndex + sizeof(char) < bufferSize) {
        buffer[byteIndex] = data;
        byteIndex += sizeof(char);
        return 0;
    }
    return 1;
}

char PacketSerialiser::readChar() {
    char read = buffer[byteIndex];
    byteIndex += sizeof(char);
    return read;
}

char *PacketSerialiser::getBuffer() const {
    return buffer;
}

unsigned int PacketSerialiser::getBufferSize() const {
    return bufferSize;
}

unsigned int PacketSerialiser::getLength() {
    return byteIndex;
}
