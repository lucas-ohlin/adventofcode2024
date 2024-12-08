#include <stdio.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

char grid[MAX_ROWS][MAX_COLS];
int rows, cols;
int directions[8][2] = {                // Vectors for possible directions
    {0, 1},  {1, 0},  {1, 1},  {1, -1}, // Right, Down, Down-Right, Down-Left
    {0, -1}, {-1, 0}, {-1, -1}, {-1, 1} // Left, Up, Up-Left, Up-Right
};

// Check if XMAS exists starting from (x, y) in a specific direction
int find_xmas(int x, int y, int dir, char str[]) {  
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int nx = x + i * directions[dir][0]; 
        int ny = y + i * directions[dir][1];
        if ( nx < 0 || ny < 0               // Check that we aren't going out of the grid by either the left or the top side
            || nx >= rows || ny >= cols     // Check that we aren't going out of the grid by either the right or the bottom side
            || grid[nx][ny] != str[i]) {    // Check if the character at the current position matches one of XMAS
            return 0;            
        }
    }
    return 1;                             
}

// Check if X-MAS pattern exists with with A as the center
int find_mas(int x, int y) {
    if (grid[x][y] != 'A') return 0;

    // Check if the diagonals are within the grid bounds
    if (x - 1 < 0 || y - 1 < 0 || x + 1 >= rows || y + 1 >= cols) {
        return 0;  
    }

    char topLeft[] = {grid[x - 1][y - 1], grid[x][y], grid[x + 1][y + 1], '\0'};  // Top left to bottom right
    char topRight[] = {grid[x - 1][y + 1], grid[x][y], grid[x + 1][y - 1], '\0'}; // Top right to bottom left

    if ((strcmp(topLeft, "MAS") == 0 || strcmp(topLeft, "SAM") == 0) &&           // Check if both diagonals form valid X-MAS patterns
        (strcmp(topRight, "MAS") == 0 || strcmp(topRight, "SAM") == 0)) {         
        return 1; 
    }

    return 0;
}

int main() {
    FILE *file = fopen("../input.txt", "r");
    char xmas[5] = "XMAS";
    char mas[4] = "MAS";

    rows = 0;
    while (fgets(grid[rows], sizeof(grid[0]), file)) {
        cols = strlen(grid[rows]);
        if (grid[rows][cols - 1] == '\n') {
            grid[rows][cols - 1] = '\0'; // Null-terminated the string
            cols--;
        }
        rows++;
    }
    fclose(file);

    // Part 1
    int count_xmas = 0;
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            if (grid[x][y] == 'X') {  
                for (int dir = 0; dir < 8; dir++) {
                    if (find_xmas(x, y, dir, xmas)) {
                        count_xmas++;
                    }
                }
            }
        }
    }

    // Part 2
    int count_mas = 0;
    for (int x = 1; x < rows - 1; x++) {        
        for (int y = 1; y < cols - 1; y++) {   
            count_mas += find_mas(x, y);
        }
    }

    printf("Part 1: %d\n", count_xmas);
    printf("Part 2: %d\n", count_mas);
    while(1) {}
    return 0;
}
