#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h> // Include bzero function

int main()
{
    struct sockaddr_in sa, cli;
    int n, sockfd;
    int len;
    char buff[100];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("\nError in Socket");
        exit(0);
    }
    else
    {
        printf("\nSocket is Opened\n");
    }
    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(5600);
    if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0)
    {
        printf("\nError in connection failed");
        exit(0);
    }
    else
    {
        printf("\nconnected successfully");
    }
    if ((n = fread(buff, sizeof(char), sizeof(buff), stdin)) < 0)
    {
        printf("\nError in Reading");
        exit(0);
    }
    else
    {
        printf("\nMessage Read %s", buff);
    }
    return 0;
}