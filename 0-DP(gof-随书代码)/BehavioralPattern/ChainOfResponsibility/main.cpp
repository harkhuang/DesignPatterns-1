#include "Handle.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    Handle* h1 = new ConcreteHandleA();
    Handle* h2 = new ConcreteHandleB();
    h1->SetSuccessor(h2);
    h1->HandleRequest();

    delete h1; // h2 will be deleted by h1 as delete successor

    return 0;
}
