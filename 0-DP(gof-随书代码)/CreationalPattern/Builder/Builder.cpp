#include "Builder.h"
#include "Car.h"
#include <iostream>

using namespace std;

Builder::Builder()
{
}

Builder::~Builder()
{
}

JeepBuilder::JeepBuilder()
{
}

JeepBuilder::~JeepBuilder()
{
}

NissanBuilder::NissanBuilder()
{
}

NissanBuilder::~NissanBuilder()
{
}

Wheel* NissanBuilder::BuildWheel()
{
    Wheel* wheel = new Wheel(16);
    return wheel;
}

Engine* NissanBuilder::BuildEngine()
{
    Engine* engine = new Engine(85);
    return engine;
}

Body* NissanBuilder::BuildBody()
{
    Body* body = new Body("hatchback");
    return body;
}

Wheel* JeepBuilder::BuildWheel()
{
    Wheel* wheel = new Wheel(22);
    return wheel;
}

Engine* JeepBuilder::BuildEngine()
{
    Engine* engine = new Engine(400);
    return engine;
}

Body* JeepBuilder::BuildBody()
{
    Body* body = new Body("SUV");
    return body;
}
