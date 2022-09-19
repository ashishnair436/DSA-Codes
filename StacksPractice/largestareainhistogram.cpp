#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getmaxarea(vector<int> &arr){

    int n = arr.size();
    int ans =0;
    int i=0;

    stack <int> st;

    arr.push_back(0);

    while(i<n+1){
         
         while(!st.empty() && arr[st.top()] > arr[i] ){
            int topelement = st.top();
            int height = arr[topelement];
            st.pop();

            if(st.empty()){
                ans = max(ans,height * i);
            }

            else{
                int length = i- st.top() - 1;
                ans = max(ans, height *length);
            }
         }


        st.push(i);
        i++;
    }

    return ans;
}

int main(){

    vector<int> arr = {2,1,5,6,2,3};
    cout<<getmaxarea(arr);
    return 0;
}