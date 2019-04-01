
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
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating structure for binary tree
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  structure defines a node structure which contains data ( int type ) and
     left and right ( bnode types for storing address of left and right elements )
     
     ------------------------------------------------------------------------------------------------
     */
    int data;
    bnode *left;
    bnode *right;
};

class btree {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : binary tree class
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines constructor and functions which can be accessed publicly such as :-
     1. btree() for initializing the pointer
     2. insert() for insertion in binary tree
     3. display() for displaying binary tree
     6. newNode() for creating new node
     7. preorder() for displaying preorder of tree
     8. postorder() for displaying postorder of tree
     9. inorder() for displaying inorder of tree
     10. creating root node for binary tree
     11. arr[] for storing path and pathlen for storing length of path for every leaf node
     ------------------------------------------------------------------------------------------------
     */
public:
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    void preorder(bnode*);
    void postorder(bnode*);
    void inorder(bnode*);
    int height(bnode*);
    void printLevel(bnode* , int , bool);
    void printSpiral(bnode*);
};
btree::btree() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : initializing root as NULL and pathlen as zero
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   assigning NULL to root and 0 to pathlen
     
     ------------------------------------------------------------------------------------------------
     */
    root = NULL;
}
bnode* btree:: newNode(int value) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating newnode and assigning it to given value
     
     ------------------------------------------------------------------------------------------------
     input parameter : value which has to inserted into binary tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : new node which is created
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating a bnode type node and assiging its left and right as NULL and data as value
     
     ------------------------------------------------------------------------------------------------
     */
    bnode* temp=new bnode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void btree:: insert() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insertion in binary tree
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   inserting nodes from root , then its right & left and so on
     
     ------------------------------------------------------------------------------------------------
     */

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    root->left->right->left = newNode(9);
    /*
    root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
     */
}
void btree::display() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying binary tree and path
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling insert() , inorder() , preorder() , postorder and path() functions
     
     ------------------------------------------------------------------------------------------------
     */
    insert();
    cout << "\nInorder\t\t\t:\t";
    inorder(root);
    cout << "\nPostorder\t\t:\t";
    postorder(root);
    cout << "\nPreorder\t\t:\t";
    preorder(root);
    cout << "\nLevel Order in Spiral Form\t:\t";
    printSpiral(root);
}
void btree :: postorder(bnode* root) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in postorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
     - left , right and then value of pointer
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void btree :: preorder(bnode* root) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in preorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
     - value of pointer , left and right
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL) {
        return;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void btree :: inorder(bnode* root) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in inorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
     - left , value of pointer and right
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    cout << root->data << "\t";
    preorder(root->right);
}


void btree::printSpiral(struct bnode* root)
{
    int h = height(root);
    bool ltr = false;
    for (int i = 1; i <= h; i++) {
        printLevel(root, i, ltr);
        ltr = !ltr;
    }
}
void btree::printLevel(bnode* root, int level , bool ltr)
{
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << root->data << "\t";
    }
    else if (level > 1) {
        if (ltr) {
            printLevel(root->left, level - 1, ltr);
            printLevel(root->right, level - 1, ltr);
        }
        else {
            printLevel(root->right, level - 1, ltr);
            printLevel(root->left, level - 1, ltr);
        }
    }
}
    
int btree::height(bnode* node)
{
    if (node == NULL) {
        return 0;
    }
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {
            return(leftHeight + 1);
        }
        else {
            return(rightHeight + 1);
        }
    }
}
int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
