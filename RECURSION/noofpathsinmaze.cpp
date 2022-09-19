#include <iostream>
using namespace std;

int noofpaths(int n , int i, int j){

    if(i==n-1 && j==n-1){
        return 1;
    }

    if(i>n || j>n){
        return 0;
    }

    int totalpaths = noofpaths(n,i+1,j) + noofpaths(n,i,j+1);
    return totalpaths;



}

int main(){
    int n;
    cin>>n;

    cout<<noofpaths(n,0,0);

    return 0;
}