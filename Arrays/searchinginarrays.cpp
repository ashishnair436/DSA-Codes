#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int linearsearch(int arr[] ,int n , int key){

    for(int i=0 ;i<n ;i++){
        if(arr[i]==key){
            return i;
            break;
        }
    }
    return -1;

}

int BinarySearch(int arr[] , int n , int key){

    int start = 0;
    int end = n;

    while(start<=end){

        
    int mid = (start+end)/2;


        if(arr[mid]==key){
            return key;
        }

        else if(arr[mid]>key){
            end = mid-1;
        }

        else(arr[mid]<key){
            start = mid+1;
        }
    }

    return -1;
}

int main(){

    int n;
    cin>>n;

    int* arr = new int [n];

    for(int i=0 ;i<n; i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    cout<<linearsearch(arr, n , key)<<endl;

    return 0;
}