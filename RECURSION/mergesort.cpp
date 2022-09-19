#include <iostream>
using namespace std;

void merge(int arr[] , int st, int mid , int end){

    int n1=mid-st+1;
    int n2 = end-mid;

    int a[n1];
    int b[n2];  // temp arrays to compare and sort and merge 

    for(int i=0 ;i<n1 ; i++){
        a[i] = arr[st+i];
    }

    for(int i=0 ;i<n2 ; i++){
        b[i] = arr[mid+1+i] ; 
    }

    int i=0 ; 
    int j=0;
    int k = st;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k]= b[j];
            k++;
            j++;

        }
    }

    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k]=b[j];
        k++;
        j++;
    }
    // return ;
}

void mergesort(int arr[] , int st , int end){

    while(st<end){

        if(st>=end){
            return;
        }

        int mid = (st+end)/2;

        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);

        merge(arr,st,mid,end);

    }
    // return ;
    
}


int main(){

    int arr[]= {5,3,2,55,89};
    mergesort(arr,0,4);

    for(int i=0 ;i<5;i++){
        cout<<arr[i]<<" ";

    }
    // cout<<endl;

    return 0;
}