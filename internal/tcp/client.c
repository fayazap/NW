#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    int client;
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addrSize;
    char buffer[1024];

    client = socket(AF_INET, SOCK_STREAM, 0);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6565);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client, (struct sockaddr *)&servAddr, sizeof(servAddr));
    while (1)
    {
        printf("Enter the context to be send: \n");
        scanf("%s", buffer);
        send(client, buffer, sizeof(buffer), 0);
        recv(client, buffer, 1024, 0);
        printf("Data received from server: %s\n", buffer);
    }
}