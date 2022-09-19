#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <vector>


using namespace std;

vector <int> stockSpan(vector <int> arr){
    vector <int> result;

    stack <pair<int,int>> st;

    for(int i=0 ;i<arr.size() ; i++){

        int days =1;

        while(!st.empty() and st.top().first <= arr[i]){
            days += st.top().second;
            st.pop();
        }

        st.push(make_pair (arr[i], days));

        result.push_back(days);
    }

    return result;

}

int main(){
    vector <int> arr = {100,80,60,70,60,75,85};
    vector <int> result = stockSpan(arr);

    for(int i=0 ;i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}