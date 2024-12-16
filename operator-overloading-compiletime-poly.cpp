#include<bits/stdc++.h>
using namespace std;

class Complex{

    public:
        int real;
        int img;

        Complex(){
            real = 0;
            img  = 0;
        }
        Complex(int a,int b){
            real = a;
            img = b;
        }

        Complex operator+ (Complex &c){
            Complex ans(0,0);
            cout<<real<<" "<<img<<"\n";
            ans.real = c.real + real;
            ans.img  = c.img + img;
            return ans;
        }

};


int main(){

   Complex c1(1,2);
   Complex c2(3,4);

   Complex res;
   res = c1 + c2;

   cout<<res.real<<" i"<<res.img;

    return 0;
}