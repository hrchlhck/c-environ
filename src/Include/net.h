#include <sys/socket.h>
#include <netinet/in.h>

typedef struct sockaddr_in2 {
    int family;
    int addr;
    uint32_t port;    
} address;