#include <Slot.h>
#define MAXHASH 20

class HashTable
{
    public:
        HashTable();
        virtual ~HashTable();
        // Insert a new key/index pair into the table
        bool insert(int key, int index, int& collisions);
        // If there is a record with the given key in the hash table, it is deleted
        bool remove(int key);
        // Checks if a record with the given key is found in the hash table
        bool find(int key, int& index, int& collisions);
        // returns the current loading factor, alpha, of the hash table.
        float alpha();
        // Overload << operator
        friend ostream& operator<<( ostream&, HashTable& );
        // Actual held data
        Slot hashTable[MAXHASH];
};
