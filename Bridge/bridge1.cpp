#include <iostream>
using namespace std;



/// 抽象行为
class AbstractionImp
{
public:
    virtual ~AbstractionImp();
    virtual void Operation() = 0;

protected:
    AbstractionImp();
private:
};

class Abstraction
{
public:
    virtual ~Abstraction();
    virtual void Operation() = 0;
protected:
    Abstraction();
private:
};

class RefinedAbstraction:public Abstraction
{
public:
    RefinedAbstraction(AbstractionImp* imp);
    ~RefinedAbstraction();
    void Operation();
protected:
private:
    AbstractionImp* _imp;
};



class ConcreteAbstractionImpA:public AbstractionImp
{
public:
    ConcreteAbstractionImpA();
    ~ConcreteAbstractionImpA();
    virtual void Operation();

protected:
private:
};

class ConcreteAbstractionImpB:public AbstractionImp
{
public:
    ConcreteAbstractionImpB();
    ~ConcreteAbstractionImpB();
    virtual void Operation();

protected:
private:
};


Abstraction::Abstraction()
{
}

Abstraction::~Abstraction()
{
}

RefinedAbstraction::RefinedAbstraction(AbstractionImp* imp)
{
    _imp = imp;
}

RefinedAbstraction::~RefinedAbstraction()
{
}

void RefinedAbstraction::Operation()
{
    _imp->Operation();
}



AbstractionImp::AbstractionImp()
{
    cout << "AbstractionImp()" << endl;
}

AbstractionImp::~AbstractionImp()
{
}

void AbstractionImp::Operation()
{
    cout<<"AbstractionImp....Operation..."<<endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA()
{
    cout << "ConcreteAbstractionImpA()" << endl;
}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA()
{
}

void ConcreteAbstractionImpA::Operation()
{
    cout<<"ConcreteAbstractionImpA...Operation..."<<endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB()
{
    cout << "ConcreteAbstractionImpB()" << endl;
}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB()
{
}

void ConcreteAbstractionImpB::Operation()
{
    cout<<"ConcreteAbstractionImpB...Operation..." << endl;
}



// 延迟对象的构建一直到子类出现

int main(int argc,char* argv[])
{
    AbstractionImp* imp = new ConcreteAbstractionImpA();

    Abstraction* abs = new RefinedAbstraction(imp);

    abs->Operation();

    delete abs;
    delete imp;

    return 0;
}
