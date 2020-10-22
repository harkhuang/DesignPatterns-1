//main.cpp
#include "Component.h"
#include "Composite.h"
#include "Leaf.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    Leaf* l1 = new Leaf();
    l1->Operation();
    Leaf* l2 = new Leaf();
    l2->Operation();
    Leaf* l3 = new Leaf();
    l3->Operation();

    Composite* com = new Composite();
    com->Add(l1);
    com->Add(l2);
    com->Add(l3);
    com->Operation();

    Component* ll = com->GetChild(0);
    ll->Operation();

    com->Remove(ll);
    com->Operation();

    return 0;
}
