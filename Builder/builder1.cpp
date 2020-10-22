//
// Created by k on 2020/10/22.
//

#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    Product() {cout<< "Product "<<endl;};
    ~Product(){cout<< "~Product "<<endl;};
protected:
private:
};

class ProductPart
{
public:
    ProductPart(){ cout<< "ProductPart "<<endl;};
    ~ProductPart(){ cout<< "~ProductPart "<<endl;};
    ProductPart* BuildPart(){ return new ProductPart();}
protected:
private:
};





class Builder
{
public:
    virtual ~Builder() { cout<<"~Builder()"<<endl;};
    virtual void BuildPartA(const string& buildPara) = 0;
    virtual void BuildPartB(const string& buildPara) = 0;
    virtual void BuildPartC(const string& buildPara) = 0;
    virtual Product* GetProduct() = 0;
protected:
    Builder()  { cout<<"Builder()"<<endl;};
private:
};




class ConcreteBuilder:public Builder
{
public:
    ConcreteBuilder(){
        cout<<"ConcreteBuilder"<<endl;
    }
    ~ConcreteBuilder(){
        cout<<"~ConcreteBuilder"<<endl;
    }
    void BuildPartA(const string& buildPara){
        cout<<"Step1:Build PartA..."<<buildPara<<endl;
    };
    void BuildPartB(const string& buildPara){
        cout<<"Step1:Build PartB..."<<buildPara<<endl;
    };
    void BuildPartC(const string& buildPara){
        cout<<"Step1:Build PartC..."<<buildPara<<endl;
    };
    Product* GetProduct(){
        BuildPartA("pre-defined");
        BuildPartB("pre-defined");
        BuildPartC("pre-defined");
        return new Product();
    }
protected:
private:
};




// 核心类
class Director
{
public:
    Director(Builder* bld){
        _bld = bld;
    }
    ~Director();

    // 这个类去构建  这里等构建方法有很多  可以同时一起构建  表示各个对象之间等关联关系 在构建中去适配

    // 如果不是构建方式   去适配等化  那么我们可以使用 分别等构建方法去构建 这样显得更加的灵活
    void Construct(const string a,const string b,const string c){
        _bld->BuildPartA(a);
        _bld->BuildPartB(b);
        _bld->BuildPartC(c);
    }
protected:
private:
    Builder* _bld;
};

int main(int argc,char* argv[])
{

    // 搞出来一个导演
    Director* d = new Director(new ConcreteBuilder());

    // 导演来编排剧本
    d->Construct("a+","b+","a-");
    return 0;
}