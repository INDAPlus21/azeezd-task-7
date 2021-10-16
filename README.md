# Azeez Daoud C task (7)

## Goals
- [ ] Optimize Cyber Clara (Somehow?)

## Techniques used
Here is the thought process behind the solutions

### A different problem (Same as the Rust version)
Kattis required 0-10^15 thus `long long int` is used to cover all values.

Scan each pair of values and compute the absolute value of the difference using `llabs` from `stdlib.h`

### Avstånd till kant (Same as Rust version)
1. Get values
2. Since there are 4 edges, two horizontal and two vertical. Find the minium of the horizontals and the verticals. The among those two find the minimum. (Closest of all!)

### Summera tal (Differs from Rust Version)
Since C is C, another approach was taken.
1. Get the amount of numbers
2. Go through the single line of numbers
    1. If current character is not a whitespace, it must a part of a number. Store them.
    2. Continue gathering non-whitespaces until reaching one
    3. When reaching a whitespace. All stored characters are converted to an integral value and stored in an array.
4. Sort the array of integers in descending order
5. Sum the first half of the array

### Cyber Clara (Differes from Rust Version)
Again since C is C, another approach was taken.
1. Get the amount of names
2. Prepare an array to store names (it's a struct of names and a middle-of-name indexer, used to avoid collision complications)
3. Get the first names and store them in a string
4. Add a delimiter '_' then add the last names to their corresponding first names
5. Sort the list of names alphabetically
6. Go through the list of names. If current name and next name are equal then it is a duplicate, reduce the amount of names by 1.
