#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node* left ;
    Node* right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};

//case 1
void PrintNodesatSubtree(Node *root, int k){
    if(root==NULL || k<0){
        return ;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    PrintNodesatSubtree(root->left, k-1);
    PrintNodesatSubtree(root->right, k-1);
}

//case 2

int printNodesAtK(Node * root, Node *target, int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        PrintNodesatSubtree(root,k);
        return 0;
    }

    int distanceleft = printNodesAtK(root->left, target , k);

    if(distanceleft != -1){
        if(distanceleft + 1 == k){
            cout<<root->data<<" ";
        }
        else {
            PrintNodesatSubtree(root->right , k-distanceleft-2);
        }
        return 1 + distanceleft;
    }

    int distanceright = printNodesAtK(root->right , target, k);

    if(distanceright != -1){
        if(distanceright +1 == k){
            cout<<root->data<<" ";
        }

        else{
            PrintNodesatSubtree(root->left, k-distanceright-2);
        }

        return 1 + distanceright;
    }
    

    return -1;
}


int main(){


    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    printNodesAtK(root, root->left , 1);
    cout<<endl;

    Node *root2 = new Node(1);
    root2->left = new Node(5);
    root2->right = new Node(2);
    root2->right->left= new Node(3);
    root2->right->right = new Node(4);
    root2->left->left = new Node(6);
    root2->left->left->right = new Node(7);
    root2->left->left->right->left = new Node(8);
    root2->left->left->right->right = new Node(9);

    printNodesAtK(root2,root2->left,3);
    


    return 0;
}