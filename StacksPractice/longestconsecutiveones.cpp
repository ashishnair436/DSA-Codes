#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> arr(n);

    for(int i=0 ;i<arr.size() ; i++){
        cin>>arr[i];
    }

    int zerocount = 0 ; 
    int i=0;
    int ans =0;

    for(int j=0; j<n; j++){
        if(arr[j] == 0){
            zerocount++;
        }

        while(zerocount>k){
            if(arr[i] == 0){
                zerocount--;
            }
            i++;
        }

        ans = max(ans, j-i+1);
    }


    cout<<ans<<endl;

    return 0;
}