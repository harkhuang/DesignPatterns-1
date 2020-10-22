//Component.cpp

#include "Component.h"
#include <iostream>
using namespace std;

Component::Component()
{
    cout << "Component::Component()" << endl;
}

Component::~Component()
{

}

void Component::Add(const Component& com)
{
    cout << "Component::Add(com)" << endl;
}

Component* Component::GetChild(int index)
{
    cout << "Component::GetChild(index)" << endl;
    return 0;
}

void Component::Remove(const Component& com)
{
    cout << "Component::Remove(com)" << endl;
}
