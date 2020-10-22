#include "Singleton.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
    cout << "Call Singleton::Instance 1" << endl;
    Singleton* sgn = Singleton::Instance();
    cout << "Call Singleton::Instance 2" << endl;
    Singleton* sgn1 = Singleton::Instance();

    return 0;
}
