#include "unp.h"

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr) {
	int	n;
	if ((n = accept(fd, sa, salenptr)) < 0) err_sys("accept error");
	return(n);
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen) {
	if (bind(fd, sa, salen) < 0) err_sys("bind error");
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen) {
	if (connect(fd, sa, salen) < 0) err_sys("connect error");
}

void Close(int fd) {
	if (close(fd) == -1) err_sys("close error");
}

void Listen(int fd, int backlog) {
	if (listen(fd, backlog) < 0) err_sys("listen error");
}

int Socket(int family, int type, int protocol) {
	int	n;
	if ((n = socket(family, type, protocol)) < 0) err_sys("socket error");
	return(n);
}

void Write(int fd, void *ptr, ssize_t nbytes) {
	if (write(fd, ptr, nbytes) != nbytes) err_sys("write error");
}
