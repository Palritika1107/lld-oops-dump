#include<bits/stdc++.h>
using  namespace std;

// In your code, the variables instance and mtx are initialized outside the class because:

// 1. Static Members in C++
// Static members (like instance and mtx in this case) belong to the class rather than to any specific object. They are shared across all objects of the class.
// They need to be defined and initialized outside the class definition because the class declaration only declares their existence but does not allocate memory for them.
// 2. Separation of Declaration and Definition
// In the class declaration, you declare:
// cpp
// Copy code
// static PaymentGatewayManager *instance;
// static mutex mtx;
// This tells the compiler that these static members exist, but their memory is not allocated at this point.
// Outside the class, you define and initialize them:
// cpp
// Copy code
// PaymentGatewayManager *PaymentGatewayManager::instance = nullptr;
// mutex PaymentGatewayManager::mtx;
// This is where the memory is allocated and their initial values are set.
// 3. Why This Design Is Required
// Static members are not tied to any object instance, so their initialization can't depend on object creation. Placing their definition outside the class ensures that they are initialized independently of any object instantiation.
// This is critical for implementing the Singleton pattern in your code, where the instance variable is used to ensure there is only one instance of PaymentGatewayManager.
// 4. Mutex and Thread Safety
// mtx is a static mutex to ensure thread safety when initializing the singleton instance (instance).
// Defining it outside the class allocates memory for the mutex, allowing it to be used for locking and unlocking operations across all threads and ensuring the Singleton pattern remains thread-safe.
// Key Points:
// Static member variables must be defined and initialized outside the class to allocate memory.
// This design pattern (Singleton) relies on static variables to maintain a single shared instance.
// Mutex (mtx) ensures thread safety when multiple threads try to initialize the singleton concurrently.

class Singleton{

    private : 

    Singleton(){

        cout<<"Singleton class initialised \n";
    }

    static Singleton* instance;
    static mutex mtx;

    public :

    static Singleton* getInstance(){

        if(instance == nullptr){

            mtx.lock();  

            if(instance == nullptr){

                instance = new Singleton();

            }
            mtx.unlock();

        }

        return instance;


    }


    static void display(){

        cout<<"Singleton with double checked locking \n";
    }



};

Singleton* Singleton:: instance = nullptr;
mutex Singleton:: mtx;





int main(){

    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    if(obj1 == obj2)
        cout<<"Singleton is working and handling multithreading \n";
    else 
        cout<<"not handling multithreading \n";

    obj1->display();
    obj2->display();



    return 0;
}