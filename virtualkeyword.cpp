#include <bits/stdc++.h>
using namespace std;


class Base{

    public:
    int x;

    Base(){
        x = 18;
    }

   void virtual print(){  // remove virtual and check o/p 
        cout<<x;
    }
};

class Child : public Base{

    public:
    int x;

    Child(){
        x = 10;
    }

    void print(){
        cout<<x;
    }
};
int main(){

    Base *b;
    Child c;
    b = &c;
    //if you remove virtual then child class can't override hence value of base class will be printed
    //if virtual keyword is there before print finction in Base class then child class can override print funnction and 10 will be printed
    b->print();

    return 0;
}