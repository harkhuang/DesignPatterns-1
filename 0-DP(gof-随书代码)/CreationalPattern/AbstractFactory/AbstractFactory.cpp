//AbstractFactory.cpp
#include "AbstractFactory.h"
#include "Product.h"
#include <iostream>

using namespace std;

AbstractFactory::AbstractFactory()
{
    cout << "AbsractFacotry()..." << endl;
}

AbstractFactory::~AbstractFactory()
{
    cout << "~AbsractFacotry()..." << endl;
}

ConcreteFactory1::ConcreteFactory1()
{
    cout << "  ConcreteFacotry1()..." << endl;
}

ConcreteFactory1::~ConcreteFactory1()
{
    cout << "~ConcreteFacotry1()..." << endl;
}

AbstractProductA* ConcreteFactory1::CreateProductA()
{
    return new ProductA1();
}

AbstractProductB* ConcreteFactory1::CreateProductB()
{
    return new ProductB1();
}

ConcreteFactory2::ConcreteFactory2()
{
    cout << "  ConcreteFacotry2()..." << endl;
}
ConcreteFactory2::~ConcreteFactory2()
{
    cout << "~ConcreteFacotry2()..." << endl;
}

AbstractProductA* ConcreteFactory2::CreateProductA()
{
    return new ProductA2();
}

AbstractProductB* ConcreteFactory2::CreateProductB()
{
    return new ProductB2();
}
