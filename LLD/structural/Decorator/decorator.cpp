#include<bits/stdc++.h>
using namespace std;

//error: no default constructor exists for class "foodItem"
//when writing like this 
// Burger(int price,string name){
//         foodItem(price,name);
//     }
// The issue is that in your constructor definitions for Pizza, Burger, and Topping, you are calling the constructor of foodItem like a regular function. However, constructors in C++ must be called as part of the initializer list when constructing an object, not like a function
//correct way to write :
//  Burger(int price, string name) : foodItem(price, name) {}



class foodItem{
    int price;
    string name;
    
    public:

    foodItem(int price,string name){
        this->price = price;
        this->name  = name;
    }


    virtual double getPrice(){
        return price;
    };
     
    virtual string getDesc(){
        return name;
    };



};

class Pizza : public foodItem{

    public:

    Pizza(int price) : foodItem(price, "Pizza") {}


};

class Burger : public foodItem{

    public:

     Burger(int price) : foodItem(price, "Burger") {}

};

class Topping : public foodItem{

    foodItem* baseFoodItem;

    public :

    
    Topping(foodItem* item,int price, string name) : foodItem(price, name),baseFoodItem(item) {}

    double getPrice() override{

        return baseFoodItem->getPrice() + foodItem::getPrice();
        
    }

    string getDesc(){

        return baseFoodItem->getDesc()+ "with extra"  + foodItem::getDesc();
    }



};

class cheese : public Topping{

    public : 
    cheese(foodItem*item,int price):Topping(item,price,"cheese"){}
        

    



};

class veggies : public Topping{
    public : 
    veggies(foodItem*item,int price):Topping(item,price,"cheese"){}


};

int main(){

    foodItem* pizzaOrder = new Pizza(100);
    foodItem* burgerOrder = new Burger(120);

    pizzaOrder = new cheese(pizzaOrder,10);
     pizzaOrder = new veggies(pizzaOrder,20);
    cout<<pizzaOrder->getDesc()<<"\n";
    cout<<pizzaOrder->getPrice();
    // o/p : 
    // Pizzawith extracheesewith extracheese
// 130 



    return 0;
}



