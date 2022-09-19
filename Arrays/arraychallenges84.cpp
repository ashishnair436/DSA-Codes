// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int *arr = new int [n];

//     for(int i=0 ;i<n;i++){
//         cin>>arr[i];
//     }

//     int mx= INT_MIN;

//     for(int i=0 ;i<n; i++) {
//         mx = max(mx, arr[i]);
//         cout<<mx<<" ";
//     }
//     return 0;
// }

// Sum of all Subarrays

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
    
//     int n;
//     cin>>n;

//     int * arr = new int[n];

//     for(int i=0 ;i<n; i++){
//         cin>>arr[i];
//     }

//     int curr=0;

//     for(int i=0;i<n;i++){
//         curr = 0;
//         for(int j=i; j<n;j++){
//             curr = curr+arr[j];
//             cout<< curr<<endl;
//         }
//     }

//     return 0;

// }

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int *arr = new int[n];
//     for(int i=0 ;i<n;i++){
//         cin>>arr[i];
//     }

//     int ans = 2;
//     int prevdiff = arr[1] -arr[0];
//     int curr = 2;
//     int  j =2;

//     while(j<n){

//         if(prevdiff == arr[j] - arr[j-1]){
//             curr++;
//         }
//         else{
//             prevdiff = arr[j] - arr[j-1];
//             curr =2;
//         }

//         ans = max(curr,ans);

//         j++;
//     }

//     cout<<ans<<endl;


//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int * arr = new int[n+1];
    arr[n] = -1;

    for(int i=0 ;i<n;i++){
        cin>>arr[i];
    }

    if(n==1){
        cout<<"1" <<endl;
        return 0;
    }

    int mx = INT_MIN;
    int ans = 0;

    for(int i=0  ; i<n;i++){
        if(arr[i] >mx && arr[i]>arr[i+1]){
            ans++;
        }

        mx = max(mx, arr[i]);
    }

    cout<<ans;

    return 0;
}