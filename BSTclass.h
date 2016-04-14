/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   const.h
 * Author: devesh
 *
 * Created on 13 April, 2016, 7:37 PM
 */
#include <climits>
#include <vector>

#ifndef CONST_H
#define CONST_H

const int inf1 = INT_MAX-1;
const int inf2 = INT_MAX;

using namespace std;

class BST
{
    public:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           bool isLeaf;
           int data;
        };
        tree_node* root;
            
        BST()
        {
           root = NULL;
        }
       
        void print_preorder();
        void preorder(tree_node*);
        vector<tree_node*> search(int);
        void initializetree();
};

typedef BST::tree_node* tnp;

class SequentialBST: public BST{
    
    public:
        void insert(int);    
    
};

class NonBlockingBST: public BST{
    
};
#endif /* CONST_H */

