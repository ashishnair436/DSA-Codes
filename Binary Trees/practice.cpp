#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int f(int &x, int c){
    c = c-1;
    if(c==0){
        return 1;
    }
    x=x+1;
    return f(x,c) * x;
}

// int  fun(int n){
//     if(n/10 == 0){
//         return n;
//     }

//     return n%10  + fun(n/10);
// }




int main(){

    int k = 5;
    int * p = &k;
    int **n = & p;
    printf("%d %d %d" , k , *p , **n);
    return 0;
}