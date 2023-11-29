#include <string>
#include <vector>

using namespace std;

class AVLTree
{
    public:
        AVLTree();
        ~AVLTree();
        // Node manipulation tools
        bool insert(int key, string value);
        bool find(int key, string& value);
        // Internal retrieval functions
        int getHeight(); // Function that gets the height of the entire tree
        int getSize(); // Function that gets number of nodes in tree
        vector<string> findRange(int lowkey, int highkey);
        // Operator Overrides
        friend ostream& operator<<(ostream& os, const AVLTree& me);
        AVLTree& operator=(const AVLTree& me);

    private:
        // Class definitions for nodes
        class Node {

            public:
                // Variable declarations
                int key;
                string value = "";
                int depth;
                Node *parent;
                Node *leftChild;
                Node *rightChild;

                // No-Arg constructor
                Node() {
                    parent = nullptr;
                    leftChild = nullptr;
                    rightChild = nullptr;
                }

                // Arg Constructor
                Node(int key_, string value_)
                {
                    key = key_;
                    value = value_;
                    depth = 1;
                    parent = nullptr;
                    leftChild = nullptr;
                    rightChild = nullptr;
                }

                // Deconstructor
                ~Node() {};
        };

        // Internal use functions
        Node* RightRotation(Node *); // Performs right rotations
        Node* LeftRotation(Node *); // Performs left rotations
        int getBalance(Node *); // Function to get balance factor of a particular node

        // Pointer Definition
        Node* root;
};
