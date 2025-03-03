#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>

int main()
{
    int clientsocket,port; 
    struct sockaddr_in serveraddr; 
    socklen_t len;
    struct hostent *server;
    char message[50];
    
    clientsocket=socket(AF_INET,SOCK_DGRAM,0);
    len=sizeof(serveraddr);
    serveraddr.sin_family=AF_INET;

    printf("Enter the port number ");
    scanf("%d",&port);
    serveraddr.sin_port=htons(port);
    fgets(message,2,stdin);
    printf("\nSending message for server connection\n");
    char buf[100];
    printf("enter");
    fgets(buf,100,stdin);
    sendto(clientsocket,buf,sizeof(buf),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr)); 
    printf("\nReceiving message from server.\n");

    recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
    printf("\nMessage received:\t%s\n",message);
    close(clientsocket);
}