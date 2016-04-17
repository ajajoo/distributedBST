
//Binary Search Tree Program

#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <algorithm>
#include "BSTclass.h"
using namespace std;

void SequentialBST::insert(int k)
{
    searchResult * s = search(k);
    tnp newinternal;
    newinternal.store(s->l);
    if(newinternal.load()->data == k){
        return;
    }
    tnp newnode;
    newnode.store(new tree_node);
    newnode.load()->data = k;
    newnode.load()->left.store(nullptr);
    newnode.load()->right.store(nullptr);
    newnode.load()->isLeaf.store(true);
   
    tnp newsibling;
    newsibling.store(new tree_node);
    newsibling.load()->data = newinternal.load()->data;
    newsibling.load()->left.store(nullptr);
    newsibling.load()->right.store(nullptr);
    newsibling.load()->isLeaf.store(true);
    
    newinternal.load()->data = max(k,newinternal.load()->data);
    newinternal.load()->isLeaf.store(false);
    if(k < newinternal.load()->data){
        newinternal.load()->left.store(newnode);
        newinternal.load()->right.store(newsibling);
    }
    else{
        newinternal.load()->left.store(newsibling);
        newinternal.load()->right.store(newnode);
    }
}

