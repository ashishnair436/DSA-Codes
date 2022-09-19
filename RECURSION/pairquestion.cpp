#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

bool myCompare(pair <int,int> p1 , pair <int,int> p2){
    return p1.first<p2.first;
}

int main(){

    int arr[]= {10,16,7,14,5,3,12,9};
    vector <pair <int,int> > v1;

    for(int i=0 ;i< (sizeof(arr) / sizeof(arr[0])) ; i++){

        v1.push_back(make_pair(arr[i] , i));
    }

    sort(v1.begin(), v1.end() ,myCompare);

    for(int i=0 ;i<v1.size() ; i++){
        arr[v1[i].second] = i;
    }

    for(int i=0;i<v1.size(); i++){
         cout<<arr[i]<<" ";
    }


    return 0;
}