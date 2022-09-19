#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){

    int n;
    cin>>n;
     
     int arr[n];

     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     int low =0 ;
     int high = n-1;

     while(low<=high){

        if(arr[low]<arr[high]){
            high--;
        }
         if(arr[low]>arr[high]){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;

            high--;
            low++;
         }


     }

     for(int i=0; i<n;i++){
        cout<<arr[i];
     }

    return 0;
}