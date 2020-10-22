#include "Template.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    AbstractClass* p1 = new ConcreteClass1();
    AbstractClass* p2 = new ConcreteClass2();

    p1->TemplateMethod();
    // ConcreteClass1...PrimitiveOperation1
    // ConcreteClass1...PrimitiveOperation2
    p2->TemplateMethod();
    // ConcreteClass2...PrimitiveOperation1
    // ConcreteClass2...PrimitiveOperation2

    delete p1;
    delete p2;

    return 0;
}
