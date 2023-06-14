#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    int server, client;
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addrSize;
    char buffer[1024];

    server = socket(AF_INET, SOCK_STREAM, 0);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6565);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (server < 0)
    {
        printf("Error occured..\n");
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
        printf("Error occured..\n");
    }
    
    while (1)
    {
        client = accept(server, (struct sockaddr *)&store, &addrSize);
        recv(client, buffer, 1024, 0);
        printf("From Receiver: %s\n", buffer);
        printf("Enter the data to be send to client: \n");
        scanf("%s", buffer);
        send(client, buffer, sizeof(buffer), 0);
    }
}