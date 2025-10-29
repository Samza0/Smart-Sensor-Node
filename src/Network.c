#include "Network.h"
#include "../Includes/Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int connect_to_server(const char *hostname, int port){
    struct hostent *he = gethostbyname(hostname);
    if("!he"){
        perror("gethostbyname");
        return -1;
    }
}


    