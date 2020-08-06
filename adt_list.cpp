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
        Node *last, *next;

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

    // Destructor
    ~List_stack();

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

// Destructor definition
List_stack::~List_stack()
{
    pop_all();
}

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
    {
        head = node;
    }
    else
    {
        node->set_previous(tail);
        tail->set_next(node);
    }
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
    if (node == nullptr)
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
    
    return popped;
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
    List_stack stack = List_stack();

    vector<string> rand_strings = {};

    unsigned int vals = 20;

    // test push vals amounts of values to stack
    cout << "Pushing " << vals << " values\n";
    for (unsigned int i = 0; i < vals; i++)
    {
        rand_strings.push_back(to_string( rand()%2000 )); // generate random strings of numbers
        cout << rand_strings[i] + "\n";
        stack.push(rand_strings[i]);
    }

    // check size
    if (stack.size() != vals)
    {
        cout << "Size method returned wrong size.\n";
        return 1;
    }
    

    // test pop vals amounts of items from the stack
    cout << "Popping " << vals << " values\n";
    for (int i = vals - 1; i >= 0; i--)
    {
        // verify the popped values
        if (stack.pop() != rand_strings[i])
        {
            cout << "Failed push and pop";
            return 1;
        }
    }

    cout << "Passed first push and pop\n";

    // push vals amounts of values altogether
    cout << "Bulk pushing " << vals << " values\n";
    for (unsigned int i = 0; i < vals; i++) // generate random strings of numbers
    {
        rand_strings[i] = to_string(rand() % 2000);
    }
    stack.push(rand_strings);

    // check size
    if (stack.size() != vals)
    {
        cout << "Size method returned wrong size.\n";
        return 1;
    }

    // pop vals amounts of values altogether
    cout << "Bulk Popping " << vals << " values\n";
    vector<string> popped = stack.pop(vals);
    for (int i = vals-1; i >= 0; i--)
    {
        // verify the popped values
        cout << popped[i] << " " << rand_strings[vals-i-1] << "\n";
        if (popped[i] != rand_strings[vals-i-1]) // prints the values if they arent verified
        {
            cout << "Failed push and pop\n";

            for (unsigned int i = 0; i < vals; i++)
                cout << "expected: " << rand_strings[vals-i-1] << " stored: " << popped[i] << "\n";

            return 1;
        }

    }

    // push new test

    stack.pop_all();

    unsigned int amount_vals = (rand() % 10) + 3;
    cout << "generating " << amount_vals << " unique values.\n";
    rand_strings.clear();
    for (unsigned int i = 0; i < amount_vals; i++)
    {
        bool pushed = false;
        while (!pushed) // ensure generated values are unique
        {
            bool exists = false;
            string rand_string = to_string(rand() % 2000); // generate random number string
            for (unsigned int j = 0; j < rand_strings.size() && !exists; j++)
            {
                if (rand_strings[j] == rand_string)
                {
                    exists = true;
                }
                
            }

            if (!exists)
            {
                rand_strings.push_back(rand_string);
                cout << "pushed unique value: " + rand_string + "\n";
                pushed = true;
            }

        }

    }

    cout << "generated " << rand_strings.size() << " values.\n";

    if (rand_strings.size() != amount_vals) // check for the number of generated values to be correct
    {
        cout << "not enough values were generated.\n";
        return 1;
    }
    
    // Push vals to expected and stack
    vector<string> pushed_vals;
    string rand_val;
    cout << "Pushing " << vals << " random values selected from unique generated values\n";
    for (unsigned int i = 0; i < vals; i++)
    {
        // push into stack
        rand_val = rand_strings[rand() % rand_strings.size()];
        cout << "stack and expected push_new: " << rand_val << "\n";
        stack.push_new(rand_val);

        // push into expected vector
        vector<string>::iterator iter = pushed_vals.begin();
        if (pushed_vals.size() > 0)
        {
            while (*iter != rand_val && iter != pushed_vals.end())
                advance(iter, 1);
        }
        
        if (iter == pushed_vals.end())
            pushed_vals.push_back(rand_val);
        
    }

    cout << "size of expected: " << pushed_vals.size() << "\n" << "expected values.\n";
    for (string c : pushed_vals)
        cout << c + "\n";

    cout << "size of stack: " << stack.size() << "\n";
    
    for (int i = pushed_vals.size() - 1; i >= 0 ; i--)
    {
        string popped_val = stack.pop();
        cout << "expected: " << pushed_vals[i] << " popped: " << popped_val << "\n";
        if (pushed_vals[i] != popped_val)
        {
            cout << "push new failed. vals dont match\n";
        }
        pushed_vals.pop_back();
    }
    

    cout << "All List_stack tests passed\n";
} // main
