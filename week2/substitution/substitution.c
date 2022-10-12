#include <cs50.h>
#include <stdio.h>
// Need string.h library to use: strlen
#include <string.h>
// Need ctype.h library to use: isdigit
#include <ctype.h>
// Need stdlib.h library to use: atoi(string s)
// atoi converts a string to an int
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Checks if argc is equal to 2. If not equal to 2, will return error message and quit program.
    // != means: Does NOT equal.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Checks if inputted characters is 26.
    if (strlen(argv[1]) != 26)
    {
        // Returns error message if inputted characters does not equal 26.
        printf("Key must contain 26 characters\n");
        return 1;
    }
    // string variable created.
    string enteredString = argv[1];
    // Character key created.
    char key[26];

    // Bool created.
    bool usedAlready[26];
    for (int i = 0; i < 26; i++)
    {
        usedAlready[i] = false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(enteredString[i]))
        {
            if (isupper(enteredString[i]))
            {
                if (usedAlready[enteredString[i] - 'A'] == true)
                {
                    printf("Key must not contain duplicate letters: %c\n", enteredString[i]);
                    return 1;
                }
                else
                {
                    usedAlready[enteredString[i] - 'A'] = true;
                    key[i] = enteredString[i] - 'A';
                }
            }
            else
            {
                if (usedAlready[enteredString[i] - 'a'] == true)
                {
                    printf(" Key must not contain duplicate letters: %c\n", enteredString[i]);
                    return 1;
                }
                else
                {
                    usedAlready[enteredString[i] - 'a'] = true;
                    key[i] = enteredString[i] - 'a';
                }
            }
        }
        else
        {
            printf("Please use only letters\n");
            return 1;
        }
    }


    string plainText = get_string("plaintext: ");

    string cipherText = plainText;

    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                cipherText[i] = (key[plainText[i] - 'A'] + 'A');
            }
            else
            {
                cipherText[i] = (key[plainText[i] - 'a'] + 'a');
            }
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
    // Prints ciphertext message.
    printf("ciphertext: %s\n", cipherText);
    return 0;
}