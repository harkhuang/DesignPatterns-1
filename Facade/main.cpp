#include <iostream>

class Computer {
public:
    void GetElectricShock() { std::cout << "Ouch!" << std::endl; }
    void MakeSound() { std::cout << "Beep beep!" << std::endl; }
    void ShowLoadingScreen() { std::cout << "Loading..." << std::endl; }
    void Bam() { std::cout << "Ready to be used!" << std::endl; }
    void CloseEverything() { std::cout << "Bup bup bup buzzzz!" << std::endl; }
    void Sooth() { std::cout << "Zzzzz" << std::endl; }
    void PullCurrent() { std::cout << "Haaah!" << std::endl; }
};

class ComputerFacade {
public:
    ComputerFacade(Computer& computer): computer_(computer) {}
    void TurnOn() {
        computer_.GetElectricShock();
        computer_.MakeSound();
        computer_.ShowLoadingScreen();
        computer_.Bam();
    }
    void TurnOff() {
        computer_.CloseEverything();
        computer_.PullCurrent();
        computer_.Sooth();
    }

private:
    Computer& computer_;
};



//门面模式被我用的最多了  面向过程写一堆   然后打包到一起个名字 美其名曰设计模式


//举例编译器
//最后暴露的都是一样的



int main()
{
    Computer real_computer;
    ComputerFacade computer(real_computer);
    computer.TurnOn();
    computer.TurnOff();
}
