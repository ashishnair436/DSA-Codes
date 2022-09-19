#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node * left;
    Node * right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calculateHeight(Node* root){

    if(root ==NULL){
        return 0;
    }

    int leftheight = calculateHeight(root->left);
    int rightheight = calculateHeight(root->right);

    return max(leftheight,rightheight)+1;
    
}

// this is O(n^2) 
int calculateDiameter(Node *root){

    if(root == NULL){
        return 0;
    }

    int leftheight = calculateHeight(root->left);
    int rightheight = calculateHeight(root->right);

    int currdiameter = leftheight + rightheight +1;

    int leftdiameter = calculateDiameter(root->left);
    int rightdiameter = calculateDiameter(root->right);

    return max(currdiameter , max(leftdiameter,rightdiameter));
}

// if we calculate height in the diameter function itself we can decrease time complexity by O(n);

int calculateDiameter2(Node * root , int * height){

    if(root == NULL){
        *height =0 ;
        return 0;
    }

    int leftheight = 0  , rightheight = 0;

    int leftDiameter = calculateDiameter2(root->left , &leftheight);
    int rightDiameter = calculateDiameter2(root->right , &rightheight);


    int currentDiameter = leftheight + rightheight + 1;
    * height = max(leftheight,rightheight) + 1;

    return max(currentDiameter , max(leftDiameter , rightDiameter));
}


int main(){

    Node * root = new Node(1);
    root->left = new Node(2);
    root ->right = new Node(3);
    root ->left->left = new Node(4);
    root->left->right =  new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<calculateHeight(root)<<endl;
    cout<<calculateDiameter(root)<<endl;

    int height = 0 ;
     cout<<calculateDiameter2(root, &height )<<endl;

    return 0;
}