#ifndef _BUILDER_H_
#define _BUILDER_H_

class Wheel;
class Engine;
class Body;

/* Builder is responsible for constructing the smaller parts */
class Builder
{
public:
    virtual ~Builder();

    virtual Wheel* BuildWheel() = 0;
    virtual Engine* BuildEngine() = 0;
    virtual Body* BuildBody() = 0;
protected:
    Builder();
private:
};

/* Concrete Builder for Jeep SUV cars */
class JeepBuilder : public Builder
{
public:
    JeepBuilder();
    ~JeepBuilder();

    Wheel* BuildWheel();
    Engine* BuildEngine();
    Body* BuildBody();
};


/* Concrete builder for Nissan family cars */
class NissanBuilder : public Builder
{
public:
    NissanBuilder();
    ~NissanBuilder();

    Wheel* BuildWheel();
    Engine* BuildEngine();
    Body* BuildBody();
};

#endif //~_BUILDER_H_
