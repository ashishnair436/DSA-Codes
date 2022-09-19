#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node* left ;
    Node* right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};

void FlattenBinaryTree(Node* root){

    if(root==NULL || (root->left == NULL && root->right == NULL)){
        return ;
    }

    if(root->left!=NULL){
        FlattenBinaryTree(root->left);

        Node * temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node * tail = root->right;

        while(tail->right !=NULL){
            tail = tail->right;
        }

        tail->right = temp;

    }

    FlattenBinaryTree(root->right);

}

void InorderPrint( Node * root){
    if(root== NULL){
        return;
    }

    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}



int main(){

    Node *root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left =  new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    InorderPrint(root);
    cout<<endl;

    FlattenBinaryTree(root);

    InorderPrint(root);

    return 0;
}