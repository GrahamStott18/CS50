// Determines the lenght of a string using a function

#include <cs50.h>
#include <stdio.h>

int string_lenght(string s);

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");
    int lenght = string_lenght(name);
    printf("%i\n", lenght);
}

int string_lenght(string s)
{
    // Count number of characters up until '\0' (aka NUL)
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}