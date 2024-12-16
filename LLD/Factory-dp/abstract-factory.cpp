#include<bits/stdc++.h>
using namespace std;

//solution1 : to avoid "uknown type error"
//the following piece of code is known as : Forward Declaration
//if we define the following class inside furniture factory then we will get " unknown type error"
//as modern and traditional factory classes are defined after furniturefactory class
class modernFactory;
class traditionalFactory;

class Sofa{

    public :

    virtual void sitOn() = 0;
};

class Table{

    public :

    virtual void placeOn()=0;
        
};

class Chair{

    public :

   virtual void sitOn()=0;
};

class ModernSofa : public Sofa{

    public:

        void sitOn() override{
            cout<<"sit on modern sofa";
        }

};
class ModernChair : public Chair{

    public:

        void sitOn() override{
            cout<<"sit on modern chair";
        }

};
class ModernTable : public Table{

    public:

        void placeOn() override{
            cout<<"place  on modern table";
        }

};

class TraditionalSofa : public Sofa{

    public:

        void sitOn() override{
            cout<<"sit on Traditional sofa";
        }

};
class TraditionalChair : public Chair{

    public:

        void sitOn() override{
            cout<<"sit on Traditional chair";
        }

};
class TraditionalTable : public Table{

    public:

        void placeOn() override{
            cout<<"place  on Traditional table";
        }

};


class furnitureFactory{

    public :

    virtual Sofa* createSofa() = 0;
    virtual Table* createTable() = 0;
    virtual Chair* createChair() = 0;

    static furnitureFactory* createFurnitureFactory(string factoryName);
    // {

    //     if(factoryName == "modern")
    //         return new modernFactory();
    //     else if(factoryName == "traditional")
    //         return new traditionalFactory();

    //     return nullptr;  
    
    // }

};

class modernFactory : public furnitureFactory{

    public :

    Sofa* createSofa() override{

        return new ModernSofa();
    }

    Table* createTable() override{

        return new ModernTable();
    }

    Chair* createChair() override{

        return new ModernChair();
    }


};

class traditionalFactory : public furnitureFactory{

public : 

    Sofa* createSofa() override{

        return new TraditionalSofa();
    }

    Table* createTable() override{

        return new TraditionalTable();
    }

    Chair* createChair() override{

        return new TraditionalChair();
    }


};


//solution2 : to avoid "uknown type error"
//solution 1: is noot working , 2 works
furnitureFactory* furnitureFactory::createFurnitureFactory(string factoryName) {
    if (factoryName == "modern")
        return new modernFactory();
    else if (factoryName == "traditional")
        return new traditionalFactory();
    return nullptr;
}

int main(){

    string facName = "modern";
    furnitureFactory* factory = furnitureFactory ::createFurnitureFactory(facName);

    Sofa* sofa = factory->createSofa();
    Table* table = factory->createTable();
    Chair* chair = factory->createChair();

    sofa->sitOn();
    table->placeOn();
    chair->sitOn();

    //memeory management : cleanup of dynamically allocated memory
    delete sofa;
    delete table;
    delete chair;
    delete factory;




    return 0;
}





