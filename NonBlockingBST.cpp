/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NonBlockingBST.cpp
 * Author: devesh
 * 
 * Created on 14 April, 2016, 12:37 AM
 */

#include <atomic>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "BSTclass.h"

using namespace std;

bool NonBlockingBST::insert(int k)
{
  atomic<treeNode *> *p;
  treeNode *newInternal, *l, *newSibling, *newNode;
  atomic<updateRecord *> *pupdate;
  infoRecord * op;

  // Create new node containing k

  newNode = new treeNode(k, true);

  while(true) {
    searchResult * s = search(k);
    p = s->p;
    pupdate = &(s->pupdate);
    l = (treeNode *)s->l;

    // Cannot insert duplicate key
    if (l->data == k)
      return false;

    // Help the other operation
    if (pupdate->load()->isDirty)
      helpInsert(pupdate->load()->info);
    else {
      // pointer to a new Leaf whose key is l->key
      newSibling = new treeNode(l->data, true);

      bool newNodeIsSmaller = k < l->data;

      // pointer to a new internal node
      updateRecord * newInternalUpdate = new updateRecord();

      newInternal = new treeNode(max(k, l->data), true);
      if (newNodeIsSmaller) {
        newInternal->left.store(newNode);
        newInternal->right.store(newSibling);
      }
      else {
        newInternal->left.store(newSibling);
        newInternal->right.store(newNode);
      }
      newInternal->update.store(newInternalUpdate);
     
      // pointer to a new iinfo record containing <p, l, newInternal>
      op = new infoRecord(p->load(), l, newInternal);

      // attempt to cas for result
      updateRecord * ur = new updateRecord(true, op);

      // a pointer variable will store address and load retuns the value or pointer??
      updateRecord * pupdateVal = pupdate->load();

      bool casSuccess = (p->load()->update).
        compare_exchange_strong(pupdateVal, ur);
      if (casSuccess) {
        helpInsert(op);
      }
      else {
        helpInsert(pupdate->load()->info);
      } 
    }
  }
}

void NonBlockingBST::helpInsert(infoRecord* info)
{
  tnp *p = &(info->parent);
  treeNode * l = info->leaf.load();
  treeNode * s = info->subtree.load();

  updateRecord * oldUR = new updateRecord(true, info),
               * newUR = new updateRecord(false, info);

  CASChild(p, l, s); 
  info->parent.load()->update.
      compare_exchange_strong(oldUR, newUR);

/*	
	// a pointer variable will store address and load retuns the value or pointer??
	treeNode* l = info.load()->leaf.load();
	treeNode* sb = new treeNode;
	sb->left.store(info.load()->subtree.load()->left);
	sb->right.store(info.load()->subtree.load()->right);
	sb->update.store(info.load()->subtree.load()->update);
	sb->isLeaf = info.load()->subtree.load()->isLeaf;
	bool cassed = atomic_compare_exchange_strong
		&(info.load()->parent),
		&(l),
		sb);
*/
}

bool NonBlockingBST::CASChild(tnp *parent, treeNode *oldNode, treeNode *newNode)
{
  tnp *childToChange = (newNode->data < parent->load()->data)
    ? &(parent->load()->left)
    : &(parent->load()->right);
  
  return childToChange->compare_exchange_strong(oldNode, newNode);
}
