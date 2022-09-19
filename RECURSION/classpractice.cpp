#include <iostream>

using namespace std;


  class student{
    
    public:
    string name;
    int age;
    bool gender;


    void PrintInfo(){
      cout<<"Name"<<endl;
      cout<<name<<endl;
      cout<<"Age"<<endl;
      cout<<age<<endl;
      cout<<"Gender"<<endl;
      cout<<gender<<endl;
    }

  };

int main(){


  student a;

  a.name="Ashish";
  a.age=21;
  a.gender=1;

  a.PrintInfo();

  return 0;
  
}