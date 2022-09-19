#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin,s);

    vector<int> arr(256,-1);

    int maxlengthans = 0; 
    int start =-1;

    for(int i=0 ;i<s.length() ; i++){
        if(arr[s[i]] > start){
            start = arr[s[i]];
        }

        arr[s[i]] = i;

        maxlengthans = max(maxlengthans , i-start);
    }

    cout<<maxlengthans<<endl;

    return 0;
}