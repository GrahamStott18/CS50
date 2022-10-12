#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Prompt user to input text.
    string text = get_string("Text: ");

    // Creates variable to count letters, and sets equal to zero at start of program.
    int letters = 0;
    // Creates variable to count words, and sets equal to ONE at start of program. This is to account for the final word in the text.
    int words = 1;
    // Creates variable to count sentences, and sets equal to zero at start of program.
    int sentences = 0;

    // Sets an index equal to zero to start checking inputted text, keep checking text until all string complete, checks letters one by one.
    for (int i = 0; i < strlen(text); i++)
    {
        // Determines if letters in text are UPPERCASE letter or a lowercase letter, then counts each letter.
        // isalpha function below, is used to replace following code:  if(text[i] > 65 && text[i] < 90) || (text[i] > 97 && text[i] < 122))
        // && is used to say AND, || is used to say OR.
        if (isalpha(text[i]))
        {
            // Counts letters one by one.
            letters++;
        }
        // Counts each space in between letters to calculate number of words in text.
        else if (text[i] == ' ')
        {
            // Counts words one by one, by counting spaces between letters.
            words++;
        }
        // Analyze text and find any full stops (Periods, Question Marks, Exclaimation Marks).
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            // Count full stops in text, one by one.
            sentences++;
        }
    }
    // Creates a float variable from text count data to input into formula. (L = avg # of letters per 100 words in the text)
    // (float) added in front of letters and words to change them from int to float, temporarily. Needed so C returns as a float, not an int.
    float L = (float) letters / (float) words * 100;
    // Creates a float variable from text count data to input into formula. (S = avg # of sentences per 100 words in the text)
    // (float) added in front of sentences and words to change them from int to float, temporarily. Needed so C returns as a float, not an int.
    float S = (float) sentences / (float) words * 100;

    // Input data counts from text (letter count, word count, sentence count) into the Coleman-Liau formula to determine Grade Level.
    // round() function comes from <math.h> library.
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Compares result from formula, to see if result is less than one.
    if (index < 1)
    {
        // Prints statement if results less than one.
        // \n added to create new line
        printf("Before Grade 1\n");
    }

    // Compares result from formula, to see if result is greater than sixteen.
    else if (index > 16)
    {
        // Prints statement if results greater than sixteen.
        // \n added to create new line
        printf("Grade 16+\n");
    }

    // Compares results from formula, to see if between one and sixteen.
    else
    {
        // Prints statement if results are between one and sixteen.
        // \n added to create new line
        printf("Grade %i\n", index);
    }
}