#include "HashTable.h"
#include "hashfunction.h"

HashTable::HashTable()
{
    // Build empty hash table
    for(auto c: hashTable)
    {
        c = Slot();
    }
}

HashTable::~HashTable()
{
}

bool HashTable::insert(int key, int index, int& collisions)
{
    int hashIndex = jsHash(key);

    for(int i = 0; i < MAXHASH; i++) // Check if it is in the table
    {
        if (hashTable[hashIndex%MAXHASH].getKey() == key && !hashTable[hashIndex%MAXHASH].isEmpty())
        {
            return false; // Entry exists
        }

        if (hashTable[hashIndex%MAXHASH].isEmpty())
        {
            hashTable[hashIndex%MAXHASH].load(key, index);
            return true; // Successfully filled slot
        }

        collisions++;
        hashIndex += 3; // PR Probing
    }

    return false; // Table is full
}

bool HashTable::remove(int key)
{
    int hashIndex = jsHash(key);

    for(int i = 0; i < MAXHASH; i++) // Check if it is in the table
    {
        if (hashTable[hashIndex%MAXHASH].isEmpty())
        {
            return false; // Does not exist
        }

        if (hashTable[hashIndex%MAXHASH].getKey() == key && !hashTable[hashIndex%MAXHASH].isEmpty())
        {
            hashTable[hashIndex%MAXHASH].kill();
            return true; // Entry exists and was removed
        }

        hashIndex += 3; // PR Probing
    }

    return false; // Entry not found
}

bool HashTable::find(int key, int& index, int& collisions)
{
    int hashIndex = jsHash(key);

    for(int i = 0; i < MAXHASH; i++) // Check if it is in the table
    {
        if (hashTable[hashIndex%MAXHASH].getKey() == key && !hashTable[hashIndex%MAXHASH].isEmpty())
        {
            index = hashIndex%MAXHASH;
            return true; // Entry exists
        }

        collisions++;
        hashIndex += 3; // PR Probing
    }

    return false; // Entry not found
}

float HashTable::alpha()
{
    int filledCount = 0;

    for (auto i: hashTable)
    {
        if (!i.isEmpty()) // If it is not empty
        {
            filledCount++;
        }
    }

    return (filledCount/MAXHASH);
}

ostream& operator<<( ostream& os, HashTable& ht)
{
    // Header
    cout << "HashTable Contents: " << endl;

    int slotCount = 0;

    // Actual Contents
    for (auto i: ht.hashTable)
    {
        if (!i.isEmpty()) // Don't print empty slots
        {
            os << "Hashtable Slot " << slotCount << ": " << i << endl; // Use slot overloading
        }

        slotCount++; // Increment slot count
    }

    return os;
}
