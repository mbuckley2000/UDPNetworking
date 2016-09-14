#include <iostream>
#include "UDPSocket.h"
#include "Server.h"

int main() {
    std::cout << "Opening server on port 40005" << std::endl;
    UDPSocket sock = UDPSocket();
    sock.initialiseSockets();
    sock.open(40005);

    UDPAddress me = UDPAddress(127, 0, 0, 1, 40005);

    Server server = Server(&sock);

    Packet p = Packet();
    p.setType(p.handshake);


    while (server.isRunning()) {
        //server.sendPacket(&me, &p);
        server.update();
    }

    sock.close();
    sock.shutDownSockets();
    return 0;
}