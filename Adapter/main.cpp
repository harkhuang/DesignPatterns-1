#include <iostream>

/*
适配器 可以说是一个仿造模式

仿造的可以是对象  

仿造的也可以是个类,  仿造的是个类的话,需要在模式中加入
*/



class ILion {
public:
    virtual void Roar() {
		 std::cout << "I am a Lion" << std::endl;
	}


    // 不适用虚函数 不能出栈方式调用不到子类的方法
	virtual ~ILion() {
		std::cout << "~ILion()" << std::endl;
	};

};

class Hunter {
public:

    // 这是重点
    // 劣人捕获的是一个抽象对象  如果是一个具体的对象
    void Hunt(ILion& lion) {
        lion.Roar();
    }
};

class WildDog
{
public:
    void Bark() {
        std::cout << "I am a wild dog." << std::endl;
    }
};

//! now we added a new class `WildDog`, the hunter can hunt it also.
//! But we cannot do that directly because dog has a different interface.
//! To make it compatible for our hunter, we will have to create an adapter.


// 通过继承抽象接口和关联适配器方法
// 做2件事
// 让接口能被在用 ->继承 (这里运用多态去构造)
// 让用户类能正常调用关联了新的(特殊的)方法

class WildDogAdapter : public ILion {
public:
    WildDogAdapter(WildDog& dog): dog_(dog) {}
    
    void Roar()  {
        dog_.Bark();
    }

private:
    WildDog& dog_;
};

int main()
{
    WildDog dog;


    // 把野狗伪装成狮子 通过继承的方式🦁
    WildDogAdapter dogAdapter(dog);

    Hunter hunter;
    hunter.Hunt(dogAdapter);
}
