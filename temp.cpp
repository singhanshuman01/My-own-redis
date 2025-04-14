#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>


int fd = socket(AF_INET,SOCK_STREAM,0);
int val = 1;
int setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

struct sockaddr_in addr = {};

addr.sin_family = AF_INET;
addr.sin_port = htons(5000);
addr.sin_addr.s_addr = htonl(0);

int rv = bind(fd, (const struct sockaddr *)&addr, sizeof(addr));

if(rv) { die("bind()"); }