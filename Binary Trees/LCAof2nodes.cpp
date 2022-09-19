#include <iostream>
#include <bits/stdc++.h>

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

bool getPath(Node * root, int key , vector<int> &path){

    if(root==NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data == key){
        return true;
    }

    if(getPath(root->left , key, path) || getPath(root->right , key , path) ){
        return true;
    }

    path.pop_back();

    return false;
}

int LCA(Node * root , int n1 , int n2){

    vector<int> path1;
    vector<int> path2;

    if( !getPath(root, n1, path1) || !getPath(root , n2, path2)){
        return -1;
    }

    int pathchange ;

    for(pathchange = 0 ; pathchange<path1.size() && path2.size() ; pathchange++){
        if(path1[pathchange] != path2[pathchange]){
            break;
        }
    }

    return path1[pathchange-1];
 
}

Node * LCA2 (Node * root , int n1 , int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node * leftlca = LCA2(root->left, n1,n2);
    Node * rightlca = LCA2(root->right , n1 , n2);

    if(leftlca && rightlca){
        return root;
    }

    if(leftlca != NULL){
        return leftlca;
    }

    return rightlca;
}



int main(){

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    int n1 = 7;
    int n2 = 6;

    int lca = LCA(root,n1,n2);

    if(lca==-1){
        cout<<"Lca does not exist"<<endl;
    }
    else{
        cout<<"LCA is "<<lca<<endl;
    }

      Node * lca1 = LCA2(root,n1,n2);

    if(lca1== NULL){
        cout<<"Lca does not exist"<<endl;
    }
    else{
        cout<<"LCA is "<<lca1->data<<endl;
    }
    

    return 0;
}

