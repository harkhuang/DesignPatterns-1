#include "Context.h"
#include "State.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
    State* stA = new ConcreteStateA();
    Context* con = new Context(stA);
    con->OprationInterface();
    // ConcreteStateA::OperationInterface......

    State* stB = new ConcreteStateB();
    con = new Context(stB);
    con->OprationInterface();
    // ConcreteStateB::OperationInterface......
    con->OprationInterface();
    // ConcreteStateB::OperationInterface......
    if (con != NULL) delete con;
    if (stA != NULL) stA = NULL;
    if (stB != NULL) stB = NULL;
    return 0;
}
