#ifndef _COLLEAGE_H_
#define _COLLEAGE_H_
#include <string>

using namespace std;

class Mediator;

class Colleague
{
public:
    virtual ~Colleague();
    virtual void Aciton() = 0;
    virtual void SetState(const string& sdt) = 0;
    virtual string GetState() = 0;

protected:
    Colleague();
    Colleague(Mediator* mdt);
    Mediator* _mdt; // every Colleague maintains a Mediator

private:
};

class ConcreteColleagueA:public Colleague
{
public:
    ConcreteColleagueA();
    ConcreteColleagueA(Mediator* mdt);
    ~ConcreteColleagueA();
    void Aciton();
    void SetState(const string& sdt);
    string GetState();

protected:
private:
    string _sdt;
};

class ConcreteColleagueB:public Colleague
{
public:
    ConcreteColleagueB();
    ConcreteColleagueB(Mediator* mdt);
    ~ConcreteColleagueB();
    void Aciton();
    void SetState(const string& sdt);
    string GetState();

protected:
private:
    string _sdt;
};

#endif //~_COLLEAGE_H_
