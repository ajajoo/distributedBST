/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BST.cpp
 * Author: devesh
 * 
 * Created on 14 April, 2016, 12:36 AM
 */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <algorithm>
#include "BSTclass.h"

using namespace std;

searchResult *
BST::search(int k)
{
  treeNode *p, *l = root.load();
  updateRecord pupdate;
  do {
    p = l;
    pupdate = l->update.load();

    if (k < l->data){
      l = p->left.load();
    }
    else {
      l = p->left.load();
    }
  } while(!(l->isLeaf));

  return new searchResult(p, l, pupdate);
}

void BST::print_preorder()
{
  preorder(root.load());
  cout << endl;
}

void BST::preorder(treeNode *p)
{
  if(!p) return;

  if (p->isLeaf)
    cout << " " << p->data << " ";
  else {
    treeNode *l = p->left.load(),
             *r = p->right.load(); 
    if(l) preorder(l);
    if(r) preorder(r);
  }
}

