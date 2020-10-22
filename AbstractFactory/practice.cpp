//
// Created by Administrator on 2020/10/22.
//

#include <iostream>
#include <memory>
class Ishos { public: virtual void show() = 0; };
class sportShos :public Ishos {
public:
    void show() {
        std::cout << "i am Sport shoses"<<std::endl;
    }
};
class classShos :public Ishos {
public:
    void show() {
        std::cout << "i am class shoses"<<std::endl;
    }
};


class Itshirt { public: virtual void show() = 0; };
class OldTshirt :public Itshirt {
public:
    void show() {
        std::cout << "i am old T-shirt"<<std::endl;
    }
};
class newTshirt :public Itshirt {
public:
    void show() {
        std::cout << "i am new T-shirt"<<std::endl;
    }
};


class IFactory {
public:
    virtual Ishos* Makeshos() = 0;
    virtual Itshirt* Makeshirt() = 0;
};





// 工厂方法中允许了两种类型的对象进行任意个数的构建
// 如果想对这些对象进项管理 我们需要一个mannager 来进行管理

// typename 中是一个实际的类对象  已经实现的对象 并非抽象的对象
template<typename shoses, typename tshrit>
class Factory :public IFactory {
public:
    Factory() {
//         pshos = Makeshos();
//         ptshirt = Makeshirt();
    }
public:
    // 模糊的是 怎么用模版?
    Ishos * Makeshos() override { std::cout << " create shoses."; return     (Ishos *) std::make_shared <shoses>().get(); }
    Itshirt * Makeshirt()override  { std::cout << " create t-shirt."; return  (Itshirt *)  std::make_shared <tshrit>().get(); }

//
//     Ishos * Makeshos() override { std::cout << " create shoses."; return new shoses(); }
//     Itshirt * Makeshirt()override { std::cout << " create t-shirt."; return  new tshrit(); }
//
//     Ishos* pshos;
//     Itshirt* ptshirt;
};

int main()
{
    IFactory *f1 = new Factory<sportShos, newTshirt>();
    Itshirt *shirt1 = f1->Makeshirt();
    Ishos *shose1 = f1->Makeshos();
    shirt1->show();
    shose1->show();
    return 0;
}