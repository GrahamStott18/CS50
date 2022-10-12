// Constants

// Tells compiler to load specified library(s) into program
#include <cs50.h>
#include <stdio.h>

// Initiates code in program
int main(void)
{
    // Number of points that I lost
    const int MINE = 2;

    // Prompt user for points
    int points = get_int("How many points did you lose? ");

    // Compare points against mine
    if (points < MINE)
    {
        printf("You lost fewer points than me.\n");
    }
    else if (points > MINE)
    {
        printf("You lost more points than me.\n");
    }
    else
    {
        printf("You lost the same number of points as me.\n");
    }
}