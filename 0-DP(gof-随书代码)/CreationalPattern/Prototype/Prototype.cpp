#include "Prototype.h"
#include <iostream>
using namespace std;

Prototype::Prototype()
{
    cout << "Prototype constructor" << endl;
}

Prototype::~Prototype()
{
}

Prototype* Prototype::Clone() const
{
    cout << "Prototype::Clone" << endl;

    return 0;
}

//---------
ConcretePrototype::ConcretePrototype()
{
}

ConcretePrototype::~ConcretePrototype()
{
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp)
{
    cout<<"ConcretePrototype copy ..."<<endl;
}

Prototype* ConcretePrototype::Clone() const
{
    cout << "ConcretePrototype::Clone() calls \"new ConcretePrototype(*this)\"" << endl;
    return new ConcretePrototype(*this);
}
