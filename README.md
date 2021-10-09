# The Big Five

## Overview
Create and test a class called Points2D. This class describes a sequence of 2D points (i.e. points
in the 2D-plane). For example (1, 3), (4, 5) is a sequence of two points, where each coordinate is
an integer. (1.2, 3.4), (5.6, 10.1), (11.1, 12.0) is a sequence of three points where each
coordinate is a double. A sequence can have any size. An empty sequence has size 0.

The private data members should be:
 size_t size; std::array<Object, 2> *sequence_;

Object is the template type parameter (i.e. int, double, etc.). An initial piece of code with the
structure of the class is provided. Do not change the data representation (for instance do not use a
vector or list to represent the sequence_).

## Thoughts
Within the big-five, set the size of the zero-parameter constructor to zero, and the sequence as nullpointer. 
For the copy-constructor, copy the array and size, return if copy file is a nullpointer, 
then return Points2D object with copied value. 
Finished the copy-assignment by following the instruction. 
Completed the move-constructor by setting its sequence and size. 
Utilized std::swap() for the move-assignment.
Added a destructor to delete allocated space for the array by setting the size to 0 and the pointer to null.

Out of the big-five, took in the array item for the one parameter constructor. 
Allocated the space as the size of the array-1 and copied the value in the array item. 
Inside the "void ReadPoints2D()" method, made the method only read once, 
set the size to the size of the sequence, and allocate the space for the sequence. 
Set abort() correctly, absort if the sequence does not exist. 
For the two sequences, brute force the way to append two array object. 
Took the larger size and allocate space for that size of one object size is greater than the other one. 
Got the sum from common size by using the smaller size, 
then starting from the smaller size and append the rest of the array object. 
In order to overload the << operator, print out an empty parentheses if the size is 0,
and use a for loop for any other size object. 

Also, added two private variables, row and column for ReadPoints2D function utilized stl array for this program. 

## Run
- To compile on terminal type:
1. make clean
2. make all

- To delete executables and object file type:
1. make clean

- To run:
1. ./test_points2d

- To run with a given file that is redirected to standard input:
1. ./test_points2d < test_input_file.txt
