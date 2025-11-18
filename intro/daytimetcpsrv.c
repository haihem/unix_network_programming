#include <time.h>
#include <stdio.h>
#include "../lib/unp.h"

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);
    Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    printf("Bind done\n");
    Listen(listenfd, LISTENQ);
    printf("Listen done\n");
    while (1) {
        printf("Waiting Accept\n");
        connfd = Accept(listenfd, (struct sockaddr *) NULL, NULL);
        printf("Accept done\n");
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\er\en", ctime(&ticks));
        Write(connfd, buff, strlen(buff));
        printf("Write done\n");
        Close(connfd);
        printf("Close done\n");
    }

}
