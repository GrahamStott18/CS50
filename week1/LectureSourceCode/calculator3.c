// Floating-point imprecision

// Tells compiler to load specified library(s) into program.
#include <cs50.h>
#include <stdio.h>

// Initiates code in program.
int main(void)
{
    // Prompt user for x variable
    float x = get_float("x: ");

    // Prompt user for y variable
    float y = get_float("y: ");

    // Divide x by y
    float z = x / y;
    printf("%.50f\n", z);
}