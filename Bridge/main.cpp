#include <iostream>
#include <string>


// 抽象和实现分离

// 抽象出主题 怎么越看越像工厂？
class ITheme {
public:
    virtual std::string GetColor() = 0;
};

class DarkTheme : public ITheme {
public:
    std::string GetColor() override { return "Dark Black"; }
};

class LightTheme : public ITheme {
public:
    std::string GetColor() override { return "Off white"; }
};

class AquaTheme : public ITheme {
public:
    std::string GetColor() override { return "Light blue"; }
};




// 前面用到的继承很像工厂  继承仅仅是工厂的一部分属性而已
// 该类也是用户类的超类 使用抽象类做为成员对象
// 使得该类具备类更多变化的空间
class IWebPage {
public:
    // 构建该基类需要传递一个抽象主题
    // 需要一个具象的对象才能对该抽象类实例化
    IWebPage(ITheme& theme) : theme_(theme) {}
    virtual std::string GetContent() = 0;
protected:
    ITheme& theme_;
};

// 实力化 关于页面
// 有着一个抽象主题      这个主题只有在用户层才真的被实力话
class About : public IWebPage {
public:
    About(ITheme& theme) : IWebPage(theme) {}
    std::string GetContent() override {
        return "About page in " + theme_.GetColor();
    }
};


// 延迟了 主题的构建
// 延迟构建 利用抽象类对象的定义
// 可以一层层的延迟  直到我们希望传递进去实体类对象进去为止
// 这里举例的延迟 一直到用户层代码  由用户决定到底定义是什么主题
class Careers : public IWebPage {
public:
    Careers(ITheme& theme) : IWebPage(theme) {}
    std::string GetContent() override {
        return "Careers page in " + theme_.GetColor();
    }
};

int main()
{

    // 可以让多个实现类自由组合
    DarkTheme darkTheme;
    About about(darkTheme);
    std::cout << about.GetContent() << std::endl;


    // 这是一个亮色主题
    LightTheme lightTheme;
    Careers careers(lightTheme);
    std::cout << careers.GetContent() << std::endl;
}
