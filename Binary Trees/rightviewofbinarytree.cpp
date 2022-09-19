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

void RightView(Node *root){

    if(root == NULL){
        return ;
    }

    queue <Node*> q;

    q.push(root);
    //queue.push(NULL);

    while(!q.empty()){

        int n = q.size();

        for(int i = 0 ;i< n; i++){
            Node * current = q.front();
            q.pop();            

            if(i==n-1){
                cout<<current->data<<" ";
            }

            if(current->left!=NULL){
                q.push(current->left);
            }

            if(current->right!=NULL){
                q.push(current->right);
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
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    RightView(root);
    return 0;
}