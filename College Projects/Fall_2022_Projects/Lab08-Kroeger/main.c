#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct address_t
{
    // Integers for Address
    int A;
    int B;
    int C;
    int D;

    // String for Host Name
    char HostName[20];
};

struct dns_t
{
    // Array of Addresses
    struct address_t Addresses[25];
};

// Functions def
int scan_file(struct dns_t);
void find_hostname(struct dns_t, int);
void find_ip(struct dns_t, int);
void print_subnet_d_hosts(struct dns_t, int);

int main()
{
    bool keepGoing = true;
    char userInput = ' ';

    struct dns_t inputData;
    int lineNum;

    printf("Welcome to the IPv4 lookup.\n");
    printf("s - scan a data file\nh - find a hostname associated with an IP address\ni - find an ip address associated with a hostname\np - print hostnames associated with a subnet\nq - end program\n");

    // Loop for user input
    while (keepGoing)
    {
        printf("Pick something to do: ");
        scanf("%s", &userInput);

        switch (userInput)
        {
            case 's' :
                // Scan in a data file
                lineNum = scan_file(inputData);
                printf("Data Scanned\n");
                break;
            case 'h' :
                // Find a hostname associated with an IP address
                find_hostname(inputData, lineNum);
                break;
            case 'i' :
                // Find an ip address associated with a hostname
                find_ip(inputData, lineNum);
                break;
            case 'p' :
                // Print hostnames associated with a subnet
                print_subnet_d_hosts(inputData, lineNum);
                break;
            case 'q' :
                // End program
                printf("\nSee Ya!\n");
                keepGoing = false;
                break;

        }

    }
    return 0;
}

int scan_file(struct dns_t inputData)
{
    // Read in file
    FILE *fp = fopen("data.txt", "r");

    char line[128]; // Allocate line

    int lineCount = 0; // Counter for lines

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        int holder = 0;

        char * chunk = strtok(line, "."); // Get A
        sscanf(chunk, "%d", &holder); // Convert to int
        inputData.Addresses[lineCount].A = holder;

        chunk = strtok(NULL, "."); // Get B
        sscanf(chunk, "%d", &holder); // Convert to int
        inputData.Addresses[lineCount].B = holder;

        chunk = strtok(NULL, "."); // Get C
        sscanf(chunk, "%d", &holder); // Convert to int
        inputData.Addresses[lineCount].C = holder;

        chunk = strtok(NULL, "."); // Get D
        sscanf(chunk, "%d", &holder); // Convert to int
        inputData.Addresses[lineCount].D = holder;

        chunk = strtok(chunk, " "); // Get Hostname
        chunk = strtok(NULL, " ");
        strcpy(inputData.Addresses[lineCount].HostName, chunk);

        lineCount++; // Iterate line count
    }

    fclose(fp);

    return lineCount;
}

void find_hostname(struct dns_t inputData, int lineNum)
{
    // Get Input
    char hostIpInput[20];
    printf("Enter an Ip: ");
    scanf(" %c", &hostIpInput);

    int tempA;
    int tempB;
    int tempC;
    int tempD;

    // Process Input
    char * chunk = strtok(hostIpInput, "."); // Get A
    sscanf(chunk, "%d", &tempA); // Convert to int

    chunk = strtok(NULL, "."); // Get B
    sscanf(chunk, "%d", &tempB); // Convert to int

    chunk = strtok(NULL, "."); // Get C
    sscanf(chunk, "%d", &tempC); // Convert to int

    chunk = strtok(NULL, "."); // Get D
    sscanf(chunk, "%d", &tempD); // Convert to int

    for(int i = 0; i < lineNum; i++)
    {

        if(inputData.Addresses[lineNum].A == tempA && inputData.Addresses[lineNum].B == tempB && inputData.Addresses[lineNum].C == tempC && inputData.Addresses[lineNum].D == tempD)
        {
            printf("The IP matches host name %s", inputData.Addresses[lineNum].HostName);
        }
    }
}

void find_ip(struct dns_t inputData, int lineNum)
{
    char hostName[20];
    printf("Enter a Hostname: ");
    scanf("%s", &hostName);

    for(int i = 0; i < lineNum; i++)
    {
        if(strcmp(inputData.Addresses[lineNum].HostName, hostName) == 0)
        {
            printf("The host name matches IP %d . %d . %d . %d", inputData.Addresses[lineNum].A, inputData.Addresses[lineNum].B, inputData.Addresses[lineNum].C, inputData.Addresses[lineNum].D);
        }
    }
}

void print_subnet_d_hosts(struct dns_t inputData, int lineNum)
{
        // Get Input
    char hostIpInput[20];
    printf("Enter an Ip: ");
    scanf("%s", &hostIpInput);

    int tempA;
    int tempB;
    int tempC;

    // Process Input
    char * chunk = strtok(hostIpInput, "."); // Get A
    sscanf(chunk, "%d", &tempA); // Convert to int

    chunk = strtok(NULL, "."); // Get B
    sscanf(chunk, "%d", &tempB); // Convert to int

    chunk = strtok(NULL, "."); // Get C
    sscanf(chunk, "%d", &tempC); // Convert to int

    for(int i = 0; i < lineNum; i++)
    {
        if(inputData.Addresses[lineNum].A == tempA && inputData.Addresses[lineNum].B == tempB && inputData.Addresses[lineNum].C == tempC)
        {
            printf("The IP subnet matches host name %s", inputData.Addresses[lineNum].HostName);
        }
    }
}
