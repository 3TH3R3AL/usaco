j# NV Chad notes
- Toggle FE = Ctrl N
- a to create new file while in nvtree
- Enter to open file while in nvtree
- Ctrl w to change windows
- Tab to change files/tab things (but not actually tabs)
- SPACE x to close buffer (tab but not tab :) ) 


## GDB Notes
- Run with `gdb binary`
- set breakpoint with `b [Line Number]`, so `b 49`
- start program with `run`
- Have to compile like `g++ -g input.cpp -o output` in order to use gdb
- step with `step` or shortened, `s`
- step over function with `next` or `n`


## C++ Notes:
- You can do something similiar to pythons `for item in list` via `for (std:string& str : strList)` where std:string is the type, & means to use a reference, str is the temporary variable, and strList is the iterable. 
- std:vector from <vector> are like pseudo-dynamic arrays that are handled automatically.
- need to use long long, because long is weird. 
- `push_back` to append to end of vector
- You can use std:sort from the <algorithm> libary to sort vectors.
- You can init an array to 0 like this int array[10] = {}; but if the array is variable sized you have to do this: int *array = new int[size]();
- Global arrs are auto initialized to 0


## General notes
- When dealing with pairs, probably use an array with partner[i] = j and partner[j] = i;
Handy Bitwise stuff:

 It turns out that the way 2's complement machines represent integers and the way they implement subtraction (the standard on virtually all modern machines) yields some very interesting possibilities for bit manipulation.

Two's complement machines represent positive integers as the binary representation of that integer with a 0 in the sign bit. A negative integer is represented as the complement of the positive integer (including turning on the sign bit) plus 1. Thus, the absolute value of the most negative representable integer is one more than the most positive representable integer. Thus:

   x    +x in 8-bit binary    -x in 8-bit binary
   0        0000 0000              0000 0000
   1        0000 0001              1111 1111
   2        0000 0010              1111 1110
   3        0000 0011              1111 1101
  64        0100 0000              1100 0000
  65        0100 0001              1011 1111              
 126        0111 1110              1000 0010 
 127        0111 1111              1000 0001 
 128    [no representation]        1000 0000

Given this representation, addition can proceed just as on pencil and paper, discard any extra high order bits that exceed the length of the representation. Subtracting b from a (a-b) proceeds as add a and the quantity (-b).

This means that certain bit operations can exploit these definitions of negation and subtraction to yield interesting results, the proofs of which are left to the reader (see a table of these offsite):

             Binary
Value        Sample             Meaning
  x         00101100        the original x value
x & -x      00000100        extract lowest bit set
x | -x      11111100        create mask for lowest-set-bit & bits to its left
x ^ -x      11111000        create mask bits to left of lowest bit set
x & (x-1)   00101000        strip off lowest bit set
                            --> useful to process words in O(bits set)
                                instead of O(nbits in a word)
x | (x-1)   00101111        fill in all bits below lowest bit set
x ^ (x-1)   00000111        create mask for lowest-set-bit & bits to its right
~x & (x-1)  00000011        create mask for bits to right of lowest bit set
x | (x+1)   00101101        toggle lowest zero bit
x / (x&-x)  00001011        shift number right so lowest set bit is at bit 0


