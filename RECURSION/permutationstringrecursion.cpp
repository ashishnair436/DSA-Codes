#include <iostream>
using namespace std;

void permutations(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0 ; i<s.length() ; i++){
        char ch= s[i];
        string restofstring = s.substr(0,i) + s.substr(i+1,s.length());

        permutations(restofstring , ans+ch);
    }

}

int main(){

    permutations("ABC" , "");

    return 0;
}