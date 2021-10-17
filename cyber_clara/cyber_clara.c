#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Store name and where the middle of the name is
// Delimiter is used to avoid erroers such as "bob aba" and "bo baba" will both be stored as "bobaba" thus adding a delimter to distguish them
struct name
{
    char name[42]; // 42 because, 20 for first name, 20 for last, 1 for delimiter and 1 for null terminator
    unsigned char middle; // place of the delimiter
};

// Compare function, compares the name value of the name struct. Used to sort names alphabetically
int compare(const void* val1, const void* val2)
{
    const struct name* pVal1 = (const struct name*) val1;
    const struct name* pVal2 = (const struct name*) val2;
    return strcmp(pVal1->name, pVal2->name);
}

int main()
{
    // Get amount of names
    unsigned long int size;
    scanf("%lu", &size);

    // Allocate places for names (struct)
    struct name* names = malloc(size * sizeof(struct name));

    // Scan the first names and store where they end in the name
    for (unsigned long int i = 0; i < size; i++)
    {
        scanf("%s", names[i].name);
        names[i].middle = strlen(names[i].name);
    }

    // Scan last name and store them starting from the after the middle of name
    for (unsigned long int i = 0; i < size; i++)
    {
        names[i].name[names[i].middle] = '_'; // Set delimiter
        scanf("%s", names[i].name + names[i].middle + 1); // Store after the middle
    }

    qsort(names, size, sizeof(struct name), compare);
    
    unsigned long int newSize = size;

    // Loop through names once comparing current with next value. If current is equal to next, decrement newSize (we have a duplicate!)
    for (size_t i = 0; i < size - 1; i++)
    {
        if (strcmp(names[i].name, names[i+1].name) == 0)
            newSize--;
    }

    // Print the new size after filtering out the duplicates
    printf("%lu", newSize);


    free(names);

    return 0;
}
