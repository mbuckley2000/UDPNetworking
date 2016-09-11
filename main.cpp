#include <iostream>
#include "UDPSocket.h"

int main() {
    std::cout << "Opening socket on port 40005" << std::endl;
    UDPSocket sock(UDPAddress(0, 0, 0, 0, 0));
    sock.initialiseSockets();
    sock.open(40005);

    UDPAddress serverAddr = UDPAddress(192, 168, 0, 5, 25565);

    while (true) {
        //sock.send(serverAddr, "Hi", sizeof(char) * 3);
        if (sock.receive() == 1) {
            std::cout << "Received:" << std::endl<< sock.getReceivedData() << std::endl << "FROM: " << sock.getLastSender()->getA() << "." << sock.getLastSender()->getB() << "." << sock.getLastSender()->getC() << "." << sock.getLastSender()->getD() << ":" << sock.getLastSender()->getPort() << std::endl << std::endl;
        }
    }

    sock.close();
    sock.shutDownSockets();
    return 0;
}