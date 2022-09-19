#include <iostream>
using namespace std;

bool issafe(int **arr , int x, int y, int n ){
    //see if rat can move in which directions . 
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratinmaze(int **arr, int x, int y , int n , int **solArr){

    //base case 
    if(x==n-1 && y==n-1){
        solArr[x][y] = 1;
        return true;
    }
     
     // main logic 
    if(issafe(arr,x,y,n)){
        solArr[x][y] = 1;

        if (ratinmaze(arr,x+1,y,n,solArr)){
            return true;
        }

        if(ratinmaze(arr,x,y+1,n,solArr)){
            return true;
        }


        solArr[x][y]=0;        //backtrack bitch 
        return false;

    }
    return false;
    

}

int main(){

    int n;
     cout<<"Enter the size of square 2d matrix"<<endl;

    cin>>n;

    //dynamic allocation of array 
    int** arr= new int*[n];
    for(int i=0 ;i<n ;i++){
        arr[i]=new int[n];
    }

    // input of array 
    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<n ;j++){
            cin>>arr[i][j];
        }

    }

    //dynamic allocation of solution array 
    int **solArr = new int*[n];
    for(int i=0 ;i<n ;i++){
        solArr[i] = new int[n];
    }

    //initialize solution array with everything zero 
    for(int i=0 ;i<n ;i++){
        for(int j=0;j<n;j++){
            solArr[i][j] = 0;
        }
    }

    // final solution printing if ratinmaze is giving true 
    if(ratinmaze(arr,0,0,n,solArr)){
        for(int i=0 ;i<n;i++){
            for (int j=0 ;j<n ;j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1 
// 0 1 0 1 0 
// 1 0 0 1 1 
// 1 1 1 0 1 