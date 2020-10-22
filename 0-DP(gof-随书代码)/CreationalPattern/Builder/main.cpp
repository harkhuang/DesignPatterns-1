#include "Car.h"
#include "Builder.h"
#include "Director.h"
#include <iostream>

int main()
{
    Car* car;// Final product
    /* A director who controls the process */
    Director director;

    /* Concrete builders */
    JeepBuilder jeepBuilder; // no new JeepBuilder() needed
    NissanBuilder nissanBuilder;

    /* Build a Jeep */
    std::cout << "== Jeep ==" << std::endl;
    director.setBuilder(&jeepBuilder);
    // using JeepBuilder instance
    car = director.ConstructFinalProduct();
    car->specifications();

    std::cout << std::endl;

    /* Build a Nissan */
    std::cout << "== Nissan ==" << std::endl;
    director.setBuilder(&nissanBuilder);
    // using NissanBuilder instance
    car = director.ConstructFinalProduct();
    car->specifications();

    return 0;
}
