#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main()
{
    struct sockaddr_in sa;
    struct sockaddr_in cli;
    int sockfd, conntfd;
    socklen_t len;
    int ch = 0;
    char str[100];
    time_t tick;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("error in socket\n");
        exit(0);
    }
    else
        printf("Socket opened\n");

    memset(&sa, 0, sizeof(sa));
    sa.sin_port = htons(5600);
    sa.sin_addr.s_addr = htonl(0);

    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0)
    {
        printf("Error in binding\n");
    }
    else
        printf("Binded Successfully\n");

    listen(sockfd, 50);

    for (;;)
    {
        len = sizeof(ch);
        conntfd = accept(sockfd, (struct sockaddr *)&cli, &len);
        printf("Accepted");

        tick = time(NULL);
        snprintf(str, sizeof(str), "%s", ctime(&tick));
        printf("%s", str);

        write(conntfd, str, strlen(str));
    }
    
    return 0;
}