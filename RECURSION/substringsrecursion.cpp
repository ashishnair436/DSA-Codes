#include <iostream>
using namespace std;

void substrings(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }

    char ch= s[0];
    string restofstring = s.substr(1);

    substrings(restofstring,ans);
    substrings(restofstring,ans+ch);

}

int main(){

    substrings("ABC" , "");

    return 0;
}