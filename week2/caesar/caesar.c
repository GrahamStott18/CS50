#include <cs50.h>
#include <stdio.h>
// Need ctype.h library to use: isdigit
#include <ctype.h>
// Need string.h library to use: strlen
#include <string.h>
// Need stdlib.h library to use: atoi(string s)
// atoi converts a string to an int
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Checks if argc is equal to 2. If not equal to 2, will return error message and quit program.
    // != means: Does NOT equal.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Go through argv[1], one at a time, starting at 0.
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // Checks if argv[1] only includes digits. If not only digits found, will return error message and quit program.
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Converts our key from string to int.
    int k = atoi(argv[1]);

    // Prompts user to enter text.
    string plaintext = get_string("Plaintext: ");

    printf("Ciphertext: ");

    // Runs a loop on newly created variable named "j", loop keeps going as long as "j" is less than the lenght of the "plaintext", and goes one by one.
    for (int j = 0; j < strlen(plaintext); j++)
    {
        // Determins if text is UPPERCASE
        if (isupper(plaintext[j]))
        {
            // Takes the ASCII value of the UPPERCASE character, and subtracts 65, plus the value of k,
            // then MODS (%) 26 (which loops the value around 26 and tells you the remainder), then adds 65 to give the ASCII value.
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }
        // Determins if text is lowercase
        else if (islower(plaintext[j]))
        {
            // Takes the ASCII value of the lowercase character, and subtracts 97, plus the value of k,
            // then MODS (%) 26 (which loops the value around 26 and tells you the remainder), then adds 97 to give the ASCII value.
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }
        // Determines if character is not a letter.
        else
        {
            // Prints text as is.
            printf("%c", plaintext[j]);
        }
    }
    // Prints a new line at end of program.
    printf("\n");
}