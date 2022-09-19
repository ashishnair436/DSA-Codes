#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        this->data = val;
        this->prev= NULL;
        this->next = NULL;
    }
};


void InsertAtHead(node * &head, int val){
    node *n = new node(val);

    n->next = head;
    if(head!=NULL){

    head->prev = n;
    }
   // n->prev= NULL;
    
    head=n;
}


void InsertAtTail(node * &head , int val){

    node *n = new node(val);

    if(head==NULL){
       InsertAtHead(head,val);
        return ;
    }
    node *temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = n;
    n->prev = temp;
    n->next = NULL;


}

void deleteAtHead(node *& head){
    node *todelete = head ;

    head = head->next;
    head->prev = NULL;

    delete todelete;


}


void deletion(node * & head, int pos){
    node *temp = head;

    if(pos==1){
        deleteAtHead(head);
        return;
    }


    int count = 1;

    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }

    if(temp->prev!=NULL){

    temp->prev->next=temp->next;
    }
    if(temp->next!=NULL){

    temp->next->prev= temp->prev;
    }

    delete temp;
}



void display(node * head){
    node * temp = head;

    cout<<"NULL"<<" ";

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}

int main(){

    node * head = NULL;

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtTail(head,7);
    InsertAtTail(head,8);


    display(head);

    InsertAtHead(head,72);
    InsertAtHead(head,63);
    InsertAtTail(head, 32);

    display(head);

    deletion(head,3);
    deletion(head,1);
    display(head);

    return 0;
}