#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){

        vector <int> v1;
        v1.push_back(1);
        v1.push_back(12);
        v1.push_back(3);
        v1.push_back(97);
        v1.push_back(53);
        v1.push_back(243);

        for(int i=0 ;i<v1.size() ; i++){
            cout<<v1[i]<<" ";
        }

        cout<<endl;
        vector <int> ::iterator it;

        for(it=v1.begin() ; it!=v1.end() ;it++){
            cout<<*it<<" ";
        }
        cout<<endl;

        for(auto element:v1){
            cout<<element<<" ";
        }

        v1.pop_back();
        
        cout<<endl;
        for(auto element:v1){
            cout<<element<<" ";
        }
        cout<<endl;

        vector <int> v2(3,72);
        for(auto element:v2){
            cout<<element<<" ";
        }

        swap(v1,v2);

         for(auto element:v1){
            cout<<element<<" ";
        }
        cout<<endl;
        for(auto element:v2){
            cout<<element<<" ";
        }

        cout<<endl;

        sort(v2.begin() , v2.end());
         for(auto element:v2){
            cout<<element<<" ";
        }


    return 0;
}