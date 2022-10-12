#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    // Compares the scores of player1 and player2.
    if (score1 > score2)
    {
        // Adding \n at the end of printf statement tells program to start a new line.
        printf("Player 1 wins!\n");
    }
    // Compares the scores of player1 and player2.
    else if (score2 > score1)
    {
        // Adding \n at the end of printf statement tells program to start a new line.
        printf("Player 2 wins!\n");
    }
    // Compares the scores of player1 and player2.
    else
    {
        // Adding \n at the end of printf statement tells program to start a new line.
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    // Creates score variable that starts equal to zero.
    int score = 0;

    // Creates a loop to analyze each letter of word submitted by user, one by one, until all letters analyzed.
    for (int i = 0; i < strlen(word); i++)
    {
        // Determines if letter is UPPERCASE, before assigning ASCII value.
        // isupper function below same as writing: if (word[i] > 65 && word[i] <90)
        if (isupper(word[i]))
        {
            // Takes the index value of the letters ASCII value and subtracts 65, to equal the point value listed in line 7. (65 is the difference between the ASCII value and the points value of the game)
            score = score + POINTS[word[i] - 65];
        }
        // Determines if letter is lowercase, before assigning ASCII value.
        // islower fuction below same as writing: if (word[i] > 97 && word[i] < 122)
        if (islower(word[i]))
        {
            // Takes the index value of the letters ASCII value and subtracts 97, to equal the point value listed in line 7. (97 is the difference between the ASCII value and the points value of the game)
            score = score + POINTS[word[i] - 97];
        }
    }
    // Returns collective score of submitted letters.
    return score;
}