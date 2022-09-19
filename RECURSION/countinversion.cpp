#include <iostream>

using namespace std;

long long merge(int arr[] , int st, int mid , int en){
    long long inv=0;
    int n1 = mid-st+1;
    int n2 = en-mid;

    int a[n1];
    int b[n2];

    for(int i=0 ;i<n1 ;i++){
        a[i] = arr[st+i];
    }

    for(int i=0; i<n2 ;i++){
        b[i] = arr[mid +1 +i ];
    }

    int i = 0  , j=0  , k=st;
    while(i<n1 && j<n2){

        if(a[i] <= b[j]){
            arr[k] = a[i];
            k++; 
            i++;
        }

        else{
           // a[i] > b[j]  and i<j   this is an inversion so we have to count it 

           arr[k] = b[j];
           inv +=n1 -i;   // a[i] , a[i+1] ,a[i+2]  > = b[j] so we have to count all elements after this ........ 
           k++;
           j++;
        }
    }

    while(i<n1){
        arr[k] = a[i] ; 
        k++; i++;
    }
    while(j<n2){
        arr[k] = b[j];
        k++; j++;
    }

    return inv;
}

long long mergesort(int arr[] , int st , int en){
    long long inv;

    if(st<en){
        int mid = (st+en)/2;
        inv += mergesort(arr,st,mid);
        inv += mergesort(arr,mid+1,en);
        inv += merge(arr,st,mid,en);
    }
    return inv;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0 ;i<n ;i++){
        cin>>arr[i];
    }

    cout<<mergesort(arr, 0 ,n-1)<<endl;
    return 0;
}