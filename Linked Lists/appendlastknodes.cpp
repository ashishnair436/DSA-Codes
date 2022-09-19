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

void InsertAtHead(node * &head , int val){
    node *n= new node(val);

    n->next = head;
    head = n;

}

void InsertAtTail(node * &head, int val){

    node *n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node *temp= head;

    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next = n;
}



void display(node* head){
    node * temp= head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

int length(node* &head){
    node *temp = head;

    int length =0;

    while(temp!=NULL){
        length++;
        temp= temp->next;
    }

    return length;
}


node *kappend(node * &head, int k){
    
    node *newhead;
    node *newtail;
    node *tail = head;

    int l = length(head);
    k=k%l;
    int count = 1;

    while(tail->next !=NULL){

        if(count==l-k){
            newtail= tail;
        }

        if(count == l-k+1){
            newhead = tail;
        }


        tail= tail->next;
        count++;

    }

    newtail->next = NULL;
    tail->next = head;

    return newhead;


}


int main(){

    node * head = NULL;

    int arr[] ={1,2,3,4,5,6,7,8,9};

    for(int i=0 ;i<9 ;i++){
        InsertAtTail(head,arr[i]);
    }

    display(head);

    int k = 3;

    node *newhead = kappend(head,k);
    display(newhead);



    return 0;
}