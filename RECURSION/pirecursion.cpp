#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void pirecursion(string s){

    if(s.length()==0){
        return ;
    }

    if(s[0]=='p' && s[1] =='i'){
        cout<<"3.14";
        pirecursion(s.substr(2));
    }
    else{
        cout<<s[0];
        pirecursion(s.substr(1));

    }

}


int main(){

    string s = "pipppxipipppxxashipipiashishopbenchoppippi";
    pirecursion(s);

    return 0;
}