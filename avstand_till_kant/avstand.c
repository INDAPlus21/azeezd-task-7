#include "stdio.h"

// Redefine min because stdlib.h has a definition only for C++?? Could be my Visual Studio C/C++ causing problems
#define min(x,y) (((x) > (y)) ? (y) : (x))

int main()
{
    // Initialise values
    int rows = 0,
        cols = 0,
        currentCoord = 0;

    // Get sizes
    scanf("%d %d", &rows, &cols);

    // Board is rows x cols, loop through that amount of times
    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= cols; j++)
        {
            // Distance to edge is the closest (minimum) distance between current position and one of the two edges
            currentCoord = min( // Minimum of the distances of two edges
                min(j, cols - j + 1), // Minimum to horizontal edge
                min(i, rows - i + 1) // Minimum to vertical edge
                );

            if (currentCoord >= 10) // As required by Kattis
                printf(".");
            else
                printf("%d", currentCoord);
                
        }
        printf("\n");
    }

    return 0;
}