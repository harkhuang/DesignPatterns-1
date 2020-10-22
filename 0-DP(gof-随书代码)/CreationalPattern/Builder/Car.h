#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>

/* Car parts */
class Wheel
{
public:
    Wheel();
    Wheel(int s);
    ~Wheel();
    int getSize(){return size;}

private:
    int size;
};


class Engine
{
public:
    Engine();
    Engine(int hp);
    ~Engine();
    int getHorsePower() { return horsepower; }

private:
    int horsepower;
};


class Body
{
public:
    Body();
    Body(std::string sp);
    ~Body();
    std::string getShape() { return shape; }
private:
    std::string shape;
};


/* Final product -- a car */
class Car
{
public:
    Car();
    ~Car();

    Wheel*   wheels[4];
    Engine*  engine;
    Body* body;
    void specifications();
};

#endif //~_CAR_H_
