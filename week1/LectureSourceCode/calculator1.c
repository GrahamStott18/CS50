// Addition with long

// Tells compiler to load specified library(s) into program.
#include <cs50.h>
#include <stdio.h>

// Initiates code in program.
int main(void)
{
    // Prompt user for x variable
    long x = get_long("x: ");

    // Prompt user for y variable
    long y = get_long("y: ");

    // Perform addition
    printf("%ld\n", x + y);
}