#include "Singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::_instance = 0; // or NULL

Singleton::Singleton()
{
    cout<<"Singleton instance created...."<<endl;
}

Singleton* Singleton::Instance()
{
    if (_instance == 0) {
        _instance = new Singleton();
    }

    return _instance;
}
