#include "Invoker.h"
#include "Command.h"
#include <iostream>


Invoker::Invoker(Command* cmd)
{
    _cmd = cmd;
}

Invoker::~Invoker()
{
}

void Invoker::Invoke()
{
    std::cout << "Invoker::Invoke()" << std::endl;
    _cmd->Execute();
}
