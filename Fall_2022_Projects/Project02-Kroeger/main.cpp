#include <iostream>
#include "character.h"

using namespace std;

int main()
{
    // initialization for inputs
    string strName, strRole;
    int intHitPoints;
    int intAttackBonus;
    int intDamageBonus;
    int intArmorClass;

    // build first character
    cout << "First character name?" << endl;
    cin >> strName;
    cout << strName << "'s role?" << endl;
    cin >> strRole;
    cout << strName << " the " << strRole << "'s hit points?" << endl;
    cin >> intHitPoints;
    cout << strName << " the " << strRole << "'s attack bonus?" << endl;
    cin >> intAttackBonus;
    cout << strName << " the " << strRole << "'s damage bonus?" << endl;
    cin >> intDamageBonus;
    cout << strName << " the " << strRole << "'s armor class?" << endl;
    cin >> intArmorClass;

    // display inputs
    cout << "\nCharacter summary" << endl;
    cout << "-----------------" << endl;
    cout << strName << " the " << strRole << endl;
    cout << "HP: " << intHitPoints << endl;
    cout << "AB: " << intAttackBonus << endl;
    cout << "DB: " << intDamageBonus << endl;
    cout << "AC: " << intArmorClass << endl;

    // create first character object
    character FirstCharacter = character(strName, strRole, intHitPoints, intAttackBonus, intDamageBonus, intArmorClass);

    // build second character
    cout << "\nSecond character name?" << endl;
    cin >> strName;
    cout << strName << "'s role?" << endl;
    cin >> strRole;
    cout << strName << " the " << strRole << "'s hit points?" << endl;
    cin >> intHitPoints;
    cout << strName << " the " << strRole << "'s attack bonus?" << endl;
    cin >> intAttackBonus;
    cout << strName << " the " << strRole << "'s damage bonus?" << endl;
    cin >> intDamageBonus;
    cout << strName << " the " << strRole << "'s armor class?" << endl;
    cin >> intArmorClass;

    // display inputs
    cout << "\nCharacter summary" << endl;
    cout << "-----------------" << endl;
    cout << strName << " the " << strRole << endl;
    cout << "HP: " << intHitPoints << endl;
    cout << "AB: " << intAttackBonus << endl;
    cout << "DB: " << intDamageBonus << endl;
    cout << "AC: " << intArmorClass << endl;
    cout << endl;

    // create second character object
    character SecondCharacter = character(strName, strRole, intHitPoints, intAttackBonus, intDamageBonus, intArmorClass);

    // combat loop
    while ((FirstCharacter.getHealth() != 0) && (SecondCharacter.getHealth() != 0))
    {
        // trade attacks
        FirstCharacter.attack(SecondCharacter);
        // if Second Character dies
        if (SecondCharacter.getHealth() == 0)
        {
            // exit loop
            break;
        }
        SecondCharacter.attack(FirstCharacter);
        // leaves loop if First Character dies
    }

    // display winner
    if (FirstCharacter.getHealth() == 0)
    {
        cout << SecondCharacter.getName() << " wins!" << endl;
    }
    else
    {
        cout << FirstCharacter.getName() << " wins!" << endl;
    }

    return 0;
}
