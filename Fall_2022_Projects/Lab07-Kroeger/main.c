#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

bool contains(char InputArray[], char guess);

int main()
{
    char newGuess = " ";
    char word[9] = "code"; // Hard coded word
    char guesses[15];

    int guessCount = 0;
    int correctGuesses = 0;

    bool correct = false;

    printf("Let's play hangman!\n");

    // Loop for user input
    while (!correct)
    {
        printf("Enter a letter: ");
        scanf(" %c", &newGuess);

        if (contains(guesses, newGuess))
        {
            printf("you already picked that letter\n");
        }
        else
        {
            if (contains(word, newGuess))
            {
                printf("the letter %c is in the word!\n", newGuess);
                correctGuesses++;
            }
            else
            {
                printf("sorry buddy, try again\n");
            }

            guesses[guessCount] = newGuess;
            guessCount++;
        }

        if (correctGuesses == 4) // number of UNIQUE letters in word
        {
            printf("You got it! the word was %s", word);
            correct = true;
        }

        if (guessCount == 15)
        {
            printf("Sorry, you ran out of guesses, the word was %s", word);
            correct = true;
        }
    }

    return 0;
}

bool contains(char InputArray[], char guess) // Function checks if provided character is in the array
{
    for (int i = 0; i < (int)(sizeof(InputArray)/(sizeof(InputArray[0]))); i++)
    {
        if (InputArray[i] == guess)
        {
            return true;
        }
    }

    return false;
}
