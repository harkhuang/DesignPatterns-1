#include <iostream>

// 汉堡类
class Burger {
public:


    // 包含类创建方法
    // 这里巧用 结构包含  使得汉堡自己充当director（导演）
    class BurgerBuilder;

    // Flavors 风味调料
    void showFlavors() {
        std::cout << size_;
        if (cheese_) std::cout << "-cheese";
        if (peperoni_) std::cout << "-peperoni";
        if (lettuce_) std::cout << "-lettuce";
        if (tomato_) std::cout << "-tomato";
        std::cout << std::endl;
    }
private:
    Burger(int size): size_(size) {}


    // 设置汉堡默认等属性
    int size_ = 7;
    bool cheese_ = false;
    bool peperoni_ = false;
    bool lettuce_ = false;
    bool tomato_ = false;
};




// 汉堡构建者
// 类的类  成员类中包含类 构建方法
class Burger::BurgerBuilder {
public:
    BurgerBuilder(int size) { burger_ = new Burger(size); }
    BurgerBuilder& AddCheese() { burger_->cheese_ = true; return *this; }
    BurgerBuilder& AddPepperoni() { burger_->peperoni_ = true; return *this; }
    BurgerBuilder& AddLettuce() { burger_->lettuce_ = true; return *this; }
    BurgerBuilder& AddTomato() { burger_->tomato_ = true; return *this; }



    Burger* Build() { return burger_; }
private:
    Burger* burger_;
};



class A{

public:
    class B;
};

// 我们把这段代码理解成结构体更好  这样便于理解
// 结构体 +  RAII的 + private + 构造拷贝等 = 类
class A::B{

public:
   // B(){ a_ = new A(); }
    void hi()
    {
        std::cout<< "hi \n";
    }

    //A *a_;
};

int main()
{

    A a;

    // 临时构建。
    A::B().hi();
    // 这不就是java中常用到等一种设计模式吗？？？？？？？？？？
    // spring 疯狂调用这些列举等方法 去构建 或者去事情
    // 原来背后等依赖是这个 ！！
    // 这个方法牛逼 写法第一次见到 确实感觉很清新
    // 因为方法返回的 this指针 这样我们后面的调用限额有意义
    Burger* burger = Burger::BurgerBuilder(14).AddPepperoni().AddLettuce().AddTomato().Build();
    burger->showFlavors();
}
