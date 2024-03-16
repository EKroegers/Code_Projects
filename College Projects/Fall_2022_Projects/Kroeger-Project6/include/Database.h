#include <HashTable.h>
#include <Record.h>
#include <vector>

class Database
{
    public:
        Database();
        virtual ~Database();
        // Insert a new student record into the database
        bool insert(const Record& newRecord, int& collisions);
        // If there is a record with the given key in the Database, it is deleted
        bool remove(int key);
        // Checks if a record with the given uid is found in the Database
        bool find(int uid, Record& foundRecord, int& collisions);
        // returns the current loading factor, alpha, of the Database's hash table
        float alpha();
        // Overload << operator
        friend ostream& operator<<( ostream&, Database& );

    private:
        HashTable indexTable;
        vector<Record> recordStore;
};
