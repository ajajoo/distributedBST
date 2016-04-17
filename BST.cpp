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
 
    tree_node* t = new tree_node;
    tree_node* rootleft = new tree_node;
    tree_node* rootright = new tree_node;
    
    rootleft->data = inf1;
    rootleft->left = NULL;
    rootleft->right = NULL;
    rootleft->isLeaf = true;
    
    rootright->data = inf2;
    rootright->left = NULL;
    rootright->right = NULL;
    rootright->isLeaf = true;
    
    t->data = inf2;
    t->left = rootleft;
    t->right = rootright;
    t->isLeaf = false;
   
    root = t;
}

vector<tnp> BST::search(int k)
{
    vector<tnp> vec;
    tnp gp = NULL;
    tnp p = NULL;
    tnp l = root;
    do{
        gp = p;
        p = l;
        if (k<l->data){
            l = p->left;
        }
        else{
            l = p->right;
        }
    }while(l->isLeaf != true);  
    vec.push_back(gp);
    vec.push_back(p);
    vec.push_back(l);
    return vec;
}

void BST::print_preorder()
{
    preorder(root);
}

void BST::preorder(tree_node* p)
{
    if(p != NULL)
    {
        if (p->isLeaf)
            cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

