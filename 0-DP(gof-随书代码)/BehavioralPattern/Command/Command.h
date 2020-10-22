#ifndef _COMMAND_H_
#define _COMMAND_H_

class Receiver;

class Command
{
public:
    virtual ~Command();
    virtual void Execute() = 0;

protected:
    Command();

private:
};

class ConcreteCommandA:public Command
{
public:
    ConcreteCommandA(Receiver* rev);
    ~ConcreteCommandA();
    void Execute();

protected:
private:
    Receiver* _rev;

};

class ConcreteCommandB:public Command
{
public:
    ConcreteCommandB(Receiver* rev);
    ~ConcreteCommandB();
    void Execute();

protected:
private:
    Receiver* _rev;

};

#endif //~_COMMAND_H_
