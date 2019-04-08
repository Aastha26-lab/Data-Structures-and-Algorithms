//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;

struct bnode {
    int data;
    bnode *left;
    bnode *right;
};

class btree {
public:
    bnode *root , *root2;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    void leftView(bnode*);
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
void btree:: insert() {
    /*
    root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
     */
    root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->right = newNode(6);
    root->right->left->right->left = newNode(18);
    root->right->left->right->right = newNode(7);
}
void btree::display() {
    insert();
    cout << "\nLeft View\t:\t";
    leftView(root);
}



void btree::leftView(bnode* root) {
    queue<bnode*> q;
    if (root == NULL) {
        return;
    }
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        bnode* temp = q.front();
        
        if (temp) {
            cout << temp->data << "\t";
            while (q.front() != NULL) {
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                q.pop();
                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }
}
int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}

