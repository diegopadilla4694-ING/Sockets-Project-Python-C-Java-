#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(){
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    std::cout << "C++ server listening on port 8080..." << std :: endl;

    int new_socket = accept(server_fd, nullptr, nullptr);
    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);
    std::cout << "Message received: " << buffer << std::endl;

    close(new_socket);
    close(server_fd);
    return 0;
}
