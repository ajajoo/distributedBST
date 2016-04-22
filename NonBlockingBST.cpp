g*
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
  tnp p, newInternal, l, newSibling, newNode;
  urp pupdate, result, tmpUpdate;
  irp op;

  // Create new node containing k
  newNode.store(new tree_node);
  newNode.load()->data = k;
  newNode.load()->left.store(nullptr);
  newNode.load()->right.store(nullptr);
  newNode.load()->update.store(nullptr);
  newNode.load()->isLeaf.store(true);

  while(true) {
    searchResult * s = search(k);
    p.store(s->p);   
    pupdate.store(s->pupdate);   
    l.store(s->l);

    // Cannot insert duplicate key
    if (l.load()->data == k)
      return false;

    // Help the other operation
    if (pupdate.load()->isDirty.load())
      helpInsert(pupdate.load()->info);
    else {
      // pointer to a new Leaf whose key is l->key
      newSibling.store(new tree_node);
      newSibling.load()->data = l.load()->data;
      newSibling.load()->left.store(nullptr);
      newSibling.load()->right.store(nullptr);
      newSibling.load()->update.store(nullptr);
      newSibling.load()->isLeaf.store(true);

      bool newNodeIsSmaller = k < l.load()->data;

      // pointer to a new internal node
      updateRecord * newInternalUpdate = new updateRecord;
      newInternalUpdate->isDirty.store(false);
      newInternalUpdate->info.store(nullptr);

      newInternal.store(new tree_node);
      newInternal.load()->data = max(k, l.load()->data);
      if (newNodeIsSmaller) {
        newInternal.load()->left.store(newNode.load());
        newInternal.load()->right.store(newSibling.load());
      }
      else {
        newInternal.load()->left.store(newSibling.load());
        newInternal.load()->right.store(newNode.load());
      }
      newInternal.load()->update.store(newInternalUpdate);
      newInternal.load()->isLeaf.store(false);
     
      // pointer to a new iinfo record containing <p, l, newInternal>
      infoRecord * newInfo = new infoRecord;
      newInfo->parent.store(p.load());
      newInfo->leaf.store(l.load());
      newInfo->subtree.store(newInternal.load());
      op.store(newInfo);

      // attempt to cas for result
      updateRecord * ur = new updateRecord;
      ur->isDirty.store(true);
      ur->info.store(op.load());

	// a pointer variable will store address and load retuns the value or pointer??
	updateRecord * pupdateVal = pupdate.load();

      bool casSuccess =
        atomic_compare_exchange_strong(
          &(p.load()->update),
          &(pupdateVal),
          ur
        );
      if (casSuccess) {
        helpInsert(op);
      }
      else {
        helpInsert(pupdate.load()->info);
      } 
    }
  }
}

void NonBlockingBST::helpInsert(irp& info)
{
	
	// a pointer variable will store address and load retuns the value or pointer??
	tree_node* l = info.load()->leaf.load();
	tree_node* sb = new tree_node;
	sb->left.store(info.load()->subtree.load()->left);
	sb->right.store(info.load()->subtree.load()->right);
	sb->update.store(info.load()->subtree.load()->update);
	sb->isLeaf.store(info.load()->subtree.load()->isLeaf);
	bool cassed = atomic_compare_exchange_strong(
		&(info.load()->parent),
		&(l),
		sb);
}
