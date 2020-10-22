#ifndef _DECORATOR_H_
#define _DECORATOR_H_

// Can not be abstract class, because Decorator will keep an instance of Component
class Component
{
public:
    virtual ~Component();
    virtual void Operation();

protected:
    Component();

private:
};

// This is the default behaviour
class ConcreteComponent:public Component
{
public:
    ConcreteComponent();
    ~ConcreteComponent();
    void Operation();

protected:
private:
};

// 1. keep an instance of component
// 2. sub-classed to add new behavior
class Decorator:public Component
{
public:
    Decorator(Component* com);
    virtual ~Decorator();
    void Operation();

protected:
    Component* _com;

private:
};

class ConcreteDecorator:public Decorator
{
public:
    ConcreteDecorator(Component* com);
    ~ConcreteDecorator();
    void Operation();
    void AddedBehavior();

protected:
private:
};

#endif //~_DECORATOR_H_
