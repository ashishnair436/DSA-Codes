#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool sorted(int arr[] ,int n ){

    if(n==1){
        return 1;
    }

    bool restArray = sorted(arr+1, n-1);

    return arr[1]>arr[0] && restArray;
}

int main(){

    int arr[]= {1,2,3,4,5};
    cout<<sorted(arr,5 );

    return 0;
}