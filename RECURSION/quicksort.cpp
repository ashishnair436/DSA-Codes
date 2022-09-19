#include <iostream>
using namespace std;


void swap(int arr[] , int i, int j){
    int temp=arr[i];
    arr[i]= arr[j];
    arr[j] = temp;
}

int partition(int arr[] , int st, int en){
    
    int pivot = arr[en];
    int i= st-1;

    for(int j=st;j<en;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }

    swap(arr,i+1,en);
    return i+1;
}

void quicksort(int arr[] , int st, int en){

    if(st<en){

        int pivot = partition(arr,st,en);
        quicksort(arr,st,pivot-1);
        quicksort(arr,pivot+1,en); 
        
    }
}



int main(){

    int arr[]= {5,4,3,2,1};

    quicksort(arr,0,4);

    for(int i=0 ;i<5; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}