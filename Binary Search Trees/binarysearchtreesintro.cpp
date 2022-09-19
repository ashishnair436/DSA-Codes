#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *left ;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right= NULL;
    }
};

Node * InsertBST(Node *root , int val){

    if(root==NULL){
        return new Node(val);
    }

    if(root->data> val){
        root->left =  InsertBST(root->left , val);
    }
    else{
        //root->data < val
        root->right = InsertBST(root->right , val);
    }

    return root;
}

void Inorder(Node *root){
    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main(){

    Node *root = NULL;
    root = InsertBST(root,5);
    InsertBST(root,1);
    InsertBST(root,3);
    InsertBST(root,4);
    InsertBST(root,2);
    InsertBST(root,7);

    Inorder(root);

    return 0;
}