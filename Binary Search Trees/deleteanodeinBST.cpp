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

//case 1 = to delete a leaf node 
// for case 1 directly delete leaf node no need to do anything else because BST will still be intact.

//case 2 = to delete a node with only one child 
// to simply replace the node we have to delete with its child and the BST will still be intact. 

// case 3 = most problematic
// to delete a node with 2 child
//  to do this first find the inorder  successor of the node to be deleted and then swap the positions of the nodes and then finally delete 

Node * inordersuccessor(Node * root){
    Node *current = root;

    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

Node * DeleteInBST(Node * root, int key){
      
      if(key < root->data ){
        root->left = DeleteInBST(root->left , key);
      }
      else if (key > root->data){
        root->right = DeleteInBST(root->right , key);
      }

    else{
        //for cases 1 and 2
        if(root->left == NULL){
            Node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node * temp = root->left;
            free(root);
            return temp;
        }

        // for case 3
        Node * temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = DeleteInBST(root->right, temp->data);
    }
    return root;

}

void inorder(Node * root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}



int main(){

    Node * root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    inorder(root);
    cout<<endl;
    DeleteInBST(root, 4);
    inorder(root);
    return 0;
}