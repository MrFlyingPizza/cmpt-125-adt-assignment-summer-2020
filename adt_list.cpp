// adt_list.cpp

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
// don't #include anything else!

using namespace std;

class List_stack : public Stack {
private:

    class Node
    {
    private:
        string data;
        Node *next, *last;

    public:
        Node(string value)
        : data(value), last(nullptr), next(nullptr)
        { }

        Node(string value, Node* last_node, Node* next_node) 
        : data(value), last(last_node), next(next_node)
        { }

        string get_data() const
        {
            return data;
        }

        Node* get_next() const
        {
            return next;
        }

        Node* get_previous() const
        {
            return last;
        }

        void set_data(const string value)
        {
            this->data = value;
        }

        void set_next(Node* next)
        {
            this->next = next;
        }

        void set_previous(Node* last)
        {
            this->last = last;
        }
    };

    Node *head, *tail;
    unsigned int count;

public:

    // Default constructor
    List_stack()
    : head(nullptr), tail(nullptr), count(0)
    { }

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if the stack is empty, and false otherwise
    bool is_empty() const;

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of elements in this stack
    int size() const;

    // Pre-condition:
    //    none
    // Post-condition:
    //    puts x on the top of the stack
    void push(const string& x);

    // Pre-condition:
    //    none
    // Post-condition:
    //    pushes all the elements of v onto the stack; first v[0] is pushed,
    //    then v[1], etc.
    void push(const vector<string>& v);

    // Pre-condition:
    //    none
    // Post-condition:
    //    if x occurs anywhere on the stack, then does nothing; otherwise,
    //    pushes x onto the stack
    void push_new(const string& s);

    // Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //    removes and returns the top element of the stack
    string pop();

    // Pre-condition:
    //    none
    // Post-condition: 
    //    if n <= 0, an empty vector is returned; otherwise, pops the first n items 
    //    off the stack and returns them in a vector such that the first item of the vector
    //    is the top of the stack, the second item of the vector is the second item of the
    ///   stack, and so on; if n > size(), then all items are popped and returned
    vector<string> pop(int n);

    // Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //    returns a copy of the top element of the stack (without removing it)
    string peek() const;

}; // class List_stack

bool List_stack::is_empty() const
{
    return count == 0;
}

// Pre-condition:
//    none
// Post-condition:
//    returns the number of elements in this stack
int List_stack::size() const
{
    return count;
}

// Pre-condition:
//    none
// Post-condition:
//    puts x on the top of the stack
void List_stack::push(const string& x)
{
    Node *node = new Node(x);
    if (count == 0)
        head = node;
    else
        node->set_previous(tail);
        tail->set_next(node);
    tail = node;
    count++;
}

// Pre-condition:
//    none
// Post-condition:
//    pushes all the elements of v onto the stack; first v[0] is pushed,
//    then v[1], etc.
void List_stack::push(const vector<string>& v)
{
    for (string item : v)
        push(item);
}

// Pre-condition:
//    none
// Post-condition:
//    if x occurs anywhere on the stack, then does nothing; otherwise,
//    pushes x onto the stack
void List_stack::push_new(const string& s)
{
    Node* node = head;
    while (node != nullptr && node->get_data() != s)
        node = node->get_next();
    if (node = nullptr)
        push(s);
}

// Pre-condition:
//    !is_empty()
// Post-condition: 
//    removes and returns the top element of the stack
string List_stack::pop()
{
    string data = "";
    if (!is_empty())
    {
        Node* node = tail;
        tail = node->get_previous();
        if (tail == nullptr)
            head = nullptr;
        else
            tail->set_next(nullptr);
        
        data = node->get_data();
        delete node;

        count--;
    }

    return data;
}

// Pre-condition:
//    none
// Post-condition: 
//    if n <= 0, an empty vector is returned; otherwise, pops the first n items 
//    off the stack and returns them in a vector such that the first item of the vector
//    is the top of the stack, the second item of the vector is the second item of the
///   stack, and so on; if n > size(), then all items are popped and returned
vector<string> List_stack::pop(int n)
{
    vector<string> popped = {};
    if (n > count)
        n = count;
    
    for (int i = 0; i < n; i++)
        popped.push_back(pop());
}


// Pre-condition:
//    !is_empty()
// Post-condition: 
//    returns a copy of the top element of the stack (without removing it)
string List_stack::peek() const
{
    string data = "";
    if (!is_empty())
        data = tail->get_data();
        
    return data;
}


int main() {
    // ... put testing for List_stack here ...

    cout << "All List_stack tests passed\n";
} // main
