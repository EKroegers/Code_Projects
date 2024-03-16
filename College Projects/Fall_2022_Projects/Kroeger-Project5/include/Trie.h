#ifndef TRIE_H
#define TRIE_H

using namespace std;

#include <vector>
#include <string>
#include <iostream>

static int wordCount = 0;
static int nodeCount = 0;
static int completedPrefixCount = 0;
static vector<string> outputString = {};

class Trie
{
    public:
        Trie();
        ~Trie();
        Trie(const Trie& other);
        Trie& operator=(const Trie& other);
        //Trie& operator=(const Trie&) – trie1 = trie2;

        // Inserts new word into trie
        bool insert(string strToInsert);

        // return the number of words in the trie
        int count();

        // return the total number of nodes in the trie
        int getSize();

        // Returns true if the word is found, false if not
        bool find(string strToFind);

        // Returns the number of words that begin with the given string
        int completeCount(string strPrefix);

        // Returns a vector of strings that begin with the given string
        vector<string> complete(string strPrefix);

    private:

        class TrieNode
        {
            public:

                // Constructor
                TrieNode()
                {
                    // Initialize printable data to nothing
                    data = ' ';

                    // No children
                    for (int i = 0; i < 26; i++)
                    {
                        children[i] = nullptr;
                    }

                    // Not the end of word by default
                    isEndOfWord = false;
                };

                // Arg Constructor
                TrieNode(char c)
                {
                    // Initialize printable data to nothing
                    data = c;

                    // No children
                    for (int i = 0; i < 26; i++)
                    {
                        children[i] = nullptr;
                    }

                    // Not the end of word by default
                    isEndOfWord = false;
                };

                // Deconstructor
                ~TrieNode()
                {
                    // Iterate across all children
                    for (auto const& c: children)
                    {
                        // Deletes the VALUE of the child
                        delete c;
                    }
                }

                // Array to hold all of the letters of children
                TrieNode* children[26];

                // Character held
                char data;

                // Denotes end of word
                bool isEndOfWord = false;
        };

        // Helper function for insert
        bool insertKey(TrieNode *root, string strToInsert);

        // Helper function for find
        bool findKey(TrieNode* root, string& strToFind);

        // Helper function for completeCount
        void countAutoComplete(TrieNode* currentNode, string strPrefix);

        // Helper function for completeCount
        void startCountAutoComplete(TrieNode* currentNode, string strPrefix);

        // Helper function for complete
        void startAutoComplete(TrieNode* currentNode, string strPrefix);

        // Helper function for complete
        void collectAutoComplete(TrieNode* currentNode, string strPrefix);

        // Pointer to root
        TrieNode* root;

};

#endif // TRIE_H
