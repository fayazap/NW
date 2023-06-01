// header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<ctype.h>

#define MAX 1024

int main()
{
    int i, sockfd;
    struct sockaddr_in server;
    char buf[MAX];
    char tmp[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error:");
        exit(0);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    server.sin_addr.s_addr = inet_addr("192.168.10.55");

    i = connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    if (i < 0)
    {
        perror("Error:");
        close(sockfd);
        exit(0);
    }

    memset(buf, 0, MAX);
    read(sockfd, buf, MAX);
    printf("\n%s", buf);
    sleep(1);
    memset(buf, 0, MAX);
    strcpy(buf, "HELO localhost.localdomain\r\n");
    write(sockfd, buf, strlen(buf));
    memset(buf, 0, MAX);
    read(sockfd, buf, MAX);
    printf("\n%s\nSender mail:", buf);
    scanf("%s", tmp);
    strcat(tmp, "\r\n");
    sleep(1);
    memset(buf, 0, MAX);
    strcpy(buf, "MAIL FROM:");
    strcat(buf, tmp);
    write(sockfd, buf, strlen(buf));
    memset(buf, 0, MAX);
    read(sockfd, buf, MAX);
    printf("\n%s\nReceipient mail:", buf);
    scanf("%s", tmp);
    strcat(tmp, "\r\n");
    sleep(1);
    memset(buf, 0, MAX);
    strcpy(buf, "RCPT TO:");
    strcat(buf, tmp);
    write(sockfd, buf, strlen(buf));
    memset(buf, 0, MAX);
    read(sockfd, buf, MAX);
    printf("\n%s", buf);
    memset(buf, 0, MAX);
    strcpy(buf, "DATA\r\n");
    write(sockfd, buf, strlen(buf));
    memset(buf, 0, MAX);
    read(sockfd, buf, MAX);
    printf("\n%s", buf);
    memset(buf, 0, MAX);
    while (1)
    {
        memset(tmp, 0, 1024);
        gets(tmp);
        if (!strcmp(tmp, "."))
            break;
        strcat(buf, tmp);
    }
    strcat(buf, "\r\n.\r\n");
    write(sockfd, buf, strlen(buf));
    memset(buf, 0, MAX);
    read(sockfd, buf, MAX);
    printf("\n%s", buf);
    sleep(1);
    close(sockfd);
    return 0;
}
