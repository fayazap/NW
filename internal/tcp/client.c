#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
    int client;
    char buffer[1024];
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addrSize;

    client = socket(AF_INET, SOCK_STREAM, 0);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(2255);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client, (struct sockaddr *)&servAddr, sizeof(servAddr));

    while (1)
    {
        printf("Enter the context to be send to server: \n");
        scanf("%s", buffer);
        send(client, buffer, sizeof(buffer), 0);
        recv(client, buffer, 1024, 0);
        printf("Content received from server: %s\n", buffer);
    }
}
