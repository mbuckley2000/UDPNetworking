//
// Created by Matt on 11/09/2016.
//

#ifndef NETWORKING_TUTORIALS_BITPACKER_H
#define NETWORKING_TUTORIALS_BITPACKER_H

#include <cstdint>
#include "Packet.h"

class BitPacker {
public:
    BitPacker(int bufferSize);

    BitPacker(char *data, int dataSize);

    BitPacker(Packet *packet);

    bool setData(char *data, int dataSize);

    char *pack(Packet *packet);

    int getPackedDataSize();

    Packet *unpack();

private:
    uint64_t scratch;
    int scratch_bits;
    int word_index;
    uint32_t* buffer;
    int bufferSize;
};


#endif //NETWORKING_TUTORIALS_BITPACKER_H
