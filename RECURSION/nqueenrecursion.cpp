#include <iostream>
using namespace std; 

bool is_safe(int **arr,int x,int y, int n ){

    //first to check if queen is placed in any row 
    for(int row=0 ;row<x ; row++){
        if(arr[row][y] == 1){
            return false;
        }
    }

    //now to check if queen is placed in diagonals

    int row=x;
    int col=y;
     
     //to check left diagonal 
    while(row>=0 && col>=0){
        if(arr[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }

    row=x;
    col=y;

        // to check right diagonal 
    while(row>=0 && col<n){
        if(arr[row][col] ==  1){
            return false;
        }

        row--;
        col++;
    }

    return true;
}

    // no need for column int y because we will place in new rows and move on.......... 
    //we wont check for columns as 2 queens should not be in same column 

bool nQueen(int **arr , int x, int n ){

    //base case that are all the queens placed 
    if(x>=n){
        return true;
    }

    for(int col=0 ;col<n; col++){
        if(is_safe(arr,x,col,n)){
            arr[x][col]=1;

            if(nQueen(arr,x+1,n)){
                return true;        
            }

            arr[x][col] = 0;  //backtracking 
        }
    }
    return false;
}

int main(){

    int n;
    cout<<"Enter the size of chess board"<<endl;
    cin>>n;

    //memory allocation of dynamic array 
    int **arr = new int*[n];
    for(int i=0 ;i<n; i++){
        arr[i] = new int[n]; 
    }

    //initialisation with 0;
    for(int i=0 ; i<n ; i++){
        for (int j=0 ;j<n ; j++){
            arr[i][j] = 0;
        }
    }
    

    //now we finally check does the nqueen give us true ........ if yes then we print the array 

    if(nQueen(arr,0,n)){

        for(int i=0;i<n;i++){
            for(int j=0 ;j<n; j++){

                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}