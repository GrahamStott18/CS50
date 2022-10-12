// Tells compiler to load specified library into program.
#include <cs50.h>
// Tells compiler to load specified library into program.
#include <stdio.h>
// Tells compiler to load specified library into program.
#include <math.h>

// Prototype functions.
bool LuhnCheck(long CardNumber);
int GetCardLenght(long CardNumber);
void GetCardProvider(long CardNumber);


// This initiates code.
int main(void)
{
    // Prompts user to input card number.
    long CardNumber = get_long_long("Card Number to Validate: ");
    // Checks if card number is valid to Luhn's Algorithm, if not valid, prints INVALID.
    if (LuhnCheck(CardNumber) == true)
    {
        // Check if card is valid for a provider.
        GetCardProvider(CardNumber);

    }
    else
    {
        // Prints INVALID if number is not valid to Luhn's Algorithm.
        printf("INVALID\n");
    }
}

// Application of Luhn's Algorithm.
bool LuhnCheck(long CardNumber)
{
    // Sum that validates or not, the card.
    int CheckSum = 0;
    // Copy of card number.
    long tmp = CardNumber;

    // Iterates over each digit of the card number, checking for odds and evens.
    for (int pos = 0; tmp > 0; pos++)
    {
        if (pos % 2 == 0)
        {
            // Adds the last digit of the card to the sum.
            CheckSum += tmp % 10;
            // Excludes the last digit of the card
            tmp /= 10;
        }
        else
        {
            // For odd numbers it's necessary to *2
            int odd = (tmp % 10) * 2;
            // Makes sure we add each digit of the product and not the whole number.
            CheckSum += (odd / 10 + odd % 10);
            // Excludes the last digit of the card.
            tmp /= 10;
        }
    }
    // Returns true or false for the card validation. (If the sum's last digit is equal to zero).
    return (CheckSum % 10) == 0;
}

int GetCardLenght(long CardNumber)
{
    // Counts how many digits the card number has.
    int len = log10(CardNumber);
    return len + 1;
}

void GetCardProvider(long CardNumber)
{
    // Saves the card number lenght for use.
    int len = GetCardLenght(CardNumber);
    // It's going to store the first 2 digits of the card number.
    int prov;

    // Code Block for 16 digits lenght.
    if (len == 16)
    {
        // Uses scientific notation to reduce card number to 2 digits.
        prov = (CardNumber / 1e14);
        // Then checks said digits and prints it's provider.
        if (prov >= 51 && prov <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (prov >= 40 && prov <= 49)
        {
            printf("VISA\n");
        }
        // For check error.
        else
        {
            printf("INVALID\n");
        }
    }

    // Code block for 13 digits lenght.
    if (len == 13)
    {
        prov = (CardNumber / 1e12);
        if (prov == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // Code block for 15 digits lenght.
    if (len == 15)
    {
        prov = (CardNumber / 1e13);
        if (prov == 34 || prov == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Deals with any other lenght not specified by blocks above.
    else if (len <= 12 || len >= 17 || len == 14)
    {
        printf("INVALID\n");
    }
}