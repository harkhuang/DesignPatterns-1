#include "Product.h"
#include <iostream>
using namespace std;

Product::Product()
{
    cout << "Product constructor..." << endl;
}

Product::~Product()
{
    cout << "~Product..." << endl;
}

ConcreteProduct::ConcreteProduct()
{
    cout<<"ConcreteProduct constructor...."<<endl;
}

ConcreteProduct::~ConcreteProduct()
{
    cout << "~ConcreteProduct..." << endl;
}
