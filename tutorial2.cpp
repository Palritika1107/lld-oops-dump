#include<bits/stdc++.h>
using namespace std;

class Rectangle{

public:
    int l;
    int b;

Rectangle(){ //default contructor
    l = 0;
    b = 0;
}
Rectangle(int x,int y){ //parameterised contructor
    l = x;
    b = y;
}
Rectangle(Rectangle &r){
    l = r.l;
    b = r.b;
}
~Rectangle(){
    cout<<"destructor called"<<"\n";
}

};

int main(){

    Rectangle* r1 = new Rectangle();

    cout<<r1->l<<" "<<r1->b<<"\n";

    delete r1;//for pointer to class destructo rhas to be explicitly called , for reference type (r2,r3) they are automatically called after program ends

    Rectangle r2(3,4);

    cout<<r2.l<<" "<<r2.b<<"\n";


    Rectangle r3(r2); // anythoer syntax is Rectangle r3 = r2;

    cout<<r3.l<<" "<<r3.b<<"\n";

    return 0;
}