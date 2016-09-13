#include <iostream>
#include "UDPSocket.h"
#include "SerialiserTests.h"

int main() {
    std::cout << "Opening server on port 40005" << std::endl;
    UDPSocket sock = UDPSocket();
    sock.initialiseSockets();
    sock.open(40005);

    UDPAddress serverAddr = UDPAddress(192, 168, 0, 5, 25565);

    SerialiserTests tests = SerialiserTests();
    tests.runtests();

    /*
    Server server = Server(&sock);

    while (server.isRunning()) {
        server.update();
    }

     */
    sock.close();
    sock.shutDownSockets();
    return 0;
}