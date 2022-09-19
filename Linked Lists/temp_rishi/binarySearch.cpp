#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int BinaryToDecimal(int n){

    int ans=0;
    int rem=0;
    int multiplier=1;
    while(n>0){
        rem=n%10;
        ans = ans + (multiplier*rem);
        multiplier*=2;
        n=n/10;
    }

    return ans;

}

int DecimalToBinary(int n){

    int ans=0;
    int multiplier=1;
    while(n>0){
        int rem= n%2;
        n= n/2;

        ans += rem*multiplier;

        multiplier= multiplier*10;
        
    }

    return ans;

}



int  main(){
     int n;

     cin>>n;

     cout<<DecimalToBinary(n)<<endl;

     //cout<<BinaryToDecimal(n)<<endl;
    return 0;
}