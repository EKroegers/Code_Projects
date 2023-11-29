#include "Trie.h"

Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
    delete root;
}

Trie::Trie(const Trie& other)
{
    root = other.root;
}

Trie& Trie::operator=(const Trie& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int Trie::count()
{
    return wordCount;
}

int Trie::getSize()
{
    return nodeCount;
}

bool Trie::insert(string strToInsert)
{
    // If there is no root
    if (root == nullptr)
    {
        // Make a new root
        root = new TrieNode();
        return insertKey(root, strToInsert);
    }
    else // Otherwise go ahead
    {
        return insertKey(root, strToInsert);
    }
}

bool Trie::insertKey(TrieNode* coreNode, string strToInsert)
{
    // Set pointer at the root
    TrieNode *currentNode = coreNode;

    // Iterate down the length of the string
    for (auto c : strToInsert)
    {
        // Get difference in character position
        int index = c - 'a';

        // If the current node is not already a child
        if (currentNode->children[index] == nullptr)
        {
            // Place a new node in the children array
            currentNode->children[index] = new TrieNode(c);

            // Iterate on Node Count
            nodeCount++;
        }

        // Iterate the pointer down
        currentNode = currentNode->children[index];
    }

    // We have reached the end of an existing word
    if (currentNode->isEndOfWord)
    {
        return false;
    }

    // Mark the last node as end the of the word
    currentNode->isEndOfWord = true;

    // Iterate word count
    wordCount++;

    // Successfully added a new word
    return true;
}

bool Trie::find(string strToFind)
{
    return findKey(root, strToFind);
}

bool Trie::findKey(TrieNode* startNode, string& strToFind)
{
    // Set pointer at the root
    TrieNode* currentNode = startNode;

    // Iterate across the length of the string
    for (auto c : strToFind)
    {
        // Set index
        int index = c - 'a';

        // If the current node is not already a child
        if (currentNode->children[index] == nullptr)
        {
            // Given word does not exist
            return false;
        }

        // Iterate the pointer down
        currentNode = currentNode->children[index];
    }

    // If we iterate through the entire length
    // And never hit a dead end, we found the word
    return true;
}

vector<string> Trie::complete(string strPrefix)
{
    outputString = {};

    startAutoComplete(root, strPrefix);

    return outputString;
}

void Trie::startAutoComplete(TrieNode* currentNode, string strPrefix)
{
    // Pointer at where we start
    TrieNode* pointerNode = currentNode;

    for (char c : strPrefix)
    {
        // Set index
        int index = c - 'a';

        // Prefix does not exist
        if (pointerNode->children[index] == nullptr)
        {
            // bail
            return;
        }

        // Iterate down the line
        pointerNode = pointerNode->children[index];
    }

    // Ships prefix off to the function to get all children
    collectAutoComplete(pointerNode, strPrefix);
}

void Trie::collectAutoComplete(TrieNode* currentNode, string strPrefix)
{
    // Cout when we found the end of a word
    if (currentNode->isEndOfWord)
    {
        outputString.push_back(strPrefix);
    }
    // Allow to continue after the addition because the English language

    // Loop through all children of the node
    for (int i = 0; i < 26; i++)
    {
        // Continue down the line if there are children
        if (currentNode->children[i] != nullptr)
        {
            // Character for output
            char childChar = currentNode->children[i]->data;

            // Append char
            strPrefix.push_back(childChar);

            // Recursive call
            collectAutoComplete(currentNode->children[i], strPrefix);
        }
    }
}

int Trie::completeCount(string strPrefix)
{
    completedPrefixCount = 0;

    startCountAutoComplete(root, strPrefix);

    return completedPrefixCount;
}

void Trie::startCountAutoComplete(TrieNode* currentNode, string strPrefix)
{
    // Pointer at where we start
    TrieNode* pointerNode = currentNode;

    for (char c : strPrefix)
    {
        // Set index
        int index = c - 'a';

        // Prefix does not exist
        if (pointerNode->children[index] == nullptr)
        {
            // bail
            return;
        }

        // Iterate down the line
        pointerNode = pointerNode->children[index];
    }

    // Ships prefix off to the function to get all children
    countAutoComplete(pointerNode, strPrefix);
}

void Trie::countAutoComplete(TrieNode* currentNode, string strPrefix)
{
    // Cout when we found the end of a word
    if (currentNode->isEndOfWord)
    {
        // Iterate the count
        completedPrefixCount++;
    }
    // Allow to continue after the count because the English language

    // Loop through all children of the node
    for (int i = 0; i < 26; i++)
    {
        // Continue down the line if there are children
        if (currentNode->children[i])
        {
            // Character for output
            char childChar = currentNode->children[i]->data;

            // Append char
            strPrefix.push_back(childChar);

            // Recursive call
            countAutoComplete(currentNode->children[i], strPrefix);
        }
    }
}
