#include<bits/stdc++.h>
using namespace std;

class Fruits{

public :
    string name;
    string color;
};



int main(){

    Fruits apple ; //object declaration

    apple.name = "apple";
    apple.color = "red";

    cout<<apple.name<<" "<<apple.color<<"\n";

    Fruits* mango = new Fruits();
    mango->name = "mango";
    mango->color = "yellow";

    cout<<mango->name<<" "<<mango->color<<"\n";
    return 0;
}
