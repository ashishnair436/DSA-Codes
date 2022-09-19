#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node{
    public:

    int data;
    node* next;

    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void InsertAtHead(node *& head  , int val ){
    node *n = new node(val);

    n->next = head;
    head = n;
}


void InsertAtTail(node* &head , int val){
    node *n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node *temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }    

    temp->next = n;

}

void display(node * head){

    node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


node * ReversekNodes(node* &head , int key){

    node *prevptr = NULL;
    node * currptr = head;
    node * nextptr ;

    int count =0;

    while(currptr!=NULL && count<key){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr= currptr;
        currptr= nextptr;
        count++;

    }

    if(nextptr!=NULL){
        
    head->next = ReversekNodes(nextptr, key);
    }



    return prevptr;

}

int main(){


    node * head = NULL;

    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    InsertAtTail(head, 7);
    

    int k = 2;

    display(head);

    node *newhead = ReversekNodes(head, k);

    display(newhead);

    return 0;
}