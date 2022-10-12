// Calculates a remainder

// Tells compiler to load specified library(s) into program
#include <cs50.h>
#include <stdio.h>

// Initiates code in program
int main(void)
{
    // Prompt user for integer
    int n = get_int("n: ");

    // Check parity of integer
    if (n % 2 == 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }
}