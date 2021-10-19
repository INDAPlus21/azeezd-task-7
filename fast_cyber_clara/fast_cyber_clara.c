#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

// Couldn't be bothered writing it out a zillion times
#define ulint unsigned long int

// Used as a value to hash the string. Best if Prime number
#define HASH_VALUE 31

// Hashes a given first and last names by taking a pointer to where they are stored
ulint hashName(const char* firstName, const char* lastName);

// Insert to the hashSet. Will not add if key already exists. Increments amount by one if key sucessfully added.
void insert(const ulint* key);

// A HashMap-like structure but only allows unique values
ulint* hashSet;

// Amount of values in the hashSet
ulint amount = 0;

// The amount of names that will be inputted. Given in first line of the input
ulint SIZE = 0;

// Store the name
typedef struct
{
    char name[21]; // By Kattis, names are max 20 characters + 1 for null terminator
} name;


int main()
{
    // Get amount of names
    scanf("%lu", &SIZE);

    // Store inputted names int the name struct
    name* names = malloc(2 * SIZE * sizeof(name));

    // Initilise memory for hashSet and its default values
    hashSet = malloc(SIZE * sizeof(ulint));
    memset(hashSet, 0, SIZE * sizeof(ulint));

    for (ulint i = 0; i < 2 * SIZE; i++)
    {
        scanf("%s", names[i].name);
    }

    ulint currentHash = 0;
    // Loop through names
    for (ulint i = 0; i < SIZE; i++)
    {   
        currentHash = hashName(names[i].name, names[i + SIZE].name);
        // Hash first and last name (constant offset = SIZE) and insert them in the hashSet
        insert(&currentHash);
    }

    printf("%lu", amount);
    
    free(names);
    free(hashSet);

    return 0;
}

ulint hashName(const char* firstName, const char* lastName)
{
    // The hash value that will be returned
    ulint hash = 0;

    const char* currentChar = firstName;

    // Iterate through first name until null terminator
    while (*currentChar != '\0')
    {
        hash = (hash + *currentChar) * HASH_VALUE;
        currentChar++;
    }

    // Delimiter
    hash = (hash + '.') * HASH_VALUE;

    // Switching to last name and then looping the same fashion as firstName
    currentChar = lastName;
    while (*currentChar != '\0')
    {
        hash = (hash + *currentChar) * HASH_VALUE;
        currentChar++;
    }
    
    return hash;
}

void insert(const ulint* key)
{
    // Modulo the key to get an index in the set
    ulint index = *key % SIZE;

    // Point to an adress within the set
    ulint* currentKey = &hashSet[index];

    // If key already exists, return
    if (*currentKey == *key) {return;}

    // Loop through until we find an empty spot to put the key
    while (*currentKey != 0)
    {
        // Duplicate key, return
        if (*currentKey == *key) {return;}

        // Move forward in the hashSet and wrap around.
        index = (index + 1) % SIZE;
        currentKey = &hashSet[index];
    }

    // Increase amount of names if above was sucessfull and set the current key to the given key
    amount++;
    *currentKey = *key;
}