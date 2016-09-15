//
// Created by Matt on 10/09/2016.
//

#ifndef NETWORKING_TUTORIALS_ADDRESS_H
#define NETWORKING_TUTORIALS_ADDRESS_H

//Detect Platform
#define PLATFORM_WINDOWS 1
#define PLATFORM_MAC 2
#define PLATFORM_UNIX 3

#if defined(_WIN32)
#define PLATFORM PLATFORM_WINDOWS
#elif defined(__APPLE__)
#define PLATFORM PLATFORM_MAC
#else
    #define PLATFORM PLATFORM_UNIX
#endif

//Link WinSock for Windows platforms
#if PLATFORM == PLATFORM_WINDOWS
#pragma comment(lib, "wsock32.lib")
#endif

//Include platform-specific socket headers
#if PLATFORM == PLATFORM_WINDOWS
#include <winsock2.h>
#include <cstdio>

#else //Mac or UNIX
#include <sys/socket.h>
    #include <netinet/in.h>
    #include <fcntl.h>
#endif

class UDPAddress
{
public:
    UDPAddress(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port );

    UDPAddress(unsigned int address, unsigned short port);
    sockaddr_in* setSockaddr();
    unsigned short getPort();
    unsigned char getA();
    unsigned char getB();
    unsigned char getC();
    unsigned char getD();
    
private:
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned short port;
    sockaddr_in addr;
};

#endif //NETWORKING_TUTORIALS_ADDRESS_H
