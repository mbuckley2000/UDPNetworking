//
// Created by Matt on 11/09/2016.
//

#ifndef NETWORKING_TUTORIALS_PACKET_H
#define NETWORKING_TUTORIALS_PACKET_H

#include <cstdint>

class BitPacker {
public:
    BitPacker(int bufferSize);

    void write(void* data, unsigned int size);

private:
    uint64_t scratch;
    int scratch_bits;
    int word_index;
    uint32_t* buffer;
    int bufferSize;
};


#endif //NETWORKING_TUTORIALS_PACKET_H
