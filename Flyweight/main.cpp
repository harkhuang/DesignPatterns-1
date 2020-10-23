#include <iostream>
#include <string>
#include <unordered_map>

// Anything that will be cached is flyweight.
// Types of tea here will be flyweights.
class KarakTea {};

// 享元模式最大的特点就是



class TeaMaker {
public:
    KarakTea* Make(const std::string& preference) {

        // 查询该记录是否存在  不存在则插入 并且返回该对象
        if (availableTea_.find(preference) == availableTea_.end())
            // 如果不存在在这里构建
            availableTea_.insert({preference, new KarakTea()});

        return availableTea_.at(preference);
    }

private:

    // 记录享元模式内容
    // 记录能够做的奶茶的种类?

    // 记录了该之怎对象
    std::unordered_map<std::string, KarakTea*> availableTea_;
};




// 没有继承只有关联
class TeaShop {
public:
    TeaShop(TeaMaker& teaMaker): teaMaker_(teaMaker) {}

    // 点菜  点单
    void TakeOrder(const std::string& teaType, int table) {
        orders_[table] = teaMaker_.Make(teaType);
    }

    // 服务
    void Serve() {
        for(auto order : orders_)
            std::cout << "Serving tea to table# " << order.first << std::endl;
    }

private:

    // int 表示座位号码    karak表示茶的种类
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
   
    getchar();
}
