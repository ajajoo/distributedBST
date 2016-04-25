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

void BST::initializetree(){
  tnp rootleft, rootright;
  rootleft.store(new treeNode(inf1, true));
  rootright.store(new treeNode(inf2, true));
  root.store(new treeNode(inf2, false, rootleft, rootright));
}

searchResult *
BST::search(int k)
{
  urp pupdate;
  tnp *p, *l = &root;
  pupdate.store(nullptr);
  do {
    p = l;
    pupdate.store(p->load()->update);

    if (k < l->load()->data){
      l = &(p->load()->left);
    }
    else {
      l = &(p->load()->right);
    }
  } while(l->load()->isLeaf != true);

  searchResult * s = new searchResult(p, pupdate, l);
  
  return s;
}

void BST::print_preorder()
{
  preorder((tnp&)root);
  cout << endl;
}

void BST::preorder(tnp &p)
{
  if(p.load() != nullptr)
  {
    if (p.load()->isLeaf)
      cout<<" "<<p.load()->data<<" ";
    if(p.load()->left.load())
      preorder(p.load()->left);
    if(p.load()->right.load())
      preorder(p.load()->right);
  }
  else return;
}

