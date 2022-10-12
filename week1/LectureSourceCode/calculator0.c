// Addition with int

// Tells compiler to load specified library into program.
#include <cs50.h>
// Tells compiler to load specified library into program.
#include <stdio.h>

int main(void)
{
    // Prompt user for x variable
    int x = get_int("x: ");

    //Prompt user for y variable
    int y = get_int("y: ");

    // Perform addition
    printf("%i\n", x + y);
}