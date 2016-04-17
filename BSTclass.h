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
#include <atomic>
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
      struct updateRecord;
      struct searchResult;

      struct tree_node
      {
        atomic<tree_node*> left;
        atomic<tree_node*> right;
        atomic<updateRecord*> update;
        atomic<bool> isLeaf;
        int data;
      };

      atomic<tree_node*> root;

      BST() {
        root.store(nullptr);
      };

      void print_preorder();
      void preorder(atomic<tree_node*>&);
      struct searchResult * search(int);
      void initializetree();

      struct infoRecord {
        atomic<tree_node*> parent;
        atomic<tree_node*> leaf;
        atomic<tree_node*> subtree;
      };
      struct updateRecord {
        atomic<bool> isDirty;
        atomic<infoRecord*> info;
      };
};

typedef atomic<BST::tree_node*> tnp;
typedef atomic<BST::updateRecord*> urp;
typedef atomic<BST::infoRecord*> irp;

typedef struct BST::searchResult {
  tnp p;
  urp pupdate;
  tnp l;
} searchResult;

class SequentialBST: public BST
{
    public:
      void insert(int);    
};

class NonBlockingBST: public BST
{
    private:
      void helpInsert(irp&);
    public:
      bool insert(int);
};
#endif /* CONST_H */

