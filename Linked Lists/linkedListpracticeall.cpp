#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 class node{
    public:

    int data;
    node *next;

    node(int val ){
        data = val;
        next= NULL;
    }
 };

 
 void InsertAtHead(node* &head , int val){

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

    node *temp= head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;

 }

 void deleteAtHead(node * &head){
    node *n= head;
    head = head->next;

    delete n;
 } 


  void deletion(node* &head , int val){

    if(head==NULL){
        return;
    }

    if(head->next == NULL){
        deleteAtHead(head);
        return ;
    }


    node *temp = head;

    while(temp->next->data!=val){
        temp= temp->next;
    }

    
    node *todelete = temp->next;
    
    temp->next = temp->next->next;

    delete todelete;

  }



 bool Searching(node*head , int key){
    node *temp = head;

    while(temp!=NULL){
        if(temp->data == key){
            return 1;
        }
        temp= temp->next;
    }

    return 0;
 }

void display(node* head){
    node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}


int main(){

    node *head = NULL;

    InsertAtTail(head, 1);
    InsertAtTail(head , 14);
    InsertAtTail(head, 42);

    display(head);
    InsertAtHead(head,13);
    InsertAtHead(head,6);

    display(head);

    cout<<endl;
    cout<<Searching(head , 6)<<endl;
    cout<<Searching(head , 99)<<endl;

    deletion(head , 14);
    deleteAtHead(head);
   // deletion(head,13);
    display(head);

    return 0;
}
