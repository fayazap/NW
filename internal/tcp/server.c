#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
    int server, client;
    char buffer[1024];
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addrSize;

    // initial conf
    server = socket(AF_INET, SOCK_STREAM, 0);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6265);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // binding
    bind(server, (struct sockaddr *)&servAddr, sizeof(servAddr));

    // listen
    if (listen(server, 5) == 0)
    {
        printf("Listening..\n");
    }
    else
    {
        printf("Error..\n");
    }
    client = accept(server, (struct sockaddr *)&store, &addrSize);
    recv(client, buffer, 1024, 0);
    printf("Data received: %s\n", buffer);
    strcpy(buffer, "Hello this is server..");
    printf("Sending data to client..\n");
    send(client, buffer, sizeof(buffer), 0);
    close(server);
    close(client);
}