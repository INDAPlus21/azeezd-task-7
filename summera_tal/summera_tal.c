#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Trying a different approach than I did in the Rust version.
// This approach is: Get values > sort them (hopefully O(nlog(n))) and add the first n values according to the size given


// Compare function used in the stdlib qsort to sort the values
// In summary, it compares two values. If returned value is negative or 0, they shouldn't be swapped. Positive: Swap 'em!
int compare(const void* val1, const void* val2)
{
    long int* pVal1 = (long int*) val1;
    long int* pVal2 = (long int*) val2;
    return *pVal2 - *pVal1; // Val2 is first because we want descending order (so if next - current is positive it indicates that they are ascending and we should swap)
}

int main()
{
    // Amount of numbers to work with. Kattis mentioned 10^9, long int keeps us covered.
    long int size;
    scanf("%li", &size);

    // Storing the inputted numbers
    long int* numbers = malloc(size * sizeof(long int));
    
    // Read input and store it in numbers array
    for (size_t i = 0; i < size; i++)
    {
        scanf("%li", numbers + i);
    }
    
    // Sort the list
    qsort(numbers, size, sizeof(long int), compare);
    
    long int sum = 0; // Store the sum we will perform
    long int check = (size + 1) / 2; // As per Kattis, summing up to the first n/2 values (since division in integral values cuts the decimal part + 1 / 2 takes care of the odd/even problem)
    for (long int i = 0; i < check; i++)
    {
        sum += numbers[i];
    }
    
    printf("%li", sum);

    free(numbers);

    return 0;
}
