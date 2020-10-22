#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

class Builder;
class Car;

/* Director is responsible for the whole process */
class Director
{
public:
    Director();
    ~Director();
    Car* ConstructFinalProduct();
    void setBuilder(Builder* newBuilder);
protected:
private:
    Builder* builder;

};

#endif //~_DIRECTOR_H_
