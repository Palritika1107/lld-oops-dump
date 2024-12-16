#include<bits/stdc++.h>
using namespace std;


class Desktop{

    public : 
    string company;
    string RAM;
    string keyboard;
    string speaker;
    string mouse;

    void display(){

        cout<<"Company is :"<<company<<"\n";
        cout<<"RAM is :"<<RAM<<"\n";
        cout<<"keyboard is :"<<keyboard<<"\n";
        cout<<"speaker is :"<<speaker<<"\n";
        cout<<"mouse is :"<<mouse<<"\n";
    }


};

class Builder{
    protected:
        Desktop desktop;

    public:
    virtual void buildCompany()=0;
    virtual void buildRam()=0;
    virtual void buildKeyboard()=0;
    virtual void buildSpeaker()=0;
    virtual void buildMouse()=0;

    Desktop& getDesktop(){
        return desktop;
    }

    virtual ~Builder(){};

    //NOTE : Why a virtual destructor is neccessary ?

    //Virtual Destructor:

// If a polymorphic base class is used as a base pointer for derived objects, it should include a virtual destructor. This ensures proper cleanup of derived objects when deleted through a base pointer.

// Without a virtual destructor, only the base class destructor is called, potentially leading to resource leaks.

//Polymorphic Base Classes : class from which other classes imherit and override already defined methods

};

class HPbuilder : public Builder{

    public :

    void buildCompany(){

        desktop.company = "HP";
    }

    void buildRam(){

        desktop.RAM = "HP-RAM";
    }

    void buildKeyboard(){

        desktop.keyboard = "HP keyboard";
    }

    void buildSpeaker(){
        desktop.speaker = "HP speaker";
    }

    void buildMouse(){
        desktop.mouse = "HP mouse";
    }


};

class SonyBuilder : public Builder{

    public :

    void buildCompany(){

        desktop.company = "Sony";
    }

    void buildRam(){

        desktop.RAM = "Sony-RAM";
    }

    void buildKeyboard(){

        desktop.keyboard = "Sony keyboard";
    }

    void buildSpeaker(){
        desktop.speaker = "Sony speaker";
    }

    void buildMouse(){
        desktop.mouse = "Sony mouse";
    }



};

class Director{

    public :
    Desktop computerBuild(Builder &builderType){
        builderType.buildCompany();
        builderType.buildKeyboard();
        builderType.buildMouse();
        builderType.buildRam();
        builderType.buildSpeaker();
        return builderType.getDesktop();

    }


};


int main(){

    Director objDirector;

    SonyBuilder sonyObj;

    Desktop desktop = objDirector.computerBuild(sonyObj);

    desktop.display();


    return 0;
}
