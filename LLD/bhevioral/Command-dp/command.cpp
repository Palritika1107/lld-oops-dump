#include<iostream>
using namespace std;


class receiver{

public :
receiver(){
    
    cout<<"receiver obj created\n";
}

void paste(){

    cout<<"paste it here \n";
}

void copy(){

    cout<<"copy it from here \n";

}

};



//command interface

class commandInterface{

public :

virtual void execute() = 0;
virtual ~commandInterface(){};


};

//concrete commands

class pasteCommand : public commandInterface{

    receiver* Receiver;
    public:
    
    pasteCommand(receiver* receiverObj){
        Receiver = receiverObj;
    }

    

    void execute(){

        Receiver->paste();
    }

};

class copyCommand : public commandInterface{
    receiver* Receiver;
    public:
    copyCommand(receiver* receiverObj){
        Receiver = receiverObj;
    }

    

    void execute(){

        Receiver->copy();
    }


};

//Invoker

class invoker{

    commandInterface* command;

    public : 

    invoker(commandInterface * command){
        this->command = command;
    }

    void invokeCommand(){

        command ->execute();
    }



};







int main(){
    
    receiver* Receiver = new receiver();

    commandInterface* pastecommand = new pasteCommand(Receiver);
    commandInterface* copycommand =  new copyCommand(Receiver);

    invoker* invokerObj1 = new invoker(pastecommand);
    invoker* invokerObj2 = new invoker(copycommand);

    invokerObj1->invokeCommand();
    invokerObj2->invokeCommand();

    




    return 0;
}


