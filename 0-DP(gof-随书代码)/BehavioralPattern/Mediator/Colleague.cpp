#include "Mediator.h"
#include "Colleague.h"
#include <iostream>

using namespace std;

Colleague::Colleague()
{
}

Colleague::Colleague(Mediator* mdt)
{
    this->_mdt = mdt;
}

Colleague::~Colleague()
{
}

ConcreteColleagueA::ConcreteColleagueA()
{
}

ConcreteColleagueA::~ConcreteColleagueA()
{
}

ConcreteColleagueA::ConcreteColleagueA(Mediator* mdt):Colleague(mdt)
{
}

string ConcreteColleagueA::GetState()
{
    return _sdt;
}

void ConcreteColleagueA::SetState(const string& sdt)
{
    _sdt = sdt;
}

void ConcreteColleagueA::Aciton()
{
    _mdt->DoActionFromAtoB();
    cout<<"State of ConcreteColleagueB:"<<" "<<this->GetState()<<endl;
}

ConcreteColleagueB::ConcreteColleagueB()
{
}

ConcreteColleagueB::~ConcreteColleagueB()
{
}

ConcreteColleagueB::ConcreteColleagueB(Mediator* mdt):Colleague(mdt)
{
}

void ConcreteColleagueB::Aciton()
{
    _mdt->DoActionFromBtoA();
    cout<<"State of ConcreteColleagueB:"<<" "<<this->GetState()<<endl;
}

string ConcreteColleagueB::GetState()
{
    return _sdt;
}

void ConcreteColleagueB::SetState(const string& sdt)
{
    _sdt = sdt;
}
