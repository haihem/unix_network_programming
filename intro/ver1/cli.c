#include "../../lib/time_server.h"

int main() {
    
    struct sockaddr_in socket_st = {0};
    socket_st.sin_family = AF_INET;
    socket_st.sin_port = htons(PORT);
    inet_pton(AF_INET, LOCALHOST, &socket_st.sin_addr);
    
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    connect(socket_fd, (struct sockaddr *) &socket_st, sizeof(socket_st));

    char buffer[MAXLINE];
    while (read(socket_fd, buffer, MAXLINE)) printf("%s", buffer);
    printf("\n");

    return 0;
}