#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *right;
    Node*left;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};

Node * SearchInBST(Node *root, int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    if(root->data > key){
        return SearchInBST(root->left , key);
    }

    // if not both above then search in right that is if root->data < key then 
    return SearchInBST(root->right , key);
}

int main(){

    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);


    if(SearchInBST(root,5) == NULL){
        cout<<"Key does not exist"<<endl;
    }
    else{
        cout<<"Key does exist"<<endl;
    }


    return 0;
}