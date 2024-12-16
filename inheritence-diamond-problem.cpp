#include<bits/stdc++.h>
using namespace std;

class Parent{
    public:
     Parent(){
            cout<<" parent class contructor "<<"\n";
     }
}; 

class Child1:public Parent{
    public :
        Child1(){
            cout<<"child1 constructor"<<"\n";
        }
};

class Child2:public Parent{
    public :
        Child2(){
            cout<<"child2 constructor"<<"\n";
        }
};

class RandomClass : public Child1,public Child2 {

    public :
        RandomClass(){
            cout<<"RandomClass constructor"<<"\n";
        }
};


int main(){
//   parent 
//   /    \
//  child1 child2
//   \      /
//     randomclass
//parent class printed twice since it's inheriting once via chils1 and once via child 2
    RandomClass obj1;
    return 0;
}