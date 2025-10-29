#ifndef NETWORK_H
#define NETWORK_H

/**
 * Connects to a TCP server.
 * @param hostname The server hostname or IP.
 * @param port The TCP port number.
 * @return socket file descriptor on success, -1 on failure.
 */

    int connect_to_server(const char *hostname, int port);

/**
 * Builds a simple HTTP POST request string.
 * @param host The server host name.
 * @param device_id Unique device identifier.
 * @param temperature Temperature string (e.g., "23.5").
 * @return Pointer to static buffer containing the HTTP request.
 */

    char *build_post_request(const char *host, const char *device_id, const char *temperature);

/**
 * Sends an HTTP POST request over a connected socket.
 * @param sockfd The TCP socket file descriptor.
 * @param request The HTTP POST request string.
 * @param response_handler Function pointer to handle server response.
 */
    void send_post(int sockfd, const char *request, void (*response_handler)(char *));

/**
 * Default response handler that prints the server response.
 * @param response The response string received from the server.
 */
    void print_response(char *response);




#endif