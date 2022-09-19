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

void LeftView(Node * root){
    if(root == NULL){
        return ;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        int n  = q.size();

        for(int i=0 ;i<n ; i++){
            Node * temp = q.front();

            q.pop();

            if(i==0){
                cout<<temp->data<<" ";
            }

            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }

        }
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
   // root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    LeftView(root);

    return 0;
}