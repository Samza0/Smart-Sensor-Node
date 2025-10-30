#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Returns a dynamically allocated array of sensor names (pointer-to-pointer example).
 * Caller must free each string and the array itself.
 */
    char **generate_sensor_list(int *count){
        *count = 2; 
        char **list = malloc((*count) * sizeof(char *));
        if(list == NULL) return NULL;

        list[0] = strdup("sensor1");
        list[1] = strdup("sensor2");

        return list;
  }

/**
 * Returns the current local time as a formatted string: "YYYY-MM-DD HH:MM:SS".
 */
    char *get_current_time_str(void){
        static char buffer[64];
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        return buffer;
    }
/**
 * Simulates a temperature reading as a string.
 */
    char *simulate_temperature(void){
        static char temp[8];
        // generate a float between 20.0°C and 40.0°C
        float value = 20.0f + (rand() % 1000) / 50.0f;
        snprintf(temp, sizeof(temp), "%.2f", value);
        return temp;
    }
