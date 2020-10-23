//main.cpp
#include "Flyweight.h"
#include "FlyweightFactory.h"

using namespace std;

int main(int argc,char* argv[])
{

    // 这个享元模式 写成了工厂模式..

    // 直接通过工厂构建  
    // 这个享元不清晰
    FlyweightFactory* fc = new FlyweightFactory();
    Flyweight* fw1 = fc->GetFlyweight("hello");
    Flyweight* fw2 = fc->GetFlyweight("world!");
    Flyweight* fw3 = fc->GetFlyweight("hello");

    return 0;
}
