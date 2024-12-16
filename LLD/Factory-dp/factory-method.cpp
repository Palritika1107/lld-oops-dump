#include<bits/stdc++.h>
using namespace std;

class Ilogger{

    public:
        virtual void log() = 0;
        virtual ~Ilogger();

};

class debugLogger : public Ilogger{

    public:
        void log() override{
            cout<<"Debug Logger";
        }


};

class errorLogger : public Ilogger{

    public:
        void log() override{
            cout<<"Error Logger";
        }


};

class infoLogger : public Ilogger{

    public:
        void log() override{
            cout<<"Info Logger";
        }


};


class LoggerFactory{

    public:

    // virtual debugLogger* createDebugLogger() = 0;
    // virtual errorLogger* createErrorLogger() = 0;
    // virtual infoLogger* createInfoLogger() = 0;

    virtual Ilogger* createLogger() = 0;

    // static LoggerFactory* createLoggerFactory(string &factoryName){

    //         if(factoryName == "debug"){
    //             return new debugFactory();
    //         }
    //         else if(factoryName == "error"){
    //             return new errorFactory();
    //         }
    //         else if(factoryName == "info"){
    //             return new infoFactory();
    //         }

    //         return nullptr;

    // }

};

class debugFactory : public LoggerFactory{


    Ilogger* createLogger() override{

       return new debugLogger();

    }

};

class errorFactory : public LoggerFactory{


    Ilogger* createLogger() override{

       return new errorLogger();

    }

};

class infoFactory : public LoggerFactory{


    Ilogger* createLogger() override{

       return new infoLogger();

    }

};

int main(){

    string loggerName = "error";

    LoggerFactory* factory = new errorFactory();
    Ilogger* logger = factory->createLogger();
    logger->log();

    delete factory;
    delete logger;


    return 0;
}

