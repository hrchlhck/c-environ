#include "Include/net.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 8080
#define SIZE 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    int opt = 1;
    
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("SOCKET FAILED.");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("SETSOCKOPT");
        exit(EXIT_FAILURE);
    }

    int inet = inet_addr("127.0.0.1");
    struct sockaddr_in addr = {AF_INET, INADDR_ANY, inet};
    int addrlen = sizeof(addr);

    if(bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("BIND FAILED");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 3) < 0) {
        perror("LISTEN");
        exit(EXIT_FAILURE);
    } 

    if((new_socket = accept(server_fd, (struct sockaddr*)&addr, (socklen_t*)&addrlen)) < 0) {
        perror("ACCEPT");
        exit(EXIT_FAILURE);
    }

    char buffer[SIZE] = {0};
    valread = read(new_socket, buffer, SIZE);
    printf("%s\n", buffer);

    return 0;
}
