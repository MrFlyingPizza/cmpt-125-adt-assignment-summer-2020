// adt_vec.cpp

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
// don't #include anything else!

using namespace std;

class Vec_stack : public Stack {
private:
    vector<string> strings;

public:
    // Default constructor
    Vec_stack() : strings{}
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

}; // class Vec_stack

bool Vec_stack::is_empty() const
{
    return strings.size() == 0;
}

// Pre-condition:
//    none
// Post-condition:
//    returns the number of elements in this stack
int Vec_stack::size() const
{
    return strings.size();
}

// Pre-condition:
//    none
// Post-condition:
//    puts x on the top of the stack
void Vec_stack::push(const string& x)
{
    strings.push_back(x);
}

// Pre-condition:
//    none
// Post-condition:
//    pushes all the elements of v onto the stack; first v[0] is pushed,
//    then v[1], etc.
void Vec_stack::push(const vector<string>& v)
{
    for (string item : v)
        push(item);
}

// Pre-condition:
//    none
// Post-condition:
//    if x occurs anywhere on the stack, then does nothing; otherwise,
//    pushes x onto the stack
void Vec_stack::push_new(const string& s)
{
    vector<string>::iterator iter = strings.begin();
    while (iter != strings.end() && *iter != s)
        advance(iter, 1);

    if (iter != strings.end())
        strings.push_back(s);
}

// Pre-condition:
//    !is_empty()
// Post-condition: 
//    removes and returns the top element of the stack
string Vec_stack::pop()
{
    string s = "";
    if (!is_empty())
    {
        s = strings.back();
        strings.pop_back();
    }
    return s;
}

// Pre-condition:
//    none
// Post-condition: 
//    if n <= 0, an empty vector is returned; otherwise, pops the first n items 
//    off the stack and returns them in a vector such that the first item of the vector
//    is the top of the stack, the second item of the vector is the second item of the
///   stack, and so on; if n > size(), then all items are popped and returned
vector<string> Vec_stack::pop(int n)
{
    if (n > strings.size())
        n = strings.size();

    vector<string> popped = {};
    for (int i = 0; i < n; i++)
        popped.push_back(pop());
    
    return popped;
}

// Pre-condition:
//    !is_empty()
// Post-condition: 
//    returns a copy of the top element of the stack (without removing it)
string Vec_stack::peek() const
{
    string s = "";
    if (!is_empty())
        strings.back();
    return s;
}

int main() {
    Vec_stack stack = Vec_stack();

    vector<string> rand_strings = {};

    unsigned int vals = 10;

    // test push vals amounts of values to stack
    cout << "Pushing " << vals << " values\n";
    for (unsigned int i = 0; i < vals; i++)
    {
        rand_strings.push_back(to_string( rand()%2000 )); // generate random strings of numbers
        cout << rand_strings[i] + "\n";
        stack.push(rand_strings[i]);
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

    cout << "All Vec_stack tests passed\n";
} // main
