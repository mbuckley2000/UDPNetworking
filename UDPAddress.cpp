//
// Created by Matt on 10/09/2016.
//

#include "UDPAddress.h"

UDPAddress::UDPAddress(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port) : a(a),
                                                                                                                  b(b),
                                                                                                                  c(c),
                                                                                                                  d(d),
                                                                                                                  port(port) {}

sockaddr_in* UDPAddress::setSockaddr() {
    unsigned int address = ( a << 24 ) |
                           ( b << 16 ) |
                           ( c << 8  ) |
                           d;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl( address );
    addr.sin_port = htons( port );
    return &addr;
}

unsigned short UDPAddress::getPort() {
    return port;
}

unsigned char UDPAddress::getA() {
    return a;
}

unsigned char UDPAddress::getB() {
    return b;
}

unsigned char UDPAddress::getC() {
    return c;
}

unsigned char UDPAddress::getD() {
    return d;
}
