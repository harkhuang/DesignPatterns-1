#include "Memento.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    Originator* o = new Originator();
    o->SetState("old"); // memo the previous status
    o->PrintState();
    Memento* m = o->CreateMemento(); // memo the state

    o->SetState("new"); // modify the status
    o->PrintState();

    o->RestoreToMemento(m); // restore the state to the state before modifying
    o->PrintState();

    return 0;
}
