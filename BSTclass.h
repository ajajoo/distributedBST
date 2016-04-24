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

    struct treeNode
    {
      int data;
      bool isLeaf;
      atomic<treeNode*> left;
      atomic<treeNode*> right;
      atomic<updateRecord*> update;

      treeNode(int d, bool b, treeNode *l = nullptr, treeNode *r = nullptr, 
               updateRecord *u = nullptr)
      : data(d), isLeaf(b)
      {
        left.store(l);
        right.store(r);
        u ? update.store(u) : update.store(new updateRecord());
      }
    };

    atomic<treeNode*> root;

    BST() {
      root.store(nullptr);
    };

    void print_preorder();
    void preorder(atomic<treeNode*>&);
    struct searchResult * search(int);
    void initializetree();

    struct infoRecord {
      atomic<treeNode*> parent;
      atomic<treeNode*> leaf;
      atomic<treeNode*> subtree;

      infoRecord(treeNode *p = nullptr, treeNode *l = nullptr, treeNode *s = nullptr)
      {
        parent.store(p);
        leaf.store(l);
        subtree.store(s);
      }
    };

    struct updateRecord {
      bool isDirty;
      infoRecord* info;

      updateRecord(bool b = false, infoRecord *i = nullptr)
      : isDirty(b), info(i) {}
    };
};

typedef atomic<BST::treeNode*> tnp;
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
    void helpInsert(infoRecord *);
    bool CASChild(tnp parent, treeNode *oldNode, treeNode *newNode);
  public:
    bool insert(int);
};
#endif /* CONST_H */

