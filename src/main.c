
#include "Network.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    // 1. Connect to server
    int sockfd = connect_to_server("httpbin.org", 80);
    if(sockfd < 0) return 1;

    // 2. Build HTTP POST request with simulated temperature
    char *temperature = simulate_temperature();
    char *request = build_post_request("httpbin.org", "UUID-1234", temperature);

    // 3. Send POST and print server response
    send_post(sockfd, request, print_response);

    // 4. Demonstrate pointer-to-pointer example
    int sensor_count;
    char **sensors = generate_sensor_list(&sensor_count);

    printf("\nSensors list: \n");
    for(int i = 0; i < sensor_count; i++){
        printf(" - %s\n", sensors[i]);
        free(sensors[i]);  // free each string
    }
    free(sensors);
    close(sockfd);
    return 0;
}