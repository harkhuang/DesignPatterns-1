//Composite.cpp
#include "Composite.h"
#include "Component.h"
#include <iostream>

#ifndef NULL
#define NULL 0 //define NULL POINTOR
#endif

using namespace std;

Composite::Composite()
{
    //vector<Component*>::iterator itend = comVec.begin();
}

Composite::~Composite()
{

}

void Composite::Operation()
{
    cout << "Composite::Operation()" << endl;
    vector<Component*>::iterator comIter = comVec.begin();

    for (;comIter != comVec.end();comIter++) {
        (*comIter)->Operation();
    }
}

void Composite::Add(Component* com)
{
    cout << "Composite::Add(com)" << endl;
    comVec.push_back(com);
}

void Composite::Remove(Component* com)
{
    cout << "Composite::Remove(com)" << endl;
    for(vector<Component*>::iterator it=comVec.begin(); it != comVec.end(); it++) {
        if(com == *it)
            comVec.erase(it);
    }
}

Component* Composite::GetChild(int index)
{
    cout << "Composite::GetChild(" << index << ")" << endl;
    return comVec[index];
}
