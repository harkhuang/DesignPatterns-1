#include <iostream>
#include <exception>
#include <string>

class Account {
public:
    // 初始化
    Account(float balance) : balance_(balance) {}
    virtual std::string GetClassName() { return "Account"; }



    // 设置后继类指针的指向  
    // 结构体就是一个指针节点
    
    void SetNext(Account* const account) { successor_ = account; }
    bool CanPay(float amount) { return balance_ >= amount; }



    // 自己调用自己  巧妙的使用递归调用   传递责任链条
    // 提供递归方式对指针进行逐个访问
    void Pay(float amountToPay) {

        // 成功支付
        if (CanPay(amountToPay)) {
            std::cout << "Paid " << amountToPay << " using " << GetClassName() << std::endl;
        } else if (successor_) { //没有成功支付
            std::cout << "Cannot pay using " << GetClassName() << ". Proceeding..." << std::endl;
           // 调用自己
            successor_->Pay(amountToPay);

        } else {
            throw "None of the accounts have enough balance.";
        }
    }
protected:

    // successor_ 后继者  这件事情干不成 交给后面的人
    Account* successor_ = nullptr;

    // 余额
    float balance_;
};

class Bank : public Account {
public:  
    Bank(float balance) : Account(balance) {}
    std::string GetClassName() override { return "Bank"; }
};

class Paypal : public Account {
public:
    Paypal(float balance) : Account(balance) {}
    std::string GetClassName() override { return "Paypal"; }
};

class Bitcoin : public Account {
public:
    Bitcoin(float balance) : Account(balance) {}
    std::string GetClassName() override { return "Bitcoin"; }
};


// 添加后继指针节点
class ZhiFuBao : public Account {
public:
	ZhiFuBao(float balance) : Account(balance) {}
	std::string GetClassName() override { return "ZhiFuBao"; }
};



// 大大问号 完全理解不了其中的算法！！！！！！！！！
int main()
{
    //! Let's prepare a chain like below:
    //! bank -> paypal -> bitcoin
    //! First priority bank
    //!   If bank can't pay then paypal
    //!   If paypal can't pay then bit coin
    
    Bank bank(100); //> Bank with balance 100
    Paypal paypal(200); //> Paypal with balance 200
    bank.SetNext(&paypal);

    Bitcoin bitcoin(300); //> Bitcoin with balance 300

    paypal.SetNext(&bitcoin);

    ZhiFuBao zhifubao(400);

    bitcoin.SetNext(&zhifubao);

    // 仅支付中做出选择
    // 选择是要过三个账户余额的 找到最合适的
    
    // 尝试从银行开始支付99元
    std::cout << "try to pay use bank first.and then...\n";
    bank.Pay(99);
    bank.Pay(199);
    bank.Pay(299);
    bank.Pay(399);


	std::cout << "try to pay use papal first.and then...\n";
    paypal.Pay(299);



}
