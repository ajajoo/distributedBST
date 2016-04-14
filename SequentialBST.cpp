
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
    vector<tnp> vec = search(k);
    tnp newinternal = vec[2];
    if(newinternal->data == k){
        return;
    }
    tnp newnode = new tree_node;
    newnode->data = k;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->isLeaf = true;
   
    tnp newsibling = new tree_node;
    newsibling->data = newinternal->data;
    newsibling->left = NULL;
    newsibling->right = NULL;
    newsibling->isLeaf = true;
    
    newinternal->data = max(k,newinternal->data);
    newinternal->isLeaf = false;
    if(k<newinternal->data){
        newinternal->left = newnode;
        newinternal->right = newsibling;
    }
    else{
        newinternal->left = newsibling;
        newinternal->right = newnode;
    }
}

