#ifndef UTILS_H
#define UTILS_H

/**
 * Generates a list of sensor names.
 * Example of pointer-to-pointer usage.
 * @param count Pointer to an integer where the number of sensors is stored.
 * @return Dynamically allocated array of strings. Caller must free.
 */
    char **generate_sensor_list(int *count);

/**
 * Returns the current local time as a formatted string.
 * @return Pointer to static string with format "YYYY-MM-DD HH:MM:SS".
 */
    const char *get_current_time(void);

/**
 * Returns the current local time as a formatted string.
 * @return Pointer to static string with format "YYYY-MM-DD HH:MM:SS".
 */
    char *get_current_time_str(void);

/**
 * Simulates a temperature reading.
 * @return Pointer to static string representing temperature (e.g., "23.56").
 */
    char *simulate_temperature(void);


#endif