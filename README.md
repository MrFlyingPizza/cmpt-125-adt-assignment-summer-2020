## Abstract Data Type Assignment

Your task for this assignment is to create two classes that implement the
`Stack` class in [Stack.h](Stack.h). **Important**: don't change
[Stack.h](Stack.h) in any way!

1. One of your implementations should be called `Vec_stack`, and it should be
   implemented using a `vector<string>`. Put that class into the file
   [adt_vec.cpp](adt_vec.cpp). `Vec_stack` should have a default constructor
   that makes an empty stack.

   In the `main` function, add automated testing that tests *every* method in
   `Vec_stack`. Do enough testing to ensure that your implementation is
   correct.

2. Your other implementation should be called `List_stack`, and it should be
   implemented using a linked list that you create by hand. Put that class
   into the file [adt_list.cpp](adt_list.cpp). `List_stack` should have a
   default constructor that makes an empty stack.

   In the `main` function, add automated testing that tests *every* method in
   `List_stack`. Do enough testing to ensure that your implementation is
   correct.

3. Suppose you want to create function that tests if two stacks are the same
   (i.e. have the elements in the same order) using a function with this
   header:

   ```cpp
   bool operator==(const Stack& a, const Stack& b)
   ```

   Is it possible to implement this `operator==` without changing the types of
   the parameters? If so, give an implementation of `operator==` that works
   correctly. If not, explain how you would modify `Stack` to make this work.

   Write your answer for this question in a text file named
   [equality.txt](equality.txt).


### What to Submit

When you are done, compress [adt_vec.cpp](adt_vec.cpp),
[adt_list.cpp](adt_list.cpp), and [equality.txt](equality.txt) into a zip
archive named `adt.zip`. Include just those two files, and nothing else! Do
*not* put `Stack.h` in this zip file.

Submit `adt.zip` on Canvas when you're done.

