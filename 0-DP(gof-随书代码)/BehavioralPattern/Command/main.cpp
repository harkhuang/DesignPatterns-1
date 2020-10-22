#include "Command.h"
#include "Invoker.h"
#include "Receiver.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    Receiver* rev = new Receiver();
    Command* cmdA = new ConcreteCommandA(rev);
    Command* cmdB = new ConcreteCommandB(rev);
    Invoker* invA = new Invoker(cmdA);
    Invoker* invB = new Invoker(cmdB);
    invA->Invoke();
    invB->Invoke();

    delete rev;
    delete cmdA;
    delete cmdB;
    delete invA;
    delete invB;

    return 0;

}
