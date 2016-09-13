//
// Created by Matt on 11/09/2016.
//

#include <cstdlib>
#include "BitPacker.h"

BitPacker::BitPacker(int bufferSize) : bufferSize(bufferSize) {
    buffer = (uint32_t*) calloc(sizeof(uint32_t), bufferSize);
    scratch = 0;
    scratch_bits = 0;
    word_index = 0;
}

BitPacker::BitPacker(char *data, int dataSize) {
    buffer = (uint32_t *) data;
    word_index = dataSize;
}

BitPacker::BitPacker(Packet *packet) {
}

char *BitPacker::pack(Packet *packet) {
}

Packet *BitPacker::unpack() {
}

bool BitPacker::setData(char *data, int dataSize) {
    return 0;
}

int BitPacker::getPackedDataSize() {
    return 0;
}
