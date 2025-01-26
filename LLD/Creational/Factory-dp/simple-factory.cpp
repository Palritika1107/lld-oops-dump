#include <bits/stdc++.h>
using namespace std;

//ilogger ->error
//   /     \     \
//  debug   log  error

//loggerfactory
// 

enum class Loglevel{
    DEBUG,
    INFO,
    ERROR
};

class Ilogger{
    public:

    virtual void log() = 0;
    virtual ~Ilogger(){}

};

class debug : public Ilogger{

    public : 
    
    void log() override{
        cout<<"debug logger"<<"\n";
    }

};

class error : public Ilogger{
    public :

    void log() override{
        cout<<"error logger"<<"\n";
    }
};

class loggerFactory{
    public :

    Ilogger* createLogger(Loglevel llname){

        if(llname == Loglevel::DEBUG)
            return new debug();
        else if(llname == Loglevel::ERROR)
            return new error();

        return nullptr;

    }

};

int main(){

    loggerFactory loggerft;

    // string st = "DEBUG";

    Ilogger* debugLogger = loggerft.createLogger(Loglevel::DEBUG);
    debugLogger->log();

    delete debugLogger;


    return 0;
}