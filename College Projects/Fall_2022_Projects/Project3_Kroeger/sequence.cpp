#include "Sequence.h"
#include <exception>

Sequence::Sequence( size_type sz )
{
    // Loop and allow push_back to assign head and tail
    for (int i = 0; i < sz; i++)
    {
        push_back(0);
    }

    // Set numElts
    numElts = sz;
}

// Constructor
Sequence::Sequence( const Sequence& s )
{
    // Copy constant input for manipulation
    Sequence sequenceCopy = s;

    // Set Heads and Tails
    head = sequenceCopy.head;
    tail = sequenceCopy.tail;

    // Set number of elements
    numElts = sequenceCopy.numElts;

    // Loop and allow insert to fill
    for (int i = 0; i < sequenceCopy.numElts; i++)
    {
        insert(i, sequenceCopy[i]);
    }
}

// Destructor
Sequence::~Sequence()
{
    delete this;
}

// Creates copy of Sequence s
Sequence& Sequence::operator=( const Sequence& s )
{
    // Copy constant input for manipulation
    Sequence sequenceCopy = s;
    Sequence *outputSequence = new Sequence();

    // Set Heads and Tails
    outputSequence->head = sequenceCopy.head;
    outputSequence->tail = sequenceCopy.tail;

    // Set number of elements
    outputSequence->numElts = sequenceCopy.numElts;

    // Loop and allow insert to fill
    for (int i = 0; i < sequenceCopy.numElts; i++)
    {
        outputSequence->insert(i, sequenceCopy[i]);
    }

    return *outputSequence;
}

// Returns value of SequenceNode at Index position
Sequence::value_type& Sequence::operator[]( size_type position )
{
    // Allocate node for current position
    Sequence::SequenceNode *current = head;

    // Check if we're being asked for the head or tail
    if (position == 0)
    {
        return head->elt;
    }
    else if (position == numElts - 1)
    {
        return tail->elt;
    }
    else if (position > 0 && position < numElts - 1) // Go through the list to find it
    {
        for (int i = 0; i < position - 1; i++)
        {
            // Loop until position index is reached
            current = current->next;
        }

        return current->elt;
    }
    else // index out of bounds
    {
        throw std::invalid_argument( "invalid index" );
    }
}

// Puts a new Sequence Node at the end of the Sequence with the Value value
void Sequence::push_back( const value_type& value )
{
    // Create pointer for the new tail
    Sequence::SequenceNode *new_node = new SequenceNode();
    // Populate new node's value
    new_node->elt = value;
    new_node->next = nullptr;

    if (empty()) // if it is an empty list
    {
        head = new_node;
        tail = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }
    else // if the list is already populated
    {
        // Set prev and next values for new tail
        tail->next = new_node;
        new_node->prev = tail;

        // Set new tail value
        tail = new_node;
    }
}

// Remove the tail Sequence Node of the Sequence
void Sequence::pop_back()
{
    // Set new tail
    this->tail = this->tail->prev;
    // Remove previous tail
    this->tail->next = nullptr;
}

// Insert a new Sequence Node at Index position with Value value
void Sequence::insert( size_type position, value_type value )
{
    if (!empty() || position < 0 || position >= numElts)
    {
        // Allocate new node
        Sequence::SequenceNode *new_node = new SequenceNode();

        // Populate new node's value
        new_node->elt = value;

        // Allocate node for current position
        Sequence::SequenceNode *current = head;

        for (int i = 0; i < position; i++)
        {
            // Loop until position before index is reached
            current = current->next;
        }
        // Push forward the reference to next
        new_node->next = current->next;

        // Fix the next of the previous node
        current->next = new_node;

        // Make the prev of the new node the previous node
        new_node->prev = current;

        // Fix the prev of the next node if it exists
        if (new_node->next != nullptr)
        {
            new_node->next->prev = new_node;
        }
    }
    else
    {
        throw std::invalid_argument( "invalid index" );
        return;
    }
}

// Return the value of the head node
const Sequence::value_type& Sequence::front() const
{
    if (!this->empty())
    {
        return head->elt;
    }
    else
    {
        throw std::invalid_argument( "sequence empty" );
        return NULL;
    }
}

// Return the value of the tail node
const Sequence::value_type& Sequence::back() const
{
    if (!empty())
    {
        return tail->elt;
    }
    else
    {
        throw std::invalid_argument( "sequence empty" );
        return NULL;
    }
}

// Return true if the list is empty
bool Sequence::empty() const
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Return the number of elements in the list
Sequence::size_type Sequence::size() const
{
    if (empty())
    {
        throw std::invalid_argument( "sequence empty" );
        return 0;
    }
    else
    {
        return numElts;
    }
}

// Remove all elements from the list
void Sequence::clear()
{
    for (int i = 0; i < size(); i++)
    {
        pop_back();
    }
}

// Remove a number of given elements starting from a given index
void Sequence::erase( size_type position, size_type count )
{
    Sequence::SequenceNode *current = head;

    if (position >= 0 && position + count - 1 <= size())
    {
        // Find the index of position
        for (int i = 0; i < position; i++)
        {
            // Loop until position index is reached
            current = current->next;
        }

        // Pop each node in sequence
        for (int i = 0; i < count; i++)
        {
            // Move pointer of current next to the item after
            current->next = current->next->next;

            // Move the prev pointer of next item to current
            current->next->prev = current;

            // Iterate current forward
            current = current->next;
        }
    }
    else
    {
        throw std::invalid_argument( "received invalid index" );
        return;
    }
}

ostream& operator<<( ostream& os, Sequence& s )
{
    // Define strings for manipulation
    string tempString = "";
    string outputString = ( "< " + std::to_string(s.front()) + ", ");

    // Append values of all the nodes besides head and tail
    for (int i = 1; i < s.size() - 1; i++)
    {
        tempString = std::to_string(s[i]);
        outputString.append(tempString);
        outputString.append(", ");
    }
    outputString.append(std::to_string(s.back()) + " >");

    os  << outputString << endl;

    return os;
}
