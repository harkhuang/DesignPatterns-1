#include <iostream>
#include <string>
#include <memory>

// 记事本设计模式

class EditorMemento {
public:
    EditorMemento(const std::string& content): content_(content) {}
    const std::string& GetContent() const { return content_; }
private:
    std::string content_;
};

class Editor {

    // 定义一种类型




    //  typedef std::shared_ptr<EditorMemento>  MementoType;
    using MementoType = std::shared_ptr<EditorMemento>;    // 两种方式等价的。
public:
    void Type(const std::string& words) { content_ += " " + words; }
    const std::string& GetContent() const { return content_; }

    // 完全记录当时的一种状态
    // 这个状态可以比较复杂 但是用例中仅仅是一个比较长的字符串



    MementoType Save() { return std::make_shared<EditorMemento>(content_); }


    // 重制我们的记录类型

    void Restore(MementoType memento) { content_ = memento->GetContent(); }
private:
    std::string content_;
};

int main()
{
    // 有个记事本
    Editor editor;
    //! Type some stuff
    editor.Type("This is the first sentence.");
    editor.Type("This is second.");
    //! Save the state to restore to : This is the first sentence. This is second.
    auto saved = editor.Save();
    //! Type some more
    editor.Type("And this is third.");
    std::cout << editor.GetContent() << std::endl;

    // 回到saved的状态（比如redis 持久化的一次回滚）
    editor.Restore(saved);
    std::cout << editor.GetContent() << std::endl;




    // 思考：
    //********************************
    //** 记事本中可能仅仅是一个游标记录  其中记录当前状态  这里包含类一定的算法在里面
    //** 记事本中 有个游标  有个记录方法  有个回滚方法

    // 这个方法在实际的编码中会经常用到 比如持久化和回滚 但是在我们在封装代码的时候没有很好的抽象接口  让它使用起来像下面的代码一样的简单。






}
