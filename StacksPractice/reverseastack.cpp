#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void insertAtBottom(stack <int> &st , int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int topelement = st.top();
    st.pop();

    insertAtBottom(st, ele);

    st.push(topelement);

}


void reversestack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int topelement = st.top();
    st.pop();
    reversestack(st);
    insertAtBottom(st , topelement);
}


int main(){

    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(33);
    st.push(444);

    reversestack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    return 0;
}