#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }


};

void InsertAtHead(node * &head , int val){

    node *n = new node(val);

    n->next = head;

    head=n;
}

void InsertAtTail(node*  &head , int val){
    
    node* n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node *temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void display(node* head){

    node *temp= head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

bool searching(node * &head, int key){

    node * temp = head;

    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }

        temp= temp->next;
    }

    return false;

    

}


int main(){

    node *head = NULL;

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,5);
    InsertAtTail(head,17);

    display(head);

    InsertAtHead(head,47);
    display(head);
    cout<<searching(head,3);


    return 0;
}