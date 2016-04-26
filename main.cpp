/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: devesh
 *
 * Created on 14 April, 2016, 12:53 AM
 */

#include <cassert>
#include <iostream>
#include "BSTclass.h"
using namespace std;

/*
 * 
 */

void testSearch(BST *b, int val, bool expected)
{
  cout << "  Looking for " << val << "." << endl;
  cout << "  (Expected to " << (expected ? "" : "not ") << "be in the tree.)" << endl;
  searchResult * res = b->search(val);
  assert((res->l.load()->data == val) == expected);
  cout << "  " << val << (expected ? " found." : " not found.") << endl << endl;
}

void populateSeqTree(SequentialBST *b)
{
  int vals[6] = {6, 10, 7, 9, 14, 3};
  for (int i = 0; i < 6; i++) {
    b->insert(vals[i]);
    cout << "  Inserted " << vals[i] << endl;
  }
}

void populateNBTree(NonBlockingBST *b)
{
  int vals[6] = {6, 10, 7, 9, 14, 3};
  for (int i = 0; i < 6; i++) {
    b->insert(vals[i]);
    cout << "  Inserted " << vals[i] << endl;
  }
}

void testSequential()
{
  cout << "Testing sequential implementation." << endl;
  cout << "----------------------------------" << endl;
  cout << "Initializing new tree." << endl;
  SequentialBST b;
  b.print_preorder();
  testSearch(&b, INT_MAX, true);
  cout << "Populating tree." << endl;
  populateSeqTree(&b);
  cout << "Testing search." << endl;
  testSearch(&b, 9, true);
  testSearch(&b, 16, false);
  b.print_preorder();
  cout << endl;
}

void testNonblocking()
{
  cout << "Testing nonblocking implementation." << endl;
  cout << "-----------------------------------" << endl;
  cout << "Initializing new tree." << endl;
  NonBlockingBST b;
  b.print_preorder();
  cout << "Testing nonblocking implementation." << endl;
  testSearch(&b, INT_MAX, true);
  cout << "Populating tree." << endl;
  populateNBTree(&b);
  cout << "Testing search." << endl;
  testSearch(&b, 9, true);
  testSearch(&b, 16, false);
  b.print_preorder();
  cout << endl;
}

int main() {
  testSequential();
  testNonblocking();
}

