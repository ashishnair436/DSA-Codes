#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left =right = NULL;
    }
};

Node * constructBST(int preorder[] , int* preorderIndex, int key , int min, int max , int n){
   if(*preorderIndex >n){
    return NULL;
   }

    Node *root = NULL;
    if(key > min && key<max){
        root= new Node(key);
        *preorderIndex = *preorderIndex+1;

        if(*preorderIndex < n){
            root->left = constructBST(preorder, preorderIndex , preorder[*preorderIndex] , min  , key , n);
        }
        if(*preorderIndex < n){
            root->right = constructBST(preorder, preorderIndex , preorder[*preorderIndex] , key , max , n);
        }
    }

    return root;
}

void printPreorder(Node * root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){

    int preorder[] = {10,2,1,13,11};
    int n=5;
    int preorderIndex = 0;
    Node * root = constructBST(preorder, &preorderIndex , preorder[0] , INT_MIN , INT_MAX , n);
    printPreorder(root);

    return 0;
}