#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int data ;
    node *next;

    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

class Queue{
    public :
    node *front ;
    node* back;

    Queue(){
        front = NULL;
        back = NULL;
    }

    void push(int val){

        node * n = new node(val);

        if(front ==NULL){
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;

    }

    void pop(){
        if(front ==NULL){
            cout<<"Queue is empty ,cant pop anymore bitch"<<endl;
            return;
        }

        node *todelete = front;
        front = front ->next;

        delete todelete;
    }


    int peek(){
        if(front ==NULL){
            cout<<"Queue is empty, cant peek bitch "<<endl;
            return -1;
        }

        return front ->data;
    }

    bool empty(){
        if(front ==NULL){
            cout<<"empty bitch "<<endl;
            return true;
        }
        return false;
    }

};



int main(){

    Queue q;

    for(int i=0 ;i<5;i++){
        q.push(i);
        cout<<q.peek()<<endl;
        q.pop();
    }

   q.empty();
    return 0;
}