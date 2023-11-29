#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct character_t
{
    // Node Data Definitions
    char character[20];
    int armor;
    int weapon;
    int talents;

    // Pointer to next node
    struct character_t* nextCharacter;
};

// Functions def
void scan_file(struct character_t **root);
void free_list(struct character_t **root);
void find_character(struct character_t **root);
void add_character(struct character_t **root);
void print_list(struct character_t **root);

int main()
{
    // Variable Declarations
    bool keepGoing = true;
    char userInput = ' ';

    // Set up root
    struct character_t *root = NULL;

    printf("Welcome to the Game Helper.\n");
    printf("s - scan a data file\nf - find character stats\na - add a character\nd - remove a character\np - print characters & stats to file\nq - end program\n");

    // Loop for user input
    while (keepGoing)
    {
        printf("\nPick something to do: ");
        scanf("%s", &userInput);

        switch (userInput)
        {
            case 's' :
                scan_file(&root);
                keepGoing = true;
                break;
            case 'f' :
                find_character(&root);
                keepGoing = true;
                break;
            case 'a' :
                add_character(&root);
                keepGoing = true;
                break;
            case 'p' :
                print_list(&root);
                keepGoing = true;
                break;
            case 'q' :
                // End loop
                keepGoing = false;
                // Free Memory
                free_list(&root);
                // See Ya!
                printf("\nSee Ya!\n");
                break;
        }
    }

    return 0;
}

void free_list(struct character_t **root)
{
    struct character_t *currentNode = *root;

    while(currentNode->nextCharacter != NULL)
    {
        struct character_t *nextCharacter = currentNode->nextCharacter;
        free(currentNode);
        currentNode = nextCharacter;
    }
}

void scan_file(struct character_t **root)
{
    // Read in file
    FILE *fp = fopen("lab10_data.txt", "r");

    char line[128]; // Allocate line

    // Set up root
    *root = (struct character_t *)malloc(sizeof(struct character_t));
    (*root)->armor = 0;
    (*root)->weapon = 0;
    (*root)->talents = 0;
    (*root)->nextCharacter = NULL;

    // Set pointer to current character in sequence
    struct character_t* currentCharacter = *root;

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        int numHolder = 0;

        char * chunk = strtok(line, " "); // Get Character Name
        strcpy(currentCharacter->character, chunk);

        chunk = strtok(NULL, " "); // Get Armor
        sscanf(chunk, "%d", &numHolder); // Convert to int
        currentCharacter->armor = numHolder;

        chunk = strtok(NULL, " "); // Get Weapon
        sscanf(chunk, "%d", &numHolder); // Convert to int
        currentCharacter->weapon = numHolder;

        chunk = strtok(NULL, " "); // Get Talents
        sscanf(chunk, "%d", &numHolder); // Convert to int
        currentCharacter->talents = numHolder;

        // Set up new node
        struct character_t *newCharacter = (struct character_t *)malloc(sizeof(struct character_t));
        (*newCharacter).armor = 0;
        (*newCharacter).weapon = 0;
        (*newCharacter).talents = 0;
        (*newCharacter).nextCharacter = NULL;

        // Transfer
        currentCharacter->nextCharacter = newCharacter;

        // Iterate
        currentCharacter = currentCharacter->nextCharacter;
    }

    fclose(fp);
}

void find_character(struct character_t **root)
{
    struct character_t* currentCharacter = *root;
    char userInput[20];
    bool charFound = false;

    printf("Select a character to search for: ");
    scanf("%s", &userInput);

    while(currentCharacter)
    {
        if (strcmp(userInput, currentCharacter->character) == 0)
        {
            charFound = true;
        }

        currentCharacter = currentCharacter->nextCharacter;
    }

    if (charFound)
    {
        printf("%s was in the list", userInput);
    }
    else
    {
        printf("Not in the list");
    }
}

void add_character(struct character_t **root)
{
    struct character_t* currentCharacter = *root;

    // Walk to the end of the list
    while(currentCharacter->nextCharacter)
    {
        currentCharacter = currentCharacter->nextCharacter;
    }

    // Prompt for user inputs
    char userNameInput[20];

    printf("Input a new character name: ");
    scanf("%s", &userNameInput);

    int userArmorInput;

    printf("Input a new armor value: ");
    scanf("%d", &userArmorInput);

    int userWeaponInput;

    printf("Input a new weapon value: ");
    scanf("%d", &userWeaponInput);

    int userTalentInput;

    printf("Input a new talent value: ");
    scanf("%d", &userTalentInput);

    // Make new character
    struct character_t *newCharacter = (struct character_t *)malloc(sizeof(struct character_t));
    strcpy((*newCharacter).character, userNameInput);
    (*newCharacter).armor = userArmorInput;
    (*newCharacter).weapon = userWeaponInput;
    (*newCharacter).talents = userTalentInput;
    (*newCharacter).nextCharacter = NULL;

    // Tie to previous end
    currentCharacter->nextCharacter = newCharacter;
}

void print_list(struct character_t **root)
{
    struct character_t* currentCharacter = *root;

    // Write in file
    FILE *fp = fopen("updated-data.txt", "w");

    while (currentCharacter)
    {
        fprintf(fp, "%s %d %d %d\n", currentCharacter->character, currentCharacter->armor, currentCharacter->weapon, currentCharacter->talents);

        currentCharacter = currentCharacter->nextCharacter;
    }

    fclose(fp);
}
