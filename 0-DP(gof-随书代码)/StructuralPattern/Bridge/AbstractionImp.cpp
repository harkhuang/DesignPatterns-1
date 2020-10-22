#include "AbstractionImp.h"
#include <iostream>

using namespace std;

AbstractionImp::AbstractionImp()
{
    cout << "AbstractionImp()" << endl;
}

AbstractionImp::~AbstractionImp()
{
}

void AbstractionImp::Operation()
{
    cout<<"AbstractionImp....Operation..."<<endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA()
{
        cout << "ConcreteAbstractionImpA()" << endl;
}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA()
{
}

void ConcreteAbstractionImpA::Operation()
{
    cout<<"ConcreteAbstractionImpA...Operation..."<<endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB()
{
    cout << "ConcreteAbstractionImpB()" << endl;
}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB()
{
}

void ConcreteAbstractionImpB::Operation()
{
    cout<<"ConcreteAbstractionImpB...Operation..." << endl;
}
