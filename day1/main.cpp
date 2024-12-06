#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Part 1
void sort(int *a, int lenght) {
    for (int i = 0; i < lenght; i++) {
        for (int y = i; y < lenght; y++) {
            if (a[i] > a[y]) {
                int temp = a[y];
                a[y] = a[i];
                a[i] = temp;
            }
        }  
    }
}

// Part 2
int count_target(int *array, int length, int target) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == target) {
            count++;
        }
    }

    return count;
}

int main() {
    int a[1000];
    int b[1000];
    int count = 0;

    FILE *file = fopen("../input.txt", "r");
    while (fscanf(file, "%d %d", &a[count], &b[count]) == 2) {
        count++;
    }

    fclose(file);
    sort(a, count);
    sort(b, count);

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += abs(a[i] - b[i]);
    }

    int score = 0;
    for (int i = 0; i < count; i++) {
        int temp = count_target(b, count, a[i]); // How many times a[i] appears in array b
        score += a[i] * temp;
    }

    printf("Part 1: %d\n", sum);
    printf("Part 2: %d\n", score);

    while (1) {};
    return 0;
}
