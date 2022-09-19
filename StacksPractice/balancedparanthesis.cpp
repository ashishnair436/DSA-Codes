#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValid(string s){

    stack <char> st;

    bool ans = true;

    for(int i=0 ;i<s.length() ; i++){
        if(s[i] == '(' || s[i] == '{' || s[i]== '['){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            if((!st.empty()) && st.top() == '('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }


        else if(s[i] == ']'){
            if((!st.empty()) && st.top()== '['){
                st.pop();
            }
             else{
                ans = false;
                break;
            }
        }
        


        else if(s[i] == '}'){
            if((!st.empty()) && st.top()== '{'){
                st.pop();
            }
             else{
                ans = false;
                break;
            }
        }


    }

    if(!st.empty()){
        return false;
    }
    else{
        return ans;
    }

}



int main(){

    string s = "{[()]}";

    if(isValid(s)){
        cout<<"String is valid and paranthesis is balanced"<<endl;
    }
    else{
        cout<<"String is invalid"<<endl;
    }

    return 0;
}