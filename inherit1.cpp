#include<bits/stdc++.h>
using namespace std;

class Parent {
    int z;
    public :
      int x;
    protected :
      int y;
};

class Child1:public Parent{

//inherit members of parent publicly
// x will be public 
//y will be protected
//z is inaccessible

};

class Child2:protected Parent{

// x will be protected 
//y will be protected
//z is inaccessible
};

class Child3:private Parent{

// x will be private
//y will be private
//z is in accessible

};

int  main(){

    return 0;
}