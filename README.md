# Azeez Daoud C task (7)

## Goals
- [x] Optimize Cyber Clara (Somehow?)

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
2. Read the input, number by number
4. Sort the array of integers in descending order
5. Sum the first half of the array

### Cyber Clara (Differs from Rust Version)
Since C is C, another approach was used by implementing a HashSet (kinda) to make the duplicate checking in worse case O(n) (Linear upon collision)
1. Read all names
2. Hash them using `(previousHash + charAsciiValue) * k`
3. Insert in the HashSet (if key already exists then don't). Each successful insertion increments a counter
4. Return counter

Also, reading strings is the heaviest thing in the program. `gets` is used to faster than scanf. This gives a 0.01 difference. Making Kattis count it at 0.02s (Fastest C solution at the time this is written).

### Game Rank
This is really just following the rules given by Kattis but in general it's
1. Get the next character in the stream while it's not end of file `EOF`
2. If `W` apply the correct victory rules
3. Else if `L` apply the defeat rules

Some features that were added was an `enum` type that holds the ranges of the ranks and each range holds the amount of required stars to rankup for that range.
A function was made in order to calculate and update the range the player currently is in to make the correct calculation.