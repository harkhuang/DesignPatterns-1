#include <iostream>
#include <string>
#include <vector>
#include <functional>

 // ----------------------------------------------------------------
 // 





// 工作展示牌 非动词

// 座位m和v的成员对象  为二者建立联系

// dao层  可以这么理解
class JobTable {
public:
    JobShow(const std::string& title): title_(title) {}
    const std::string& GetTitle() const { return title_; }
private:
    std::string title_;
};




// 抽离了求职者的共性
// 在在有工作发布的时候 会有对应的响应
class IObserver {
public:
    virtual void OnJobPoed(const JobShow& job) = 0;
};

// 通过继承基类方法   关联了modle类   在有件事情发生后
class JobSeeker : public IObserver {
public:
    JobSeeker(const std::string& name): name_(name) {}
    // 被回调
    void OnJobPosted(const JobPost &job) override {
        std::cout << "Hi " << name_ << "! New job posted: " << job.GetTitle() << std::endl;
    }
private:
    std::string name_;
};




// 抽象了服务层的对象
// 服务层对工作有几种操作,  可以添加工作
class IObservable {
public:
    virtual void Attach(IObserver& observer) = 0;
    virtual void AddJob(const JobPost& jobPosting) = 0;
protected:
    virtual void Notify(const JobPost& jobPosting) = 0;
};








class JobPostings : public IObservable {
public:
    void Attach(IObserver& observer) override {
        observers_.push_back(observer);
    }



    // 使得 m v  c
    void AddJob(const JobPost &jobPosting) override {

        // 添加工作后 我们做一次 通知方法
        Notify(jobPosting);

        // do other things .. 

    }
private:
    void Notify(const JobPost &jobPosting) override {
        for (IObserver& observer : observers_)

        // 逐个调用 第三方的内置回调方法..
            observer.OnJobPosted(jobPosting);
    }




     /// 
    std::vector<std::reference_wrapper<IObserver>> observers_;
};

int main()
{
    // 求职者
    JobSeeker johnDoe("John Doe");
    JobSeeker janeDoe("Jane Doe");

    // 工作发布者
    JobPostings jobPostings;
    
    // 注册两个人
    jobPostings.Attach(johnDoe);
    jobPostings.Attach(janeDoe);

// 添加一个工作发布工作
// jobadd 负责通知各个相关的注册

// 对比mvc 这里的添加方法相当于modle方法做类修改或者调整  在对应的  view展现中得到体现  可能是通知  也可能是对应删除 

//  这里通知相应必须展示的方法  
// 即时通知是必然的   点那个modle有类调整后  但是 我们可以通过控制修改对应的第三方内容

    // 在贴士版中添加工作.
    jobPostings.AddJob(JobPost("Software Engineer"));


// 构建方式?
// 求职者类 , 收到消息方法. 收到消息方法
// 工作发布者 1.通知已经注册第三方  2.工作修改方法
// 接口设计  发布工作     通知各路求职者
// 






}
