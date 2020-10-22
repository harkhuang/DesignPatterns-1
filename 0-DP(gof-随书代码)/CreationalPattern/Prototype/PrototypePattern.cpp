#include <iostream>

// Prototype
class Prototype
{
public:
    virtual ~Prototype(){}
    virtual Prototype* clone() const = 0;
};


// Concrete prototype
class ConcretePrototype : public Prototype
{
public:
    ConcretePrototype(int x) : x_(x){}

    ConcretePrototype(const ConcretePrototype& p) : x_(p.x_){}

    virtual ConcretePrototype* clone() const{
        return new ConcretePrototype(*this);
    }

    void setX(int x){
        x_ = x;
    }

    int getX() const{
        return x_;
    }

    void printX() const{
        std::cout << "Value :" << x_ << std::endl;
    }
private:
    int x_;
};

// Client code
void prototype_test()
{
    Prototype* prototype = new ConcretePrototype(1000);
    for (int i = 1; i < 10; i++) {
        ConcretePrototype* tempotype = static_cast<ConcretePrototype*>(prototype->clone());
        tempotype->setX(tempotype->getX() * i);
        tempotype->printX();
        delete tempotype;
    }
    delete prototype;
}


int main()
{
    prototype_test();
    return 0;
}
