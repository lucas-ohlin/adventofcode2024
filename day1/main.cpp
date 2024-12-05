#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort (int *a, int lenght) {
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

int main() {
    int a[1000];
    int b[1000];
    int count = 0;

    FILE *file = fopen("C:\\Users\\Lucas\\Desktop\\adventofcode2024\\day1\\input.txt", "r");
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

    printf("Sum: %d\n", sum);

    while (1) {};
    return 0;
}
