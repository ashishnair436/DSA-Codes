// #include <bits/stdc++.h>
// #include<iostream>

// using namespace std;

// class node{

//     public:
//     int data;
//     node *next;

//     node(int val){
//         data = val;
//         next = NULL;
//     }

// };

// void InsertAtHead(node* &head, int val){

//     node *n= new node(val);

//     n->next = head;
//     head=n;

// }

// void InsertAtTail(node * &head , int val){



//     node *n = new node(val);

//     if(head==NULL){
//         head=n;
//         return;
//     }

//     node *temp = head;

//     while(temp->next!=NULL){
//         temp= temp->next;
//     }

//     temp->next = n;

// }

// void display(node *head){

//     node* temp= head;

//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }

//     cout<<endl;
// }


// bool searching(node* &head , int key){

//     node *temp= head;

//     while(temp!=NULL){
//         if(temp->data==key){
//             return true;
//         }
//         temp= temp->next;
//     }

//     return false;
// }

// void deleteAtHead(node* &head){
//     node *todelete = head;
//     head = head->next;

//     delete todelete;
// }

// void deletion(node* &head, int val){

//     if(head==NULL){
//         return;
//     }

//     if(head->next==NULL){
//         deleteAtHead(head);
//         return ;
//     }


//     node *temp = head;

//     while(temp->next->data!=val){
//         temp = temp->next;
//     }

//     node *todelete =temp->next;

//     temp->next = temp->next->next;

//     delete todelete;

// }


// int main(){

//     node *head = NULL;

//     InsertAtTail(head,1);
//     InsertAtTail(head,14);
//     InsertAtTail(head,17);
//     InsertAtTail(head,2);
//     InsertAtTail(head,27);
//     InsertAtTail(head,32);

//     display(head);

//     InsertAtHead(head,73);
//     display(head);
//     InsertAtHead(head,54);


//     display(head);

//     deletion(head,27);
//     deleteAtHead(head);
//     display(head);

//     cout<<searching(head,3)<<endl;
//     cout<<searching(head,14);
    

//     return 0;
// }


#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

Node* createlist(int n)
{
    Node* head=new Node();
    head->data=1;
    Node* node=head;
    for(int i=1;i<n;i++)                 //iteratively creates n nodes
    {
        Node* node2=new Node();
        node->next=node2;
        node2->data=i+1;
        node=node2;
    }
    
    Node* end=new Node();           //marks the end of LL with a NULL node
    node->next=end;
    end->data=NULL;
    return head;
}

Node* deletenode(int del, Node* head)
{
    if(del==head->data)              //del= data of first node 
        return head->next;
    
    Node* temp=head;
    
    while(temp->next->data!=del)    //loop till data of next node matches del
    {
        temp=temp->next;
    }
    
    temp->next=temp->next->next;    //change link 
    return head;
}

int main()
{
    int n; cin>>n;
    Node* head=createlist(n);
    Node* temp=head;
    while(temp->data!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n\n";

    
    int del=0;
    while(del!=-1)      //type -1 to exit 
    {    
        cin>>del;                // put value of a particular node to delete it
        head=deletenode(del,head);
        
        Node* temp=head;
        
        while(temp->data!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n\n";
    }
    
    return 0;
}