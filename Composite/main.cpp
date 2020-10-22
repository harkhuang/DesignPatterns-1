#include <iostream>
#include <string>
#include <vector>

// 意图：将对象组合诚树形结构以表示部分整体 的层次结构。
// 对使得用户单个对象组合对下岗对使用具有一致性。。。。

// 雇员 薪水抽象    名字抽象
class Employee {
public:
    Employee(const std::string& name, float salary): name_(name), salary_(salary) {}
    virtual std::string GetName() { return name_; }
    virtual float GetSalary() { return salary_; }

protected:
    float salary_;
    std::string name_;
};


//
class Developer : public Employee {
public:
    Developer(const std::string& name, float salary) : Employee(name, salary) {}
};

class Designer : public Employee {
public:
    Designer(const std::string& name, float salary) : Employee(name, salary) {}
};



// 机构
class Organization {
public:
    void AddEmployee(const Employee& employee) {
        employees_.push_back(employee);
    }
    float GetNetSalaries() {
        float net_salary = 0;
        for (auto&& employee : employees_) {
            net_salary += employee.GetSalary();
        }
        return net_salary;
    }

private:
    std::vector<Employee> employees_;
};



int main()
{
    Developer john("John Doe", 12000);
    Designer jane("Jane Doe", 15000);

    Organization org;
    org.AddEmployee(john);
    org.AddEmployee(jane);

    std::cout << "Net salaries: " << org.GetNetSalaries() << std::endl;
}
