#include<bits/stdc++.h>
using namespace std;

class Product{

string name;
int id;

public:

Product(string name ,int id):name(name),id(id){}

string getName(){

    return name;
}

int getId(){

    return id;
}


};


class Iterator {

public:

virtual bool hasNext()=0;
virtual Product* first()=0;
virtual Product* next()=0;



};


class ProductIterator : public Iterator{

vector<Product*>product;
// Product* first;
int counter = 0;

public:

ProductIterator(vector<Product*>product):product(product){}

bool hasNext(){

if(counter<product.size()){

    return true;
}

// cout<<"no more products";


return false;
    


}

Product* first(){

if(product.size() > 0){

     
     counter++;
     return product[0];
}
else
{
    cout<<"product list empty \n";
    return NULL;
}

return NULL;
}


Product* next(){

if(this->hasNext()){ //instead of this if i did if(counter < product.size()) it went into infinite loop why?????????????

    return product[counter++];
}

cout<<"no more products \n";


return NULL;



}



};

class Aggregator{

vector<Product*>productList;

public:

Aggregator(){
    cout<<"aggregator constructor \n";
}


void insertProduct(Product* product){

    productList.push_back(product);

}

ProductIterator* createIterator(){

    ProductIterator* iterator = new ProductIterator(productList);

    return iterator;


}


};

int main(){

    Product* p1 = new Product("apple",1);
    Product* p2 = new Product("mango",2);  
    Product* p3 = new Product("Kiwi",3);   
    Product* p4 = new Product("strawberry",4);  

    Aggregator aggregatorObj;

    aggregatorObj.insertProduct(p1);
    aggregatorObj.insertProduct(p2);
    aggregatorObj.insertProduct(p3);
    aggregatorObj.insertProduct(p4);

    ProductIterator* iterator = aggregatorObj.createIterator();

    Product* product = iterator->first();

    while(product){

        cout<<product->getName()<<" "<<product->getId()<<"\n";
       
        product = iterator->next();
        
        
    }





    return 0;
}


