// Division with integers, demonstrating truncation

// Tells compiler to load specified library(s) into program.
#include <cs50.h>
#include <stdio.h>

// Initiates code in program.
int main(void)
{
    // Prompt user for x variable
    int x = get_int("x: ");

    // Prompt user for y variable
    int y = get_int("y: ");

    // Divide x by y
    float z = x / y;
    printf("%f\n", z);
}