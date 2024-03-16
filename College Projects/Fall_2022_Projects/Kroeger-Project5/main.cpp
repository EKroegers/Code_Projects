#include <iostream>
#include <string.h>
#include <fstream>
#include <Trie.h>

using namespace std;

int main()
{
    char userInput[20];
    char userSecondaryInput[20];
    Trie englishTrie;

    vector<string> collectedWords = {};

    // Load in dictionary
    std::ifstream file("wordlist_windows.txt");

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {
            englishTrie.insert(line.c_str());
        }

        file.close();
    }

    // Infinite loop for user input
    while (true)
    {
        // Get user input
        printf("Please enter a word prefix (or press enter to exit): ");
        fgets(userInput, 20, stdin);

        // Trim newline
        userInput[strcspn(userInput, "\n")] = '\0';

        // Exit if only enter is pressed
        if (userInput[0] == '\0')
        {
            return 0;
        }

        // Show results of search
        printf("\nThere are %d completions for the prefix '%s'.  Show completions? ", englishTrie.completeCount(userInput), &userInput);

        // Get the input for showing matches
        fgets(userSecondaryInput, 20, stdin);

        // Trim newline
        userSecondaryInput[strcspn(userSecondaryInput, "\n")] = '\0';

        // Show matches
        if (strcmp(userSecondaryInput, "Yes") == 0 || strcmp(userSecondaryInput, "yes") == 0)
        {
            collectedWords = englishTrie.complete(userInput);

            for (auto c: collectedWords)
            {
                cout << c << endl;
            }
        }

        // otherwise loop again
        printf("\n");
    }

    return 0;
}
