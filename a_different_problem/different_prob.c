#include "stdio.h"
#include "stdlib.h"

int main()
{
    // Kattis said 0-10^15. long long goes up to ~9 x 10^18. Perfect for our needs! (unsigned long is too small aswell and would cause negative value problems)
    long long int x, y;

    while (scanf("%lli%lli", &x, &y) != EOF)
    {
        // llabs calculates the absolute value of a long long, from stdlib.h
        long long int val = llabs(x - y);
        printf("%lli\n", val);
    }
    return 0;
}