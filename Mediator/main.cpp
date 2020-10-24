#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
// 中介者设计模式
class User;

class IChatRoomMediator {
public:
    virtual void ShowMessage(const User& user, const std::string& message) = 0;
};

class ChatRoom : public IChatRoomMediator {
public:
    void ShowMessage(const User& user, const std::string& message) override;
};

class User {
public:
    User(const std::string& name, IChatRoomMediator& chatMediator): name_(name), chatMediator_(chatMediator) {}
    const std::string& GetName() const { return name_; }
    void Send(const std::string& message) { chatMediator_.ShowMessage(*this, message); }
private:
    std::string name_;
    IChatRoomMediator& chatMediator_;
};







// 聊天室对用户消息进行类一层封装
void ChatRoom::ShowMessage(const User &user, const std::string &message) {
    std::time_t now = std::time(nullptr);
    std::cout << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << "[" << user.GetName() << "]: " << message << std::endl;
}

int main()
{
    // 聊天室
    ChatRoom mediator;


    // 注册聊天室用户
    User john("John Doe", mediator);
    User jane("Jane Doe", mediator);

    // 用户具备发送消息的功能
    john.Send("Hi, there!");
    jane.Send("Hey!");



    // 细致的深入里面思考  用户为何具备发送消息的功能
    // 用户是怎么样和个体人关联的
    // 实体的个人 -> 用户 ->  聊天室


    // 这里的抽象是聊天室  聊天室由成员用户
    // 实体人具备很多属性  聊天室中仅仅关心的是 聊天 撮合的属性

    // 抽象聊天室 里面包含用户成员 ->error  因为在实例化过程中我们看到的只有用户  用户的属性中包含了聊天室

    // 聊天室仅仅是其中一种媒介

    // 再次抽象  用户类中包含聊天室具柄
    // 用户可以发送消息？// 如此设计是否可以？



}
