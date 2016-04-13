
//Binary Search Tree Program

#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
    
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
       
        bool isEmpty() const { return root==NULL; }
        void print_preorder();
        void preorder(tree_node*);
        void insert(int);
        bool search(int);
};

void BinarySearchTree::insert(int d)
{
    
    if(search(d)){
        return;
    }
    
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    
    if(isEmpty()) root = t;
    else
    {
        tree_node* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(t->data > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        if(t->data < parent->data)
           parent->left = t;
        else
           parent->right = t;
    }
}

bool BinarySearchTree::search(int d)
{
    bool found = false;
    
    tree_node* curr;
    tree_node* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    return found;

}

void BinarySearchTree::print_preorder()
{
    preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

int main()
{
    BinarySearchTree b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(2);
    b.insert(8);
    b.insert(8);
    b.search(11);
    b.print_preorder();
}