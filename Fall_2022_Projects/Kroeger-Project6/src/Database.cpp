#include "Database.h"

Database::Database()
{
    indexTable = HashTable(); // Populate empty indexTable
}

Database::~Database()
{
    recordStore.clear();
}

bool Database::insert(const Record& newRecord, int& collisions)
{
    Record useRecord = newRecord; // Record for modification

    int CollisionCounter = 0; // Counter for Collisions

    // If we can insert a value into the hash table
    if(indexTable.insert(useRecord.getUID(), recordStore.size(), CollisionCounter)) // Checking is handled internally
    {
        // Place in records
        recordStore.push_back(useRecord);
        // Update collision counter
        collisions = CollisionCounter;
        return true; // Record successfully added
    }

    return false; // Otherwise it can't be done
}

bool Database::remove(int key)
{
    int indexHolder;
    int collisionHolder;

    if (indexTable.find(key, indexHolder, collisionHolder)) // If we find the key
    {
        recordStore[indexHolder] = recordStore[recordStore.size() - 1]; // Set listed index to last element
        recordStore.pop_back(); // Remove last entry

        indexTable.remove(key); // Remove from Hash Table

        return true;
    }

    return false;
}

bool Database::find(int uid, Record& foundRecord, int& collisions)
{
    int indexHolder = 0;

    if (indexTable.find(uid, indexHolder, collisions))
    {
        foundRecord = recordStore[indexHolder];
        return true;
    }

    return false;
}

float Database::alpha()
{
    return indexTable.alpha();
}

ostream& operator<<( ostream& os, Database& db)
{
    // Header
    cout << "Database Contents: " << endl;

    int slotCount = 0;
    int indexHolder = 0;
    int collisionHolder = 0;

    // Actual Contents
    for (auto i: db.recordStore)
    {
        if(db.indexTable.find(i.getUID(), indexHolder, collisionHolder)) // Find entry based on matching UID's
        {
            os << "Hashtable Slot: " << indexHolder << ", recordStore slot " << slotCount << " -- " << i << endl; // Use slot overloading
        }

        slotCount++; // Increment slot count
    }

    return os;
}
