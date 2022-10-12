#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Defines size of variable for the program.
#define BLOCKSIZE 512

// Creates function to return input error to User
int inputError()
{
    // Returns message to user.
    printf("Usage: ./recover IMAGE\n");
    // Ends function of program.
    return 1;
}

// Creates function to return file error to User
int fileError(char filename[])
{
    // Returns message to user.
    printf("Unable to open file: %s\n", filename);
    // Ends function of program.
    return 1;
}

// Creates bool function for checking jpeg file names.
bool isJpgHeader(uint8_t buffer[])
{
    // Logic used to check jpeg names in program.
    // All jpeg names should contain one of the character groups below.
    return buffer[0] == 0xff
        && buffer[1] == 0xd8
        && buffer[2] == 0xff
        && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    // Checks validity of argc. Checks for name of program and argument are only items.
    // If contains more or less than those two, will reject and end program.
    if (argc != 2)
    {
        // Returns input error message using function above.
        return inputError();
    }

    // Assigns char pointer to an array.
    char *inputFile = argv[1];
    // Error check: Ensures file present.
    if (inputFile == NULL)
    {
        // Returns input error message using function above.
        return inputError();
    }

    // Creates file pointer. Points program to a specified file.
    FILE *inputPtr = fopen(inputFile, "r");
    // Error check: Ensures file can be read.
    if (inputPtr == NULL)
    {
        return fileError(inputFile);
    }

    // xxx.jpeg'\0'  -the 8 accounts for the 8 characters shown.
    char filename[8];
    // Creates a file pointer.
    FILE *outputPtr = NULL;
    // Initializes buffer for file.
    uint8_t buffer[BLOCKSIZE];
    // Sets counter at 0 to start.
    int jpgCounter = 0;

    // Reads size of file into the buffer, byte by byte, OR the input pointer does not equal the end of file character.
    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, inputPtr) || feof(inputPtr) == 0)
    {
        if (isJpgHeader(buffer))
        {
            // Checks if outputPtr is already being used.
            if (outputPtr != NULL)
            {
                fclose(outputPtr);
            }
            // Creates filename using naming convention listed.
            sprintf(filename, "%03i.jpg", jpgCounter);
            // Sets output pointer to filename that was created, fopens file, and sets to write.
            outputPtr = fopen(filename, "w");
            // Increases counter by one once completed.
            jpgCounter++;
        }
        // Checks if outputPtr is empty.
        if (outputPtr != NULL)
        {
            // Writes from the buffer into the outputPtr file.
            fwrite(buffer, sizeof(buffer), 1, outputPtr);
        }
    }

    // Closes inputPtr file.
    if (inputPtr == NULL)
    {
        fclose(inputPtr);
    }
    // Closes outputPtr file.
    if (outputPtr == NULL)
    {
        fclose(outputPtr);
    }

    fclose(outputPtr);
    fclose(inputPtr);

    // Exits loop.
    return 0;
}