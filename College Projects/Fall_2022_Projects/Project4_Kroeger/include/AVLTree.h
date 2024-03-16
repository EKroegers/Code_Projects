#include <string>
#include <vector>

using namespace std;
static int nodeCount = 0; // for use in getSize() helper function
static vector<string> nodesInRange = {}; // for use in findRange helper function
static string tree = "";

class AVLTree
{
    public:
        AVLTree();
        AVLTree(const AVLTree&);
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
                    depth = 0;
                }

                // Arg Constructor
                Node(int key_, string value_)
                {
                    key = key_;
                    value = value_;
                    depth = 0;
                    parent = nullptr;
                    leftChild = nullptr;
                    rightChild = nullptr;
                }

                // Full Constructor
                Node(int key_, string value_, Node* parent_, Node* leftChild_, Node* rightChild_, int depth_)
                {
                    key = key_;
                    value = value_;
                    depth = depth_;
                    parent = parent_;
                    leftChild = leftChild_;
                    rightChild = rightChild_;
                }

                // Deconstructor
                ~Node() {};
        };

        // Internal use functions
        Node* RightRotation(Node *); // Performs right rotations
        Node* LeftRotation(Node *); // Performs left rotations
        int getBalance(Node *); // Function to get balance factor of a particular node

        // Helper functions
        int getNodeCount(Node* root); // For use in getSize()
        void printPreorder(Node* root); // For use in cout override
        int Height(Node* node); // For use in getHeight() and rotation
        void pickRotation(int balance, Node* node); // For use in rotation
        int updateDepth(Node* node); // For use in rotation
        static AVLTree::Node* copyNodes(Node* node); // for use with = operator and copy constructor
        vector<string> findInRange(Node* root, int lowkey, int highkey); // For use in findrange

        // Pointer Definition
        Node* root;
};
