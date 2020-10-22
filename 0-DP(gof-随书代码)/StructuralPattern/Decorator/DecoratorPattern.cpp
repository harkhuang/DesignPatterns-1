#include <iostream>
#include <string>

// Abstract base class
// The abstract Coffee class defines the functionality of Coffee implemented by decorator
struct Coffee
{
    virtual double getCost() = 0;
    // returns the cost of the coffee
    virtual std::string getIngredients() = 0;
    // returns the ingredients of the coffee
    virtual ~Coffee() = 0;
};

inline Coffee::~Coffee(){}

// SimpleCoffee class.
// extension of a simple coffee without any extra ingredients
struct SimpleCoffee : Coffee
{
    double getCost(){
        return 1.0;
    }

    std::string getIngredients(){
        return "Coffee";
    }
};

// Decorators
// Decorator Milk that adds milk to coffee
struct MilkDecorator : Coffee
{
public:
    MilkDecorator(Coffee* basicCoffee) : basicCoffee_(basicCoffee){ }

    double getCost(){
        // providing methods defined in the abstract superclass
        return basicCoffee_->getCost() + 0.5;
    }

    std::string getIngredients(){
        return basicCoffee_->getIngredients() + ", " + "Milk";
    }

private:
    Coffee* basicCoffee_;
};


// Decorator Whip that adds whip to coffee
struct WhipDecorator : Coffee
{
public:
    WhipDecorator(Coffee* basicCoffee) : basicCoffee_(basicCoffee) { }

    double getCost(){
        return basicCoffee_->getCost() + 0.7;
    }

    std::string getIngredients(){
        return basicCoffee_->getIngredients() + ", " + "Whip";
    }

private:
    Coffee* basicCoffee_;

};


//Test program
int main()
{
    SimpleCoffee s;
    std::cout << "Cost: " << s.getCost() << "; Ingredients: " << s.getIngredients() << std::endl;

    MilkDecorator m(&s);
    std::cout << "Cost: " << m.getCost() << "; Ingredients: " << m.getIngredients() << std::endl;

    WhipDecorator w(&s);
    std::cout << "Cost: " << w.getCost() << "; Ingredients: " << w.getIngredients() << std::endl;

    // Note that you can stack decorators:
    MilkDecorator m2(&w);
    std::cout << "Cost: " << m2.getCost() << "; Ingredients: " << m2.getIngredients() << std::endl;
}
