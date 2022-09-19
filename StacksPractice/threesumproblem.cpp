#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

    int n;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;

    int target ;
    cout<<"Enter the target to be found"<<endl;
    cin>>target;

    vector <int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    /*
    for(auto &i :arr){
        cin>>i;
    }*/

    bool found = false;

    sort(arr.begin() , arr.end());

    for(int i=0 ;i<n; i++){
        int low = i+1;
        int high= n-1;

        while(low<high){
            int current = arr[i] + arr[low] + arr[high];

            if(current == target){
                found = true;
            }

            if(current<target){
                low++;
            }
            else{
                high--;
            }
        }
    }

    if(found){
        cout<<"triplet found"<<endl;
    }

    if(!found){
        cout<<"Does not exist"<<endl;
    }
    return 0;  
}