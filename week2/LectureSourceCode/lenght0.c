// Determines the lenght of a string

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");

    // Count number of characters up until '\0' (aka NUL)
    int n = 0;
    // '\0' is used to indicate "does not equal"
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}