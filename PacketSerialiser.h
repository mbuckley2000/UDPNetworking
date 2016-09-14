//
// Created by Matt on 13/09/2016.
//

#ifndef NETWORKING_TUTORIALS_PACKETSERIALISERR_H
#define NETWORKING_TUTORIALS_PACKETSERIALISERR_H


class PacketSerialiser {
public:
    PacketSerialiser(char *data, unsigned int dataSize);

    int writeBool(bool data);

    bool readBool();

    int writeInt(int data);

    int readInt();

    int writeFloat(float data);

    float readFloat();

    int writeChar(char data);

    char readChar();

    char *getBuffer() const;

    unsigned int getBufferSize() const;

private:
    char *buffer;
    unsigned int bufferSize;
    unsigned int byteIndex;
};


#endif //NETWORKING_TUTORIALS_PACKETSERIALISERR_H
