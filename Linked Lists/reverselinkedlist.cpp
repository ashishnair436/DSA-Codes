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

void deleteAtHead(node *& head){
    node *todelete= head;

    head = head->next;

    delete todelete;
}

void deletion(node * & head, int val){
    
    if(head==NULL){
        return;
    }

    if(head->next ==NULL){
        deleteAtHead(head);
        return;
    }

    node *temp = head;

    while(temp->next->data!= val){
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;

}

node* ReverseLinkedList(node *& head){

    node * prevptr= NULL;
    node *currptr = head;
    node *nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node * ReverseRecursive (node * &head){


    if(head==NULL || head->next==NULL){
        return head;
    }

    node * newhead = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}





void Searching(node * &head , int key){
    node *temp = head;
    bool flag = 0;

    while(temp!=NULL){
        if(temp->data == key){
            cout<<"FOund key"<<endl;
            flag = 1;
        }
        
        temp = temp->next;
    }

    if(!flag){
        cout<<"Not found"<<endl;
    }


}


void display(node* head){
    node * temp= head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){

    node * head = NULL;

    InsertAtTail(head,12);
    InsertAtTail(head,123);
    InsertAtTail(head,192);
    InsertAtTail(head,789);
    InsertAtTail(head,907);
    InsertAtTail(head,12314);


    display(head);

    InsertAtHead(head,6);
    InsertAtHead(head,87);

    display(head);

    node * newhead = ReverseLinkedList(head);

    display(newhead);

    node *newhead1 = ReverseRecursive(newhead);

    display(newhead1);

    return 0;
}