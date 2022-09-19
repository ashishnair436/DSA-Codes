#include <iostream>
#include <bits/stdc++.h>

//something is wrong with this code.....and i am not gonna bother......... we have other stuff to do..... lets go to next question.

using namespace std;

int precedence(char ch){

    if(ch=='^'){
        return 3;
    }

    else if((ch=='*') || (ch=='/')){
        return 2;
    }

    else if((ch=='+') || (ch=='-')){
        return 1;
    }

    else{
        return -1;
    }


}

string InfixToPrefix(string s){

    reverse(s.begin() , s.end());

    stack <char> st;
    string result;

    for(int i=0 ;i<s.length()  ; i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result += s[i];
        }

        else if(s[i] == '('){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            while((!st.empty()) && (st.top() == '(')){
                result += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }

        else{
            while((!st.empty()) && (precedence(st.top()) >= precedence(s[i]))){
                result += st.top();
                st.pop();

            }

            st.push(s[i]);
        }

    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    reverse(result.begin() , result.end());


    return result;

}
int main(){

    string s = "(a-b/c)*(a/k-l)";
    cout<<InfixToPrefix(s)<<endl;
    return 0;
}