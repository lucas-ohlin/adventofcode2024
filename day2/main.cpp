#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Part 1
bool safe(int *levels, int size) {
    if (size < 2) return false;

    bool increase = levels[1] > levels[0];

    for (int i = 1; i < size; i++) {
        int diff = levels[i] - levels[i - 1]; // Calculate the difference between adjacent levels
        if (abs(diff) < 1 || abs(diff) > 3) { // Check if difference is within range [1, 3]
            return false; 
        }

        if ((increase && diff < 0) || (!increase && diff > 0)) {
            return false; 
        }
    }

    return true;
}

// Part 2
bool safe_dampener(int *levels, int size) {
    if (safe(levels, size)) {
        return true; 
    }

    for (int i = 0; i < size; i++) {   
        int temp[100];
        int temp_size = 0;

        for (int j = 0; j < size; j++) { 
            if (j != i) {
                temp[temp_size++] = levels[j];
            }
        }

        if (safe(temp, temp_size)) {
            return true;
        }
    }

    return false;  
}

int main() {
    FILE *file = fopen("../input.txt", "r");
    char line[1024];
    int safe_count = 0;
    int safe_count_dampener = 0;

    while (fgets(line, sizeof(line), file)) {
        int levels[100];
        int size = 0;

        char *token = strtok(line, " ");
        while (token) {
            levels[size++] = atoi(token);
            token = strtok(NULL, " ");
        }
        
        if (safe(levels, size)) {        
            safe_count++;
        }

        if (safe_dampener(levels, size)) {
            safe_count_dampener++;
        }
    }

    fclose(file);
    printf("Part 1: %d\n", safe_count);
    printf("part 2: %d\n", safe_count_dampener);

    while (1) {};
    return 0;
}
