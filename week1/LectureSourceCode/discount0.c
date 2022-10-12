// No return value

// Tells compiler to load specified library(s) into program
#include <cs50.h>
#include <stdio.h>

// Initiates code in program
int main(void)
{
    float regular = get_float("Regular Price: ");
    float sale = regular * .85;
    printf("Sale Price: %.2f\n", sale);
}