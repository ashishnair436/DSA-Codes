#include <iostream>
using namespace std;

int knapsack(int value[],int weight[] , int n , int capacity){

    if(n==0 || capacity==0){
        return 0;
    }

    if(weight[n-1]>capacity){
         return knapsack(value,weight,n-1,capacity);
    }



   int ifconsidered =  knapsack(value,weight,n-1,capacity-weight[n-1]) + value(n-1);
   int ifnotconsidered = knapsack(value,weight , n-1,capacity);

   return max(ifconsiderd,ifnotconsidered);
}

int main(){

    int weight[]= {10,20,30};
    int value[]= {100, 50, 150};
    int capacity = 50;
    cout<<knapsack(value,weight,3,capacity);
    return 0;
}