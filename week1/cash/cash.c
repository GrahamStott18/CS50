// Tells compiler which library to load into program.
#include <cs50.h>
// Tells compiler which library to load into program.
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

// This initiates code to run.
int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// This initiates code to run.
int get_cents(void)
{
    // Will prompt the user to enter a number for the amount of cents owed.
    // Code set up as a loop to continue to ask user for number until a number greater than zero entered.
    int cents;
    // This sets up loop in the code.
    do
    {
        // This is part of code that prompts user to enter number.
        cents = get_int("Cents Owed: ");
    }
    // This part of code tells loop to not accept number less than zero.
    while (cents < 0);
    // Returns the value of cents the user entered.
    return cents;
}

int calculate_quarters(int cents)
{
    // Code compares value of cents to value of quarters to determine how many quarters are needed.
    int quarters = 0;
    // Sets up loop to remove values of 25 from cents total, will continue until remaining value of cents is less than 25.
    while (cents >= 25)
    {
        // Will remove another quater value (25) from cents total.
        cents = cents - 25;
        // Adds a quarter to the number of quarters taken from cents value. Increment operator that increases the integer value by one.
        quarters++;
    }
    // Returns the number of quarters that were taken from cents total.
    return quarters;
}

int calculate_dimes(int cents)
{
    // Code will compare remaining cents total to value of dimes to determine how many dimes are needed.
    int dimes = 0;
    // Sets up loop to remove values of 10 from cents total, will continue until remaining value of cents is less than 10.
    while (cents >= 10)
    {
        // Removes another dime value (10) from cents total.
        cents = cents - 10;
        // Adds a dime to the number of dimes taken from cents value. Increment operator that increases the integer value by one.
        dimes++;
    }
    // Returns the number of dimes that were taken from the cents total.
    return dimes;
}

int calculate_nickels(int cents)
{
    // Code will compare remaining cents total to value of nickels to determine how many nickels are needed.
    int nickels = 0;
    // Sets up loop to remove values of 5 from the cents total, will continue until remaining value of cents is less than 5.
    while (cents >= 5)
    {
        // Removes another nickel value (5) from cents total.
        cents = cents - 5;
        // Adds a nickel to the number of nickels taken from cents value. Increment operator that increases the integer value by one.
        nickels++;
    }
    // Returns the number of nickels that were taken from the cents total.
    return nickels;
}

int calculate_pennies(int cents)
{
    // Code will compare remaining cents total to value of pennies to determine how many pennies are needed.
    int pennies = 0;
    // Sets up loop to remove values of 1 from the cents total, will continue until remaining value of cents is equal to 0.
    while (cents >= 1)
    {
        // Removes another penny value (1) from the cents total.
        cents = cents - 1;
        // Adds a penny to the number of pennies taken from cents value. Increment operator that increases the integer value by one.
        pennies++;
    }
    // Returns the number of pennies that were taken from the cents total.
    return pennies;
}
