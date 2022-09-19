#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSafe(int **arr , int x, int y, int ){

    for(int i =0 ; i<x ;i++){
        if(arr[i][y]==1){
            return false;
        }
    }

    int i=x;
    int j = y;

    while(i>=0 && j>=0){
        if(arr[i][j]==1){
            return false;
        }
        i--;
        j--;

    }

    i = x;
    j=y;

    while(i>=0 && j<n){
        if(arr[i][j]==1){
            return false;
        }
        i--;
        j++;

    }

    return true;
}

bool nQueen(int **arr, int x, int n){

    if(x>=n){
        return true;
    }

    for(int col=0; col<n ;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;

            if(nQueen(arr,x+1,n)){
                return true;
            }

            arr[x][col]=0; //backtracking
        }

    }

    return false;
}

int main(){

    int n;
    cin>>n;

    int**arr[] = new int*[n];

    for(int i=0;i<n;i++){
        arr[i]= new int[n];

    }

    for(int i=0 ;i<n ;i++){
        for(int j=0;j<n;j++){

        arr[i][j]=0;
        }
    }

    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    return 0;
}