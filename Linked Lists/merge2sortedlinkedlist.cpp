#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node{
    public :
    int data;
    node*next;

    node (int val){
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


node * mergeiterative(node* &head1 , node * &head2){
    node *ptr1 = head1;
    node *ptr2 = head2;
    
    node * dummynode = new node(-1);
    node * ptr3 = dummynode;


    while(ptr1!=NULL && ptr2!=NULL){

        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1= ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2= ptr2->next;
        }

        ptr3 = ptr3->next;
    }

    while(ptr1!=NULL){
        ptr3->next = ptr1;
        ptr1= ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3= ptr3->next;
    }

    return dummynode->next;
}

node * mergeRecursive(node * &head1, node *& head2){

    //base case
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node * result ;

    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next , head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}


void display(node *head ){
    node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}




int main(){

    node *head1 = NULL;

    int arr[]= {1,3,5,7,8,98};

    for(int i=0;i<6;i++){
        InsertAtTail(head1,arr[i]);
    }

    node *head2 = NULL;

    int arr1[] = {2,4,6,9};

    for(int i=0 ;i<4;i++){
        InsertAtTail(head2, arr1[i]);
    }

    display(head1);
    display(head2);

    // node *newhead = mergeiterative(head1,head2);

    // display(newhead);

    node *newhead1 = mergeRecursive(head1,head2);
    display(newhead1);


    return 0;
}