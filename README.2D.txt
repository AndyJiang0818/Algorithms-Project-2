// Xihao Jiang
// Homework 2

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