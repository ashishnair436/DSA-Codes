#include <iostream>
#include<bits/stdc++.h>

using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data= val;
        left = NULL;
        right = NULL;
    }
};

Node * LCA(Node * root, int n1 , int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftLCA = LCA(root->left, n1,n2);
    Node * rightLCA = LCA(root->right, n1 ,n2);

    if(leftLCA && rightLCA){
        return root;
    }

    if(leftLCA==NULL && rightLCA==NULL){
        return NULL;
    }

    if(leftLCA!=NULL){
        return leftLCA;
    }
    return rightLCA;
}

int findDistance(Node * root, int key, int distance){
    if(root==NULL){
        return -1;
    }

    if(root->data == key){
        return distance;
    }

    int leftdistance = findDistance(root->left , key,distance+1);
    int rightdistance = findDistance(root->right, key ,distance+1);

    if(leftdistance!=-1){
        return leftdistance;
    }

    /*
    if(rightdistance!=-1){
        return rightdistance;
    }*/
    return rightdistance;

}

int DistanceBetween2Nodes( Node *root, int n1,int n2){
    Node* Lca = LCA(root,n1,n2);

    int distance1 = findDistance(Lca,n1,0);
    int distance2 = findDistance(Lca,n2,0);

    return distance1 + distance2;
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    
    int n1 = 4;
    int n2 = 5;

    cout<<DistanceBetween2Nodes(root, n1 , n2);
    return 0;
}