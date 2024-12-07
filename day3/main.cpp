#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Part 1
long long extract_valid_mul(const char *input) { 
    long long sum = 0;
    const char *ptr = input;

    while (*ptr) {
        // strncmp (string compare) 
        // Compares up to num characters of the C string str1 to those of the C string str2. 
        // This function starts comparing the first character of each string.
        if (strncmp(ptr, "mul(", 4) == 0) {  
            ptr += 4;            

            // Parse the first number
            char buffer[16];
            int index = 0;
            while (*ptr >= '0' && *ptr <= '9' && index < 15) {
                buffer[index++] = *ptr++;
            }
            buffer[index] = '\0';
            int x = atoi(buffer);

            if (*ptr != ',') {
                continue;
            }
            ptr++;

            // Parse the second number
            index = 0;
            while (*ptr >= '0' && *ptr <= '9' && index < 15) {
                buffer[index++] = *ptr++;
            }
            buffer[index] = '\0';
            int y = atoi(buffer);
 
            if (*ptr != ')') {
                continue;
            }
            ptr++;

            sum += (long long)x * y;
        } else {
            ptr++;
        }
    }

    return sum;
}

// Part 2
long long extract_valid_mul_conditions(const char *input) {
    long long sum = 0;
    const char *ptr = input;
    bool enabled = true;  

    while (*ptr) {
        if (strncmp(ptr, "don't()", 7) == 0) {  // Check for don't()
            enabled = false;
            ptr += 7;  
        }
        else if (strncmp(ptr, "do()", 4) == 0) { // Check for do()
            enabled = true;
            ptr += 4;  
        }

        else if (strncmp(ptr, "mul(", 4) == 0) {
            ptr += 4; 

            // Parse the first number
            char buffer[16];
            int index = 0;
            while (*ptr >= '0' && *ptr <= '9' && index < 15) {
                buffer[index++] = *ptr++;
            }
            buffer[index] = '\0';
            int x = atoi(buffer);
            
            if (*ptr != ',') {
                continue;
            }
            ptr++;

            // Parse the second number
            index = 0;
            while (*ptr >= '0' && *ptr <= '9' && index < 15) {
                buffer[index++] = *ptr++;
            }
            buffer[index] = '\0';
            int y = atoi(buffer);

            if (*ptr != ')') {
                continue;
            }
            ptr++;

            if (enabled) {
                sum += (long long)x * y;
            }
        } else {
            ptr++; 
        }
    }

    return sum;
}

int main() {
    FILE *file = fopen("../input.txt", "r");
    char line[100000];
    size_t len = fread(line, 1, sizeof(line) - 1, file); // size_t can store the maximum size of a theoretically possible object of any type (including array).
    line[len] = '\0';                                    // Null-terminate the string
    
    long long sum = extract_valid_mul(line);             // Calculate the sum of valid multiplications
    long long sum_conditions = extract_valid_mul_conditions(line);

    fclose(file);
    printf("Part 1: %lld\n", sum);
    printf("Part 2: %lld\n", sum_conditions);

    while (1) {};
    return 0;
}
