#include "Car.h"
#include "Builder.h"
#include "Director.h"
#include <iostream>

Director::Director()
{
}

Director::~Director()
{
}

void Director::setBuilder(Builder* newBuilder)
{
    builder = newBuilder;
}

Car* Director::ConstructFinalProduct()
{
    Car* car = new Car();

    car->body = builder->BuildBody();
    car->engine = builder->BuildEngine();
    car->wheels[0] = builder->BuildWheel();
    car->wheels[1] = builder->BuildWheel();
    car->wheels[2] = builder->BuildWheel();
    car->wheels[3] = builder->BuildWheel();
    return car;
}
