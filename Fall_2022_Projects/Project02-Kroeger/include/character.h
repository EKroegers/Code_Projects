#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

class character
{
    private:
        string strName, strRole;
        int intHitPoints;
        int intAttackBonus;
        int intDamageBonus;
        int intArmorClass;

    public:
        character(string _strName, string _strRole, int _intHitPoints, int _intAttackBonus, int _intDamageBonus, int _intArmorClass)
        {
            strName = _strName;
            strRole = _strRole;
            intHitPoints = _intHitPoints;
            intAttackBonus = _intAttackBonus;
            intDamageBonus =_intDamageBonus;
            intArmorClass = _intArmorClass;
        }

        int getHealth()
        {
            return this->intHitPoints;
        }

        string getName()
        {
            return this->strName;
        }

        string getRole()
        {
            return this->strRole;
        }

        void damage(int amount)
        {
            this->intHitPoints -= amount;

            if (intHitPoints < 0)
            {
                intHitPoints = 0;
            }
        }

        void attack(character &otherCharacter)
        {
            cout << this->getName() << " attacks!" << endl;

            srand(time(0));
            int attackRoll = rand() % 20 + 1;

            int attackTotal = attackRoll + otherCharacter.intAttackBonus;

            int intDamageRoll = (rand() % 10 + 1);

            if (attackTotal > otherCharacter.intArmorClass)
            {

                cout << "Attack roll: " << attackRoll << " + " << this->intAttackBonus << " = " << attackTotal << " --> HIT!" << endl;

                cout << "Damage: " << intDamageRoll << " + " << this->intDamageBonus << " = " << intDamageRoll + this->intDamageBonus << endl;

                otherCharacter.damage(intDamageRoll + this->intDamageBonus);

                cout << otherCharacter.getName() << " has " << otherCharacter.getHealth() << " hit points remaining" << endl;
            }
            else
            {
                cout << "Attack roll: " << attackRoll << " + " << otherCharacter.intAttackBonus << " = " << attackTotal << " --> MISS!" << endl;
            }

        }

        virtual ~character();
};

#endif // CHARACTER_H
