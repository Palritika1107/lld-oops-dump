#include<bits/stdc++.h>
using namespace std;

//single inheritence
class Parent {

    public:
        Parent(){
            cout<<"Parent class contructor called"<<"\n";
        }
};

class Child1 : public Parent {

public :
    Child1(){
        cout<<"child1 constructor"<<"\n";
    }
};



int main(){

    Child1 c1;

    return  0;
}