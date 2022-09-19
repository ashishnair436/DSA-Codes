#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void leapyearornot(int n){
    if(n%400==0){
        cout<<"This is a leap year"<<endl;
    }
    else if(n%4==0 && n%100!=0){
        cout<<"Leap year"<<endl;
    }
    else{
        cout<<"Not a leap year";
    }
}

int main(){
    int n;
    cout<<"Enter the year"<<endl;
    cin>>n;

    leapyearornot(n);
    return 0;
}