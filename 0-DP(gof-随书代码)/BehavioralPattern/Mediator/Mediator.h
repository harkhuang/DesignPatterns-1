#ifndef _MEDIATOR_H_
#define _MEDIATOR_H_

class Colleague;

class Mediator
{
public:
    virtual ~Mediator();
    virtual void DoActionFromAtoB() = 0;
    virtual void DoActionFromBtoA() = 0;

protected:
    Mediator();
private:
};

class ConcreteMediator:public Mediator
{
public:
    ConcreteMediator();
    ConcreteMediator(Colleague* clgA,Colleague* clgB);
    ~ConcreteMediator();
    void SetConcreteColleagueA(Colleague* clgA);
    void SetConcreteColleagueB(Colleague* clgB);
    Colleague* GetConcreteColleagueA();
    Colleague* GetConcreteColleagueB();
    void IntroColleague(Colleague* clgA,Colleague* clgB);
    void DoActionFromAtoB();
    void DoActionFromBtoA();

protected: private:
    // ConcreteMediator maintains all the colleagues,
    // then collaborate the communications among ConcreteColleagues
    Colleague* _clgA;
    Colleague* _clgB;
};

#endif //~_MEDIATOR_H
