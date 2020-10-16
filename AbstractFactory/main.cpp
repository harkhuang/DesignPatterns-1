#include <iostream>

class IDoor {
public:
    virtual void GetDescription() = 0;
};

class WoodenDoor : public IDoor {
public:
    void GetDescription() override {
        std::cout << "I am a wooden door" << std::endl;
    }
};

class IronDoor : public IDoor {
public:
    void GetDescription() override {
        std::cout << "I am a iron door" << std::endl;
    }
};

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

class IDoorFactory {
public:
    virtual IDoor* MakeDoor() = 0;
    virtual IDoorFittingExpert* MakeFittingExpert() = 0;
};

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
    // 超类工厂 匹配 超类工人  生产超类产品
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
