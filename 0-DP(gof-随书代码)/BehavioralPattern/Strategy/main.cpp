#include "Context.h"
#include "Strategy.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    Strategy* ps = new ConcreteStrategyA();
    Context* pc = new Context(ps);

    pc->DoAction();
    // test ConcreteStrategyA.....

    if (NULL != pc)
        delete pc;
    if (NULL != ps)
        delete ps;
    // ~ConcreteStrategyA.....
    // ~Strategy.....
    return 0;
}
