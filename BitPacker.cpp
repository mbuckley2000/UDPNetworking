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

void BitPacker::write(void *data, unsigned int size) {
    if (scratch)
}
