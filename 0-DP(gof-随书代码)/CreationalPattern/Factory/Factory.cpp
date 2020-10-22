#include "Factory.h"
#include "Product.h"
#include <iostream>
using namespace std;

Factory::Factory()
{
    cout << "Factory constructor..." << endl;
}

Factory::~Factory()
{
    cout << "~Factory..." << endl;
}

ConcreteFactory::ConcreteFactory()
{
    cout<<"ConcreteFactory(extending Factory) constructor....."<<endl;
}

ConcreteFactory::~ConcreteFactory()
{
    cout << "~ConcreteFactory..." << endl;
}

/**
 * The interface for creating objects can be named as Create***Product(), for easy understanding
 */
Product* ConcreteFactory::CreateProduct()
{
    return new ConcreteProduct();
}
