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

void EvenAfterOdd(node *&head){

    node *odd =head;
    node* even = head->next;
    node *evenstart = even;

    while(odd->next !=NULL && even->next!=NULL){
        odd->next = even->next;
        odd= odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenstart;
    if(odd->next==NULL){
        even->next = NULL;
    }
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
        InsertAtTail(head,17);
    InsertAtTail(head,8);
        InsertAtTail(head,9);
    InsertAtTail(head,10);
        InsertAtTail(head,112);
    InsertAtTail(head,208);

    display(head);
    EvenAfterOdd(head);
    display(head);

    return 0;
}