#include <iostream>

// 将一个请求封装为一个对象 从而使你可以用不同的请求对客户进行参数化；
// 对请求对排队或者记录请求日志，以及支持可撤销操作。


// 别名  动机 事务   在redis命令行中使用这个方式   先传入命令再次提交
//                 数据库中同样对方式   先写命令再次 提交  如果要丰富接口 那么可以考虑加入回滚

// 电灯泡
class Bulb {
  public:
    // 打开
    void TurnOn() { std::cout << "Bulb has been lit" << std::endl; }
    // 关闭
    void TurnOff() { std::cout << "Darkness!" << std::endl; }
};



class ICommand {
  public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
};



class TurnOn : public ICommand {
  public:
    TurnOn(Bulb& bulb): bulb_(bulb) {}
    void Execute() override { bulb_.TurnOn(); }
    void Undo() override { bulb_.TurnOff(); }
    void Redo() override { Execute(); }
  private:
    Bulb& bulb_;
};

class TurnOff : public ICommand {
  public:
    TurnOff(Bulb& bulb): bulb_(bulb) {}
    void Execute() override { bulb_.TurnOff(); }
    void Undo() override { bulb_.TurnOn(); }
    void Redo() override { Execute(); }
  private:

    // 这里的bulb可以写成抽象 让他四不像
    Bulb& bulb_;
};


// 远程控制器
class RemoteControl {
  public:

    // 远程控制器 欲控制灯泡 继承抽象的命令方法
    void Submit(ICommand& command) { command.Execute(); }
};

int main()
{

    // 开关模式
  Bulb bulb;

  // 用灯泡来构建 开关
  TurnOn turnOn(bulb);
  TurnOff turnOff(bulb);


  // 远程控制一下
  RemoteControl remote;
  remote.Submit(turnOn);
  remote.Submit(turnOff);
}
