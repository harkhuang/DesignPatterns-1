#include "Subject.h"
#include "Observer.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    Subject* sub = new ConcreteSubject();
    Observer* o1 = new ConcreteObserverA(sub);
    Observer* o2 = new ConcreteObserverB(sub);

    sub->Notify();  // initial is NULL status

    sub->SetState("first");
    sub->Notify();
    sub->SetState("second");
    sub->Notify();
    sub->SetState("third"); // can also call by Observer
    sub->Notify();

    return 0;
}
