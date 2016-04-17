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
    searchResult * res = b.search(INT_MAX);
    if(res->l.load()->data == INT_MAX) {
      cout<<"Found inf2"<<endl;
    }
    else {
      cout<<"Could not Find inf2"<<endl;
    }
    b.insert(6);
    b.insert(10);
    b.insert(7);
    b.insert(9);
    b.insert(14);
    b.insert(3);
    searchResult * res1 = b.search(9);
    searchResult * res2 = b.search(16);
    if(res1->l.load()->data == 9){
        cout<<"Found 9"<<endl;
    }
    else{
         cout<<"Could not Find 9"<<endl;
    }
    if(res2->l.load()->data == 16){
        cout<<"Found 16"<<endl;
    }
    else{
         cout<<"Could not Find 16"<<endl;
    }
    b.print_preorder();
}

