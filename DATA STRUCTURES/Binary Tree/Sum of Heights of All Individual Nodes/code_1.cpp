//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

struct bnode {
    int data;
    bnode *left;
    bnode *right;
};

class btree {
public:
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    int height(bnode*);
    int getSumHeight(bnode*);
};
btree::btree() {
    
    root = NULL;
}
bnode* btree:: newNode(int value) {
   
    bnode* temp=new bnode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int btree::height(bnode *root){
    if (!root) {
        return 0;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if (lHeight > rHeight) {
        return (lHeight + 1);
    }
    else {
        return (rHeight + 1);
    }
}

int btree::getSumHeight(bnode* root) {
    if (!root) {
        return 0;
    }
    return getSumHeight(root->left) + height(root) + getSumHeight(root->right);
}
void btree:: insert() {
    root = newNode(1);
    
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    /*
    root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->right = newNode(7);
    root->right->left = newNode(6);
    root->right->left->right = newNode(8);*/
}
void btree::display() {
    insert();
    cout << "\nSum of All Heights\t:\t" << getSumHeight(root);
}





int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}

