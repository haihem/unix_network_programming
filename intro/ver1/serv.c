#include "../../lib/time_server.h"

int main() {

    struct sockaddr_in socket_st = {0};
    socket_st.sin_family = AF_INET;
    socket_st.sin_port = htons(PORT);
    socket_st.sin_addr.s_addr = htonl(INADDR_ANY);

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listen_fd, (struct sockaddr *) &socket_st, sizeof(socket_st));


    return 0;
}