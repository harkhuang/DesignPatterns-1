#include "Proxy.h"
#include <iostream>

using namespace std;

Subject::Subject()
{
    cout << "Subject::Subject()" << endl;
}

Subject::~Subject()
{
    cout << "Subject::~Subject()" << endl;
}

ConcreteSubject::ConcreteSubject()
{
    cout << "ConcreteSubject::ConcreteSubject()" << endl;
}

ConcreteSubject::~ConcreteSubject()
{
    cout << "ConcreteSubject::~ConcreteSubject()" << endl;
}

void ConcreteSubject::Request()
{
    cout<<"ConcreteSubject......request...."<< endl;
}

Proxy::Proxy()
{
    cout << "Proxy::Proxy()" << endl;
}

Proxy::Proxy(Subject* sub)
{
    _sub = sub;
}

Proxy::~Proxy()
{
    delete _sub;
}

void Proxy::Request()
{
    cout<<"Proxy request...."<<endl;
    _sub->Request();
}
