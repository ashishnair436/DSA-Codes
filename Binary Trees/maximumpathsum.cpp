#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int maximumPathSumUtil(Node *root , int &ans){
    if(root ==NULL){
        return 0;
    }

    int leftsum = maximumPathSumUtil(root->left , ans);
    int rightsum = maximumPathSumUtil(root->right, ans);

    int nodemax = max(max(root->data, root->data + leftsum +rightsum) , max(root->data + leftsum , root->data + rightsum));

    ans = max(ans, nodemax);
   

    int singlepathsum = max(root->data , max(root->data + leftsum , root->data + rightsum));

    return singlepathsum ;

}


int maximumPathSum(Node *root){
    int ans = INT_MIN;
    maximumPathSumUtil(root,ans);
    return ans;
}


int main(){
    
    Node *root = new Node (1);
    root->left = new Node(-12);
    root->right = new Node(3);
    root->left->left = new Node(4);
    //root->left->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    //root->left->left->left = new Node(8);
     //root->left->left->left->left = new Node(9);

     cout<<maximumPathSum(root)<<endl;
    
    
    return 0;
} 