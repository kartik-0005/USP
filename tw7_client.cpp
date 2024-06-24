#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 4444

int main() {
    int sockfd;
    struct sockaddr_in servAddr;
    char buffer[1024];

    // Create client socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("[+] Client socket created successfully\n");

    // Initialize server address structure
    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Connected to server\n");

    // Receive data from the server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Data received from server: %s\n", buffer);

    // Close the connection
    close(sockfd);
    printf("[+] Closing the connection\n");

    return 0;
}
