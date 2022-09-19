#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int precedence(char ch){

    if(ch=='^'){
        return 3;
    }

    else if(ch=='*' || ch=='/'){
        return 2;
    }

    else if(ch=='+' || ch=='-'){
        return 1;
    }

    else {
        return -1;
    }
}


string InfixToPostfix(string s){

    stack<char> st;

    string result;

    for(int i=0 ;i<s.length() ; i++){

        //check if operand or not
        if((s[i]>= 'a' && s[i]<='z' ) || (s[i]>= 'A' && s[i]<= 'Z' )){
            result += s[i];
        }

        else if(s[i] == '('){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            while((!st.empty()) &&  (st.top()!='(')){
                result += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }

        else{
            while(!st.empty() && precedence(st.top()) > precedence(s[i])){
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        result +=st.top();
        st.pop();
    }
    

    return result;
}


int main(){

    string s = "(a-b/c)*(a/k-l)";
     cout<<InfixToPostfix(s)<<endl;
    return 0;
}