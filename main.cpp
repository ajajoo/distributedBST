/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: devesh
 *
 * Created on 14 April, 2016, 12:53 AM
 */

#include <iostream>
#include "BSTclass.h"
using namespace std;

/*
 * 
 */
int main() {

    SequentialBST b;
    b.initializetree();
    vector<tnp> vec = b.search(INT_MAX);
    b.insert(6);
    b.insert(10);
    b.insert(7);
    b.insert(9);
    b.insert(14);
    b.insert(3);
    vector<tnp> vec1 = b.search(9);
    vector<tnp> vec2 = b.search(16);
    if(vec1[2]->data == 9){
        cout<<"Found 9"<<endl;
    }
    else{
         cout<<"Could not Find 9"<<endl;
    }
    if(vec2[2]->data == 16){
        cout<<"Found 16"<<endl;
    }
    else{
         cout<<"Could not Find 16"<<endl;
    }
    b.print_preorder();
}

