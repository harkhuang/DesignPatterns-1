#include <iostream>
// 单一职责

// 超级基类
class IDoor {
public:
    virtual void GetDescription() = 0;
};

// 集成类
class WoodenDoor : public IDoor {
public:
    void GetDescription() override {
        std::cout << "I am a wooden door" << std::endl;
    }
};

// 继承类2
class IronDoor : public IDoor {
public:
    void GetDescription() override {
        std::cout << "I am a iron door" << std::endl;
    }
};


// 基类扩展适配
// 这里的方法和基类的成员有一定的联系
class IDoorFittingExpert {
public:
    virtual void GetDescription() = 0;
};

class Carpenter : public IDoorFittingExpert {
    void GetDescription() override {
        std::cout << "I can only fit wooden doors" << std::endl;
    }
};

class Welder : public IDoorFittingExpert {
    void GetDescription() override {
        std::cout << "I can only fit iron doors" << std::endl;
    }
};


// 组建工厂 工厂是一个抽象集合
class IDoorFactory {
public:
    virtual IDoor* MakeDoor() = 0;
    virtual IDoorFittingExpert* MakeFittingExpert() = 0;
};

// 抽象了两个对象  来构建实际的工厂
// 这个工厂呢 构建了两个
template <typename Door, typename DoorFittingExpert>
class DoorFactory : public IDoorFactory {
public:
    IDoor* MakeDoor() override {
        return new Door();
    }
    IDoorFittingExpert* MakeFittingExpert() override {
        return new DoorFittingExpert();
    }
};

int main()
{
    // 抽象的工厂
	// 抽象的工厂  
	// 抽象的工人
    // 抽象的产品
    // 超类工厂匹配  超类工人 生产超类产品
    // 从工厂到产品都是抽象的  
    IDoorFactory* woodenFactory = new DoorFactory<WoodenDoor, Carpenter>();
    {
        IDoor* door = woodenFactory->MakeDoor();
        IDoorFittingExpert* expert = woodenFactory->MakeFittingExpert();
        door->GetDescription();
        expert->GetDescription();
    }

    IDoorFactory* ironFactory = new DoorFactory<IronDoor, Welder>();
    {
        IDoor* door = ironFactory->MakeDoor();
        IDoorFittingExpert* expert = ironFactory->MakeFittingExpert();
        door->GetDescription();
        expert->GetDescription();
    }
}
