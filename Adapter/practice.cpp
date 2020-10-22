//
// Created by Administrator on 2020/10/22.
//

#include <iostream>
#include <memory>
class Ishos { public: virtual void show() = 0; };
class sportShos :public Ishos {
public:
    void show() {
        std::cout << "i am Sport shoses" << std::endl;
    }
};
class classShos :public Ishos {
public:
    void show() {
        std::cout << "i am class shoses" << std::endl;
    }
};


class Itshirt { public: virtual void show() = 0; };
class OldTshirt :public Itshirt {
public:
    void show() {
        std::cout << "i am old T-shirt" << std::endl;
    }
};
class newTshirt :public Itshirt {
public:
    void show() {
        std::cout << "i am new T-shirt" << std::endl;
    }
};


// 工厂方法中允许了两种类型的对象进行任意个数的构建
// 如果想对这些对象进项管理 我们需要一个mannager 来进行管理

// typename 中是一个实际的类对象  已经实现的对象 并非抽象的对象
template<typename shoses, typename tshrit>
class Factory {

public:
    // 模糊的是 怎么用模版?



    // 这里如果使用智能指针  刚创建完 就被释放了
    // 引用计数功能发现没有人引用这个智能指针 , 因为这个指针对外暴露的不是一个智能指针的接口
//     Ishos * Makeshos() { std::cout << " create shoses."; return    std::make_shared <shoses>().get(); }
//     Itshirt * Makeshirt() { std::cout << " create t-shirt."; return std::make_shared <tshrit>().get(); }



    ///  ok   使用智能指针管理 构建的对象单元 .
    std::shared_ptr <shoses>   Makeshos() { std::cout << " create shoses."; return    std::make_shared <shoses>(); }
    std::shared_ptr <tshrit>  Makeshirt() { std::cout << " create t-shirt."; return std::make_shared <tshrit>(); }
//          Ishos * Makeshos()  { std::cout << " create shoses."; return new shoses(); }
//          Itshirt * Makeshirt() { std::cout << " create t-shirt."; return  new tshrit(); }
};
//
//template<typename shoses, typename tshrit>
//class Factory :public IFactory {
//public:
//    Factory() {
////         pshos = Makeshos();
////         ptshirt = Makeshirt();
//    }
//public:
//    // 模糊的是 怎么用模版?
//    Ishos * Makeshos() override { std::cout << " create shoses."; return     (Ishos *) std::make_shared <shoses>().get(); }
//    Itshirt * Makeshirt()override  { std::cout << " create t-shirt."; return  (Itshirt *)  std::make_shared <tshrit>().get(); }
//
////
////     Ishos * Makeshos() override { std::cout << " create shoses."; return new shoses(); }
////     Itshirt * Makeshirt()override { std::cout << " create t-shirt."; return  new tshrit(); }
////
////     Ishos* pshos;
////     Itshirt* ptshirt;
//};
//

int main()
{
    Factory<sportShos, newTshirt> f1 =  Factory<sportShos, newTshirt>();
    auto shirt1 = f1.Makeshirt();
    auto shose1 = f1.Makeshos();
    shirt1->show();
    shose1->show();
    return 0;
}