#include<bits/stdc++.h>
using  namespace std;


//Product Prototype
class NetworkDevice{

    public:

    virtual NetworkDevice* clone() const= 0;
    virtual void display() const = 0;
    virtual void nameUpdate(const string& newName)=0;




};

class Router : public NetworkDevice{
    private:

    string name;
    string protocol;
    string ipAdress;

    public : 

    Router(string name, string protocol,string ipAdress):
    name(name),protocol(protocol),ipAdress(ipAdress){}


    NetworkDevice* clone() const override{

        return new Router(*this);
    }


    void display() const override{

        cout<<"name is :"<<name<<"  ,"<<"protocol is :"<<protocol<<"  ,"<<"ip address is :"<<ipAdress<<" \n";


    }

    void nameUpdate(const string& newName){

        name = newName;

    }





};

class Switch : public NetworkDevice{
    private:

    string name;
    string protocol;
    

    public : 

    Switch(string name, string protocol):
    name(name),protocol(protocol){}


    NetworkDevice* clone() const override{

        return new Switch(*this);
    }


    void display() const override{

        cout<<"name is :"<<name<<"  ,"<<"protocol is :"<<protocol<<"  \n";


    }

    void nameUpdate(const string& newName){

        name = newName;

    }





};




int main(){


    NetworkDevice* router = new Router("router x","firewall enabled","192.168.72.1");
    NetworkDevice* switchDevice = new Switch("switch x","ethernet");

    router->display();
    switchDevice->display();

    NetworkDevice* routerClone = router->clone();

    routerClone->nameUpdate("router y");

    routerClone->display();



    return 0;
}