#include <iostream>
using namespace std;

string xinlast(string s){

    if(s.length()==0){
        return "";
    }

    char ch= s[0];
    string ans = xinlast(s.substr(1));

    if(ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}


int main(){

    string s = "aldsfjlxxxkjaldsjlxjlxxxxxxterimaaakichuuxxxxxxlavdekaxhaisabkuch";

    cout<<xinlast(s);
    return 0;
}