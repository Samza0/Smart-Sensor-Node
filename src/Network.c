#include "Network.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int connect_to_server(const char *hostname, int port){
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        herror("gethostbyname");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

/*Build an HTTP POST request including device, time, and temperature.*/
char *build_post_request(const char *host, const char *device_id, const char *temperature){
    static char buffer[1024];
    char *current_time = get_current_time_str();

    //JSON body
    char json_body[256];
    snprintf(json_body, sizeof(json_body), "{ \"device\": \"%s\", \"time\": \"%s\", \"temperature\": \"%s°C\" }",
            device_id, current_time, temperature);
    //Full HTTP post request
    snprintf(buffer, sizeof(buffer),
         "POST /post HTTP/1.1\r\n"   // <-- changed from "/" to "/post"
         "Host: %s\r\n"
         "Content-Type: application/json\r\n"
         "Content-Length: %zu\r\n"
         "Connection: close\r\n"
         "\r\n"
         "%s",
         host, strlen(json_body), json_body);

    return buffer;
}

void send_post(int sockfd, const char *request, void (*response_handler)(char *)) {
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return;
    }

    char buffer[2048];
    ssize_t bytes;

    // Receive until the server closes the connection
    while ((bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes] = '\0';         // Null-terminate
        response_handler(buffer);     // Print each chunk immediately
    }

    if (bytes < 0) {
        perror("recv");
    }
}

void print_response(char *response){
    printf("Server response:\n%s\n", response);
}
    