#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

#define PORT 4444

int main() {
    int listenfd, connfd;
    struct sockaddr_in servAddr, cliAddr;
    socklen_t clilen;
    char buffer[1024];

    // Create server socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("[+] Server socket created successfully\n");

    // Initialize server address structure
    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind the socket
    if (bind(listenfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1) {
        perror("bind");
        close(listenfd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Bind to PORT %d successful\n", PORT);

    // Listen for incoming connections
    if (listen(listenfd, 5) == -1) {
        perror("listen");
        close(listenfd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Listening...\n");

    // Accept a client connection
    clilen = sizeof(cliAddr);
    connfd = accept(listenfd, (struct sockaddr *) &cliAddr, &clilen);
    if (connfd == -1) {
        perror("accept");
        close(listenfd);
        exit(EXIT_FAILURE);
    }

    // Send data to client
    strcpy(buffer, "Hello World!");
    if (send(connfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(connfd);
        close(listenfd);
        exit(EXIT_FAILURE);
    }
    printf("[+] Data sent to client: %s\n", buffer);

    // Close the connection
    close(connfd);
    printf("[+] Closing the connection\n");

    // Close the listening socket
    close(listenfd);
    
    return 0;
}
