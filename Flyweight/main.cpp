#include <iostream>
#include <string>
#include <unordered_map>

// Anything that will be cached is flyweight.
// Types of tea here will be flyweights.
class KarakTea {};

// 享元模式最大的特点就是保存的是对象的指针
// 奶茶师唯一的技能是制造奶茶，每做一种他就在技能本中领悟一种技能
class TeaMaker {
public:

    //  制作奶茶 并且记录
    KarakTea* Make(const std::string& preference) {

        // 查询该记录是否存在  不存在则插入 并且返回该对象
        if (availableTea_.find(preference) == availableTea_.end())
            // 如果不存在在这里构建
            // 每个点过的奶茶都有一个对应的karakTea与之对应
            availableTea_.insert({preference, new KarakTea()});

        // 返回对应位置的成员
        return availableTea_.at(preference);
    }

private:

    // 记录享元模式内容
    // 记录能够做的奶茶的种类?
    // 根据对象名称记录的可以服务的查种类
    // 奶茶和奶茶师店关系是奶茶名字 奶茶种类
    std::unordered_map<std::string, KarakTea*> availableTea_;
};




// 没有继承只有关联
class TeaShop {
public:

    // 开奶茶店 必须要有个奶茶师
    TeaShop(TeaMaker& teaMaker): teaMaker_(teaMaker) {}

    // 点单服务
    void TakeOrder(const std::string& teaType, int table) {

        // 奶茶师
        orders_[table] = teaMaker_.Make(teaType);
    }

    // 服务
    void Serve() {
        //  遍历这个订单  查看客人都点了什么
        for(auto order : orders_)
            std::cout << "Serving tea to table# " << order.first << std::endl;
    }

private:

    // int 表示座位号码    karak表示茶的种类
    // 奶茶和奶茶店店关系是座位号关系
    std::unordered_map<int, KarakTea*> orders_;
    TeaMaker& teaMaker_;
};

int main()
{
    // 奶茶师
    TeaMaker teaMaker;
    //  奶茶店
    TeaShop shop(teaMaker);
    // 奶茶店创建奶茶
    // 奶茶店享受奶茶师的技能和工具  
    // 通过奶茶店制造各种奶茶
    shop.TakeOrder("less sugar", 1);
	shop.TakeOrder("more milk", 2);
	shop.TakeOrder("less milk",3);
    shop.TakeOrder("without sugar", 5);
    shop.Serve();


}
