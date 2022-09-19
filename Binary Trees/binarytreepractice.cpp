#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int HeightofTree(Node * root){
    if(root==NULL){
        return 0;
    }

    int leftheight = HeightofTree(root->left);
    int rightheight = HeightofTree(root->right);

    int maxheight = max(leftheight,rightheight) +1;

    return maxheight;
}

int main(){
    
    Node *root = new Node (1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //root->left->left->left = new Node(8);
     //root->left->left->left->left = new Node(9);
    cout<<HeightofTree(root)<<endl;
    
    
    return 0;
}