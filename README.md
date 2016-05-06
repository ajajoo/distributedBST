# Non-blocking BST Implementation in C++

####Akshay Jajoo        [ajajoo@purdue.edu]
####Devesh Kumar Singh  [singh349@purdue.edu]
####Sergei Uversky      [suversky@purdue.edu]

### Overview

This is an attempt at a C++ implementation of a non-blocking binary search tree inspired by the algorithm and pseudocode given in the paper by Ellen et al[1].  For simplicity's sake, we are first focusing on tackling the `insert()` and `contains()` functions; time permitting, we will then attempt to tackle tree balancing followed by `remove()`.

We have included a reference sequential implementation in `SequentialBST.cpp` and a transactional-memory based implementation in `STMbst.cpp`.

### User notes

The code requires a more modern version of G++ than is available on most of the CS lab machines. The code was tested on the machine `mc18.cs.purdue.edu`, which has G++ v. 5.3.0. under `g++-5.3.0`.  If running on a personal machine with an up-to-date G++ version installed, please replace the CXX variable in the makefile with `CXX=g++`.

### Sequential implementation

To run the sequential leaf oriented BST code, run the following commands:

    $ make
    $ ./main

`main` contains examples of calling `insert`, `search` and printing the tree in a pre-order fashion.

---

### References

[1] F. Ellen, P. Fatourou, E. Ruppert., and Van Breugel, F. Non-blocking binary search trees.  PODC (2010), 131-140
