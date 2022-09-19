#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node * left ;
    Node * right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int height (Node * root){

    if(root == NULL){
        return 0;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(leftheight , rightheight) + 1;

}

bool isBalancedTree(Node * root){
    if(root == NULL){
        return true;
    }

    if(isBalancedTree(root->left) == false){
        return false;
    }

    if(isBalancedTree(root->right) == false){
        return false;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if(abs(leftheight - rightheight) <= 1){
        return true;
    }
    else{
        return false;
    }

}

bool isBalancedTreelowcomplexity(Node * root , int * height){
    if(root == NULL){
        *height = 0;
        return true;
    }

    int leftheight= 0;
    int rightheight = 0;

    if(isBalancedTreelowcomplexity(root->left , &leftheight) == false){
        return false;
    }

    if(isBalancedTreelowcomplexity(root->right , &rightheight) == false){
        return false;
    }

    *height = max(leftheight,rightheight) + 1;

    if(abs(leftheight-rightheight) <=1){
        return true;
    }
    else{
        return false;
    }
    
}

int main(){

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    //root->left->left->left->left = new Node(9);


    Node * root2 = new  Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    if(isBalancedTree(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }

    int height = 0;

    if(isBalancedTreelowcomplexity(root , &height)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Unbalanced Tree"<<endl;
    }



    return 0;
}