#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
    int client;
    char buffer[1024];
    struct sockaddr_in servAddr;
    struct sockaddr_storage store;
    socklen_t addrSize;

    // initial conf
    client = socket(AF_INET, SOCK_STREAM, 0);
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(6265);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // client part begins
    connect(client,(struct sockaddr *)&servAddr,sizeof(servAddr));
    printf("Sending data to server..\n");
    printf("Enter the data to be send to server: \n");
    scanf("%s",buffer);
    send(client,buffer,sizeof(buffer),0);
    recv(client,buffer,1024,0);
    printf("Data received from server: %s",buffer);
    close(client);


}