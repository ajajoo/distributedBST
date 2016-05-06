# Non-blocking BST Implementation in C++

####Akshay Jajoo        [ajajoo@purdue.edu]
####Devesh Kumar Singh  [singh349@purdue.edu]
####Sergei Uversky      [suversky@purdue.edu]

### Overview

This is an attempt at a C++ implementation of a non-blocking binary search tree inspired by the algorithm and pseudocode given in the paper by Ellen et al[1].  For simplicity's sake, we are first focusing on tackling the `insert()` and `contains()` functions; time permitting, we will then attempt to tackle tree balancing followed by `remove()`.

We have included a reference sequential implementation in `SequentialBST.cpp` and a transactional-memory based implementation in `STMbst.cpp`.

### User notes

The code requires a more modern version of g++ than is available on most of the CS lab machines. The code was tested on the machine `mc18.cs.purdue.edu`, which has G++ v. 5.3.0. under `g++-5.3.0`.  The Makefile was set up to use this compiler if on `mc18` and to otherwise use `g++`; if testing on a personal machine, please ensure your g++ version is up-to-date to avoid spurious segmentation faults.

To compile the code, run the following command.

    $ make

A simple test of the implementation can be reached by typing

    $ ./BST test

This test contains examples of inserting into the tree and searching the tree.

Timing of concurrent insertions can be reached by typing

    $ ./BST time <numThreads> <iterations>

This will repeat a simple test <iterations> number of times: 

---

### References

[1] F. Ellen, P. Fatourou, E. Ruppert., and Van Breugel, F. Non-blocking binary search trees.  PODC (2010), 131-140
