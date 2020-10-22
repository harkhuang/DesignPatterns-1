#include "Car.h"
#include <iostream>
#include <string>

Wheel::Wheel()
{
}

Wheel::Wheel(int s)
{
    size = s;
}

Wheel::~Wheel()
{
}

Engine::Engine()
{
}

Engine::Engine(int hp)
{
    horsepower = hp;
}

Engine::~Engine()
{
}

Body::Body()
{
}

Body::Body(std::string sp)
{
    shape = sp;
}

Body::~Body()
{
}

Car::Car()
{
}

Car::~Car()
{
}

void Car::specifications()
{
    std::cout << "body:" << body->getShape() << std::endl;
    std::cout << "engine horsepower:" << engine->getHorsePower() << std::endl;
    std::cout << "tire size:" << wheels[0]->getSize() << "'" << std::endl;
}
