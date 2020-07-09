## Abstract Data Type Assignment

Your task for this assignment is to create two different classes that
implement the `Stack` ADT in [Stack.h](Stack.h). **Important**: don't change
[Stack.h](Stack.h) in any way!

1. Call one of your implementation classes `Vec_stack`, and implement it using
   a `vector<string>`. [adt_vec.cpp](adt_vec.cpp) gives a starting template.
   **Don't** `#include` any other files.
   
   Make sure `Vec_stack` has a *default constructor* that makes an empty
   stack.

   In the `main` function, add automated testing that tests *every* method in
   `Vec_stack`. Do enough testing to ensure that your implementation is
   correct.

   **Source code readability matters!** We want to see perfect indentation and
   use of whitespace, sensibly chosen names, good use of appropriate C++
   features, and so on. Please follow coding style used in the notes and
   lectures.

2. Call your other implementation `List_stack`, and implement it using a
   linked list that you create by hand. [adt_list.cpp](adt_list.cpp) gives a
   starting template. **Don't** `#include` any other files.

   `List_stack` should have a default constructor that makes an empty stack.

   In the `main` function, add automated testing that tests *every* method in
   `List_stack`. Do enough testing to ensure that your implementation is
   correct.

   **Source code readability matters!** We want to see perfect indentation and
   use of whitespace, sensibly chosen names, good use of appropriate C++
   features, and so on. Please follow coding style used in the notes and
   lectures.

3. Suppose you want to create function that tests if two stacks are the same
   (i.e. have the elements in the same order) using a function with this
   header:

   ```cpp
   bool operator==(const Stack& a, const Stack& b)
   ```

   Is it possible to implement this `operator==` without changing the types of
   its parameters? If so, give an implementation of `operator==` that works
   correctly. If not, explain *exactly* how you would modify `Stack` to make
   this work efficiently.

   Write your answer for this question in a text file named
   [equality.txt](equality.txt). Spelling, grammar, and formatting matter!


### What to Submit

When you are done, compress [adt_vec.cpp](adt_vec.cpp),
[adt_list.cpp](adt_list.cpp), and [equality.txt](equality.txt) into a zip
archive named `adt.zip`. Include just those two files, and nothing else! Do
*not* put `Stack.h` in this zip file.

Submit `adt.zip` on Canvas when you're done.

Note that if your program does not compile, you will get 0 for the entire
assignment.
