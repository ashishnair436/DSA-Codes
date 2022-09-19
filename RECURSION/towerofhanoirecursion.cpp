#include <iostream>
#include <bits/stdc++.h>

using namespace std;

    void TowerofHanoi(int n , char src , char dest, char helper){

        if(n==0){
            return ;
        }
        TowerofHanoi(n-1 , src, helper, dest);
        cout<<"Move block from "<<src<<" to "<<dest<<endl;

        TowerofHanoi(n-1 ,helper,dest,src );

    }


int main(){

    TowerofHanoi(3,'A','C', 'B');


    return 0;
}