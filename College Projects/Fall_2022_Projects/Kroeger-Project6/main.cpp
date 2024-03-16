#include <iostream>
#include <Database.h>
#include <limits>

using namespace std;

int main()
{
    // Variable Declarations
    bool keepGoing = true; // For loop
    char userInput = ' '; // For option selection

    string LastNameInput; // For Last Name input
    string FirstNameInput; // For First Name input
    int UIDInput = 0; // For UID input
    string YearInput; // For Year input

    int collisionCounter = 0; // Collision Counter

    Record useRecord; // Flexible record for internal use
    Database mainDatabase; // Database for overall use

    // Loop for user input
    while (keepGoing)
    {
        cout << "\nWould you like to (I)nsert or (D)elete a record, (S)earch for a record, (P)rint the database, or (Q)uit?" << endl;
        cout << "\nEnter Action: ";
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (userInput)
        {
            case 'I' : // Insert a new record
                cout << "Inserting a new record." << endl;

                // Get inputs (and clear buffer after every cin)
                cout << "Last name: ";
                cin >> LastNameInput;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "First name: ";
                cin >> FirstNameInput;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "UID: ";
                cin >> UIDInput;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Year: ";
                cin >> YearInput;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                useRecord.load(FirstNameInput, LastNameInput, UIDInput, YearInput);

                // Attempt to insert record
                if (mainDatabase.insert(useRecord, collisionCounter))
                {
                    cout << "Record inserted (" << collisionCounter << " collisions during insert)." << endl;
                }
                else
                {
                    cout << "Insert Failed" << endl;
                }
                keepGoing = true;
                break;
            case 'D' : // Delete a record
                cout << "Enter a UID to delete: ";
                cin >> UIDInput;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Deleting... ";
                if (mainDatabase.remove(UIDInput))
                {
                    cout << " record deleted" << endl;
                }
                else
                {
                    cout << " record not found" << endl;
                }
                keepGoing = true;
                break;
            case 'S' : // Search for a record
                cout << "Enter a UID to search for: ";
                cin >> UIDInput;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Searching... ";
                if (mainDatabase.find(UIDInput, useRecord, collisionCounter))
                {
                    cout << "Record found (" << collisionCounter << " collisions during search)" << endl;
                    cout << useRecord << endl;
                }
                else
                {
                    cout << " record not found" << endl;
                }
                keepGoing = true;
                break;
            case 'P' : // Print the Database
                cout << mainDatabase << endl;
                keepGoing = true;
                break;
            case 'Q' :
                // End loop
                keepGoing = false;
                // See Ya!
                cout << "\nSee Ya!\n";
                break;
        }
    }

    return 0;
}
