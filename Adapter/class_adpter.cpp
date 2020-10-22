#include <iostream>
using namespace std;

//适配接口
class Target
{
public:
	Target() {
		cout << "Target()" << endl;
	};
	virtual ~Target() {
		cout << "~Target()" << endl;
	};

	virtual void Request() {
		std::cout << "Target::Request()" << std::endl;
	};
protected:
private:
};

//适配器方法
class Adaptee
{
public:
	Adaptee() {
		cout << "Adaptee()" << endl;
	};
	~Adaptee() {
		cout << "~Adaptee()" << endl;
	};


	// 一个特别的请求方法
	void SpecificRequest() {
		std::cout << "Adaptee::SpecificRequest()" << std::endl;
	};
protected:
private:
};

// 被适配的方法
// 目的就是想在Adapter中调用一个和Target中request方法一样的方法

// 为了让类保持整洁 并且不破坏单一职责的原则 我们采用了关联的方式  在成员对象中实现了一个仿造请求方法
class Adapter :public Target
{
public:
	Adapter(Adaptee* ade) {
		std::cout << "Adapter(Adaptee* ade)" << std::endl;
		this->_ade = ade;
	};
	~Adapter() {
		std::cout << "~Adapter()" << std::endl;
	};


	// 通过关联方式的成员对象来重写调用继承的类成员
	// 重写的类对象很容易被构建了
	void Request() {
		_ade->SpecificRequest();
	}
	;
protected:
private:
	Adaptee* _ade;
};

int main(int argc, char* argv[])
{
	//用户根据类型名称自己适配
	Adaptee* ade = new Adaptee;

	// 构建的时候使用抽象类, 抽象类又是一个适配器方法类  适配方法类是一个
	Target* adt = new Adapter(ade);
	adt->Request();
	return 0;
}