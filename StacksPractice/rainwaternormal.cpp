#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rainWater ( vector <int> arr){
    int ans =0;

    //corner case if only 2 bars then water cant be stored so first write that

    int n = arr.size();
    if(n<=2){
        return 0;
    }

    //two arrays which have left sum max and right sum max

    vector<int> left(n,0);
    vector<int> right(n,0);

    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for(int i=1 ;i<n; i++){
        left[i] = max(left[i-1] , arr[i]);
        right[n-i-1] = max(right[n-i] , arr[n-i-1]);
    }

    //to calcualte final water

    for(int i=0 ;i<n;i++){
        ans = ans + (min(left[i] , right[i])) - arr[i];
    }

    return ans;


}

int main(){
      vector <int> arr= {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rainWater(arr)<<endl;
    return 0;
}