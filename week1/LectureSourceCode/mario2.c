// Prints a row of n question marks with a loop

// Tells compiler to load specified library(s) into program
#include <cs50.h>
#include <stdio.h>

// Initiates code in program
int main(void)
{
    int n;
    do
    {
        n = get_int("Width: ");
    }
    while (n < 1);
    for (int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}