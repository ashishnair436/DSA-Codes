#include <iostream>
using namespace std;

void reversestring(string s){

    if(s.length()==0){
        return ;
    }

    string restofstring = s.substr(1);
    reversestring(restofstring);
    cout<<s[0];

}

int main(){

    string s;
    getline(cin,s);

    reversestring(s);
    return 0;
}