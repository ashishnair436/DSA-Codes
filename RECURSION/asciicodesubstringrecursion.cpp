#include <iostream>
using namespace std;

void asciistrings(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }

    char ch=s[0];
    int ascii = ch;
    string ros= s.substr(1);

    asciistrings(ros,ans);
    asciistrings(ros,ans+ch);
    asciistrings(ros, ans+ to_string(ascii));



}

int main(){

    asciistrings("AB","");


    return 0;
}