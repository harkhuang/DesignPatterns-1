#include "Command.h"
#include "Receiver.h"
#include <iostream>

Command::Command()
{
}

Command::~Command()
{
}

ConcreteCommandA::ConcreteCommandA(Receiver* rev)
{
    this->_rev = rev;
}

ConcreteCommandA::~ConcreteCommandA()
{
}

void ConcreteCommandA::Execute()
{
    std::cout << "ConcreteCommandA::Execute()" << std::endl;

    // execute commands of receiver
    _rev->ActionA();
}

ConcreteCommandB::ConcreteCommandB(Receiver* rev)
{
    this->_rev = rev;
}

ConcreteCommandB::~ConcreteCommandB()
{
}

void ConcreteCommandB::Execute()
{
    std::cout << "ConcreteCommandB::Execute()" << std::endl;
    // execute commands of receiver
    _rev->ActionB();
}
