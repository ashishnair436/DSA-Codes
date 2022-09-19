#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rainWater ( vector <int> &arr){

    int ans =0;
    int n = arr.size();

    stack <int> st;

    for(int i=0 ; i<n ;i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            int current = st.top();
            st.pop();

            if(st.empty()){
                break;
            }

            int difference = i - st.top()-1;

            ans +=  (min(arr[st.top()] , arr[i]) - arr[current] ) * difference;
        }

        st.push(i);
    }

    return ans;
}

int main(){

    vector <int> arr= {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rainWater(arr)<<endl;

    return 0;
}