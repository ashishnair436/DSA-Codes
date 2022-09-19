#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left= NULL;
        right=NULL;
    }
};

int search(int inorder[] , int start, int end , int value){

    for(int i= start ; i<=end ;i++){
        if(inorder[i] == value){
            return i;
        }
    }

    return -1;
}

Node * buildTree(int postorder[] , int inorder[] , int start, int end){

    static int index = 4;

    if(start>end){
        return NULL;
    }

    int value = postorder[index];
    index--;

    Node * current = new Node(value);

    if(start==end){
        return current;
    }

    int pos = search(inorder , start, end, value);

    current->right = buildTree(postorder,inorder,pos+1 , end);
    current->left = buildTree(postorder, inorder , start , pos-1 );

    return current;
}

void inorderPrint(Node * root){

    if(root == NULL){
        return ;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    Node * root = buildTree(postorder, inorder , 0 , 4);
     inorderPrint(root);
    cout<<endl;

    return 0;
}