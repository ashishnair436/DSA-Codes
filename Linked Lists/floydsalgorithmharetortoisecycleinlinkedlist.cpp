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


void MakeCycle(node * &head, int pos){
    node *temp = head;
    node *startnode;

    int count = 1;

    while(temp->next!=NULL){

       if(count==pos){
            startnode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startnode;
}

void removeCycle(node * & head ){

    node * hare = head;
    node * tortoise = head;

    do
    {   
        tortoise= tortoise->next;
        hare = hare->next->next;
    } while (tortoise!=hare);
    
    hare = head;

    while(tortoise->next != hare->next ){
        tortoise= tortoise->next;
        hare= hare->next;
    }

    tortoise->next=NULL;

}


bool detectCycle(node * & head){

    node * hare = head;
    node *tortoise = head;

    while(hare!=NULL && hare->next!=NULL){
        hare = hare->next->next;
        tortoise = tortoise ->next;

        if(hare==tortoise){
            return 1;
        }
    }

    return 0;
}




void InsertAtHead(node *& head, int val){
    node *n = new node(val);

    n->next = head;
    head = n;
}

void InsertAtTail(node *&head , int val){
    node *n = new node(val);

    if(head==NULL){
        head= n;
        return;
    }

    node *temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = n;

}

void display(node * head){
    node * temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<"Null"<<endl;
}


int main(){

    node *head = NULL;

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtTail(head,7);
    InsertAtTail(head,8);
    MakeCycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);

    //display(head);

    return 0;
}