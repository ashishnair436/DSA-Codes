#include <iostream>
using namespace std;

int pairingfriends(int n){

    if(n==0 || n==1 ||n==2){
        return n;
    }

    int noofways = pairingfriends(n-1) + pairingfriends(n-2)*(n-1) ; 
    return noofways;
}

int main(){
    cout<<pairingfriends(4);
    return 0;
}