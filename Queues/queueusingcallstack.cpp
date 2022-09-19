#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Queue{
    public:
    stack<int>s1;

    void push(int val){
        s1.push(val);
    }

    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty , cant pop"<<endl;
            return -1;
        }

        int x = s1.top();
        s1.pop();

        if(s1.empty()){
            return x;
        }
        int elements = pop();
        s1.push(x);
        return elements;
    }

    bool empty(){
        if(s1.empty()){
            cout<<"Queue is empty "<<endl;
            return true;
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
    
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}