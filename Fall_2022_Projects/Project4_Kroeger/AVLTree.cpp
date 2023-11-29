#include <AVLTree.h>
#include <iostream>
using namespace std;

// No-Arg Constructor
AVLTree::AVLTree()
{
    root = nullptr;
}
// Copy constructor
AVLTree::AVLTree(const AVLTree& other)
{
    root = copyNodes(other.root);
}
// Deconstructor
AVLTree::~AVLTree()
{
    delete root; // The only part of the tree
}
// adds a new node into tree based on given parameters
bool AVLTree::insert(int key, string value)
{
    if (!this->find(key, value)) // If it is not a duplicate
    {
        // Make a new node
        Node* newNode = new Node(key, value);

        if (root == nullptr) // If it's the first node in the tree
        {
            root = newNode; // Make it the new root

            return 1; // Node is placed as root
        }
        else // Otherwise place it where it belongs in the tree
        {
            Node* currentNode = root; // Place pointer at the root

            while (true) // Loop to place the node
            {
                if (key < currentNode->key) // if it needs to go left
                {
                    if (currentNode->leftChild == nullptr) // if it can become the left child of the current node
                    {
                        currentNode->leftChild = newNode; // Place the new node and update the parent
                        newNode->parent = currentNode;

                        int balance = getBalance(newNode); // Check balance

                        pickRotation(balance, newNode); // Do rotation if needed

                        break;
                    }
                    else // Otherwise we move down the line
                    {
                        currentNode = currentNode->leftChild;
                    }
                }
                else if (key > currentNode->key) // if it needs to go right
                {
                    if (currentNode->rightChild == nullptr) // if it can become the left child of the current node
                    {
                        currentNode->rightChild = newNode; // Place the new node and update the parent
                        newNode->parent = currentNode;

                        int balance = getBalance(newNode); // Check balance

                        pickRotation(balance, newNode); // Do rotation if needed

                        break;
                    }
                    else // Otherwise we move down the line
                    {
                        currentNode = currentNode->rightChild;
                    }
                }
            }
            newNode->depth = updateDepth(newNode); // Update node depth/height

            return 1; // Node is placed in tree
        }
    }
    else // If it is a duplicate
    {
        return 0;
    }
}
// returns true or false based on if a node is in the tree
bool AVLTree::find(int key, string& value)
{
    Node* currentNode = root; // Place pointer at the root

    while (currentNode != nullptr) // if we haven't hit the end yet
    {
        if (currentNode->key == key) // If we found it
        {
            value = currentNode->value; // Set value

            return 1;
        }
        if (key < currentNode->key) // if the pointer needs to go left
        {
            currentNode = currentNode->leftChild;
        }
        else // if the pointer needs to go right
        {
            currentNode = currentNode->rightChild;
        }
    }

    return 0;
}
// returns height of tree
int AVLTree::getHeight()
{
    return Height(root); // Call helper function for no-arg interface function
}
// helper function to get height of tree rooted by the current node
int AVLTree::Height(Node* node)
{
    int height = 0; // initialize temp height value

    if (node != nullptr)
    {
        int left_height = Height(node->leftChild); // recursive call to get the left branch height at current node
        int right_height = Height(node->rightChild); // recursive call to get the right branch height at current node
        int maxHeight = max(left_height, right_height); // Check which is larger
        height = maxHeight + 1; // update height
    }

    return height;
}
// returns number of nodes in tree
int AVLTree::getSize()
{
    return getNodeCount(root); // Call helper function for no-arg interface function
}
// Helper function to get node count
int AVLTree::getNodeCount(Node* root)
{
    if(root != nullptr) // as long as the provided one exists
    {
        getNodeCount(root->leftChild); // Recursive call on the left side
        nodeCount++; // Increment count
        getNodeCount(root->rightChild); // Recursive call on the right side
    }

    return nodeCount;
}
// Helper function that updates the depth/height of a newly added node based on parent pointers
int AVLTree::updateDepth(Node* node)
{
    if (node != nullptr && node->parent != nullptr)
    {
        int height = 0; // initialize height variable

        while (node->parent != nullptr) // loop back up through the tree
        {
            height++; // Increment height
            node = node->parent; // move up the tree
        }

        return height;
    }
    else
    {
        return 0;
    }
}
// cout override to display tree
ostream& operator<<(ostream& os, const AVLTree& me)
{
    AVLTree meTree = me; // create a new tree to facilitate const
    // Call helper to facilitate recursion
    meTree.printPreorder(meTree.root);
    os << tree;
    return os;
}
// = override to create new copy of AVLTree
AVLTree& AVLTree::operator=(const AVLTree& me)
{
    AVLTree outputTree; // Create new tree object for output

    outputTree.root = copyNodes(me.root); // Call helper function to copy the root and rest of the nodes

    return outputTree; // Output new unique tree object
}
// Helper function to do preorder traversal
void AVLTree::printPreorder(Node* node)
{
    if (node == nullptr) // end the recursion
    {
        return;
    }

    // indent based on height
    for (int i = 0; i < node->depth; i++)
    {
        tree += "\t";
    }
    // print the value of the node
    tree += node->value;

    // new line
    tree += "\n";
    // Recursive call on the left subtree
    printPreorder(node->leftChild);

    // Recursive call on the right subtree
    printPreorder(node->rightChild);
}
// Helper function to copy nodes for use in = operator and copy constructor
AVLTree::Node* AVLTree::copyNodes(Node* node)
{
    if (node != nullptr)
    {
        Node* leftChild = copyNodes(node->leftChild); // Recursion, again, to copy all left children
        Node* rightChild = copyNodes(node->rightChild); // Recursion, again again, to copy all right children

        return new Node(node->key, node->value, node->parent, leftChild, rightChild, node->depth); // output new root with all references of the other tree
    }
    else
    {
        return nullptr;
    }
}
// Rotation Functions
// left rotation
AVLTree::Node* AVLTree::LeftRotation(Node *original)
{

    Node *temp1 = original->rightChild; // Going to be new root

    if (temp1 == nullptr)
    {
        return nullptr;
    }

    Node *temp2 = temp1->leftChild;

    // Rotation
    temp1->leftChild = original;
    original->rightChild = temp2;

    // Update heights
    original->depth = max(Height(original->leftChild), Height(original->rightChild)) + 1;
    temp1->depth = max(Height(original->leftChild), Height(original->rightChild)) + 1;

    // Update parents
    original->parent = temp1;
    temp2->parent = temp1;

    // Return new node pointer
    return temp1;
}
// right rotation
AVLTree::Node* AVLTree::RightRotation(Node *original)
{
    Node *temp1 = original->leftChild;

    if (temp1 == nullptr)
    {
        return nullptr;
    }

    Node *temp2 = temp1->rightChild;

    // Perform rotation
    temp1->rightChild = original;
    original->leftChild = temp2;

    // Update heights
    original->depth = max(original->leftChild->depth, original->rightChild->depth) + 1;
    temp1->depth = max(temp1->leftChild->depth, temp1->rightChild->depth) + 1;

    // Update parents
    original->parent = temp1;
    temp2->parent = temp1;

    // Return new node pointer
    return temp1;
}
// gets balance factor of a node
int AVLTree::getBalance(Node *node)
{
    if (node == nullptr || node->leftChild == nullptr || node->rightChild == nullptr) // if the node does not exist or it is missing a child
    {
        return 0; // no balance
    }

    return (Height(node->leftChild) - Height(node->rightChild)); // otherwise return balance factor
}
// goes to proper rotation function depending on balance
void AVLTree::pickRotation(int balance, Node* node)
{
    // Double Left Rotation
    if (balance > 1 && node->key < node->leftChild->key)
    {
        RightRotation(node);
    }

    // Double Right Rotation
    if (balance < -1 && node->key > node->rightChild->key)
    {
        LeftRotation(node);
    }

    // Left Right Rotation
    if (balance > 1 && node->key > node->leftChild->key)
    {
        node->leftChild = LeftRotation(node->leftChild);
        RightRotation(node);
    }

    // Right Left Rotation
    if (balance < -1 && node->key < node->rightChild->key)
    {
        node->rightChild = RightRotation(node->rightChild);
        LeftRotation(node);
    }
}
// finds all nodes in range and outputs their values in a vector
vector<string> AVLTree::findRange(int lowkey, int highkey)
{
    // empty container for use
    nodesInRange.clear();

    // Call helper function, as my solution uses recursion
    return findInRange(root, lowkey, highkey);
}
// Helper function for finding nodes in range
vector<string> AVLTree::findInRange(Node* root, int lowkey, int highkey)
{
    if (root != nullptr)
    {
        // If the range is less than the root, recursively call the left subtree
        if (lowkey < root->key)
        {
            findInRange(root->leftChild, lowkey, highkey);
        }

        // If the root is in the base range, add to vector
        if (lowkey <= root->key && highkey >= root->key)
        {
            nodesInRange.push_back(root->value);
        }

       // Recursively call right subtree
       findInRange(root->rightChild, lowkey, highkey);
    }

    return nodesInRange;
}
