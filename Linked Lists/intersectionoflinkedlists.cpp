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

void Intersect(node * &head1 , node* &head2 , int pos){

    node *temp1 = head1;
    while(pos--){
        temp1 = temp1->next;
    }

    node *temp2 = head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    temp2->next = temp1;
    

}



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

int length(node * &head){
    int l=0;

    node *temp = head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }

    return l;
}

int intersectionfinding(node *&head1, node*&head2){

    int d=0;
    int l1 = length(head1);
    int l2 = length(head2);

    node *ptr1; //will traverse longer linked list till d.
    node *ptr2; // will traverse smaller linked list 

    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1= ptr1->next;

        if(ptr1==NULL){
            return -1;
        }
        
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){


        if(ptr1==ptr2){
            return ptr1->data ; // or ptr2
        }
        ptr1= ptr1->next;
        ptr2= ptr2->next;

    }

    return -1;


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

    int arr[]= {1,2,3,4,5,6,7,8,9};

    for(int i=0;i<9;i++){
        InsertAtTail(head1,arr[i]);
    }

    node *head2 = NULL;

    InsertAtTail(head2,72);
    InsertAtTail(head2,98);
    InsertAtTail(head2,9998);

    Intersect(head1,head2,4);

    display(head1);
    display(head2);

    cout<<intersectionfinding(head1,head2)<<endl;


    return 0;
}