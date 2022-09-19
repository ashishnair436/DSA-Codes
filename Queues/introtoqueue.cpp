#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define n 30

class Queue{
    int * arr;
    int front ;
    int back;
    
    public :
    Queue(){
        arr = new int[n];
        front =-1;
        back =-1;
    }

    void push(int x){
        if(back ==n-1){
            cout<<"Queue Overflow";
            return;
        }
        back++;
        arr[back] = x;

        if(front ==-1){
            front++;
        }
    }

    void pop(){
        if(front ==-1 || front >back){
            cout<<"Queue is Empty , cant pop"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front ==-1 || front >back){
            cout<<"Queue is empty "<<endl;
            return -1;
        }

        return arr[front];

    }

    bool empty(){
        if(front ==-1 || front >back){
            return 1;
        }
        return false;
    }


};



int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    for(int i=0;i<5;i++){

   cout<< q.peek()<<endl;
   q.pop();
    }

    cout<<q.empty()<<endl;


    return 0;
}