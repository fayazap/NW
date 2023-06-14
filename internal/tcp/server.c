#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
    int server, client;
    char buffer[1024];
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addrSize;

    server = socket(AF_INET, SOCK_STREAM, 0);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(2255);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (server < 0)
    {
        printf("Socket creation failed..\n");
    }
    else
    {
        printf("Socket created successfully..\n");
    }

    bind(server, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if (listen(server, 5) == 0)
    {
        printf("Listening..\n");
    }
    else
    {
        printf("Something went wrong...\n");
    }
    while (1)
    {
        client = accept(server, (struct sockaddr *)&store, &addrSize);
        recv(client, buffer, 1024, 0);
        printf("From client: %s\n", buffer);
        printf("Enter the content to be send to client: \n");
        scanf("%s", buffer);
        send(client, buffer, sizeof(buffer),0);
    }
}