#include <stdio.h>
#include <stdlib.h>
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
    while (1)
    {
        connect(client, (struct sockaddr *)&servAddr, sizeof(servAddr));
        printf("Enter the content to send to server: \n");
        scanf("%s", buffer);
        send(client, buffer, sizeof(buffer), 0);
        recv(client, buffer, 1024, 0);
        printf("Content from server: %s\n", buffer);
    }
}
