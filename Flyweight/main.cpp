#include <iostream>
#include <string>
#include <unordered_map>

// Anything that will be cached is flyweight.
// Types of tea here will be flyweights.
class KarakTea {};

// ��Ԫģʽ�����ص����



class TeaMaker {
public:
    KarakTea* Make(const std::string& preference) {

        // ��ѯ�ü�¼�Ƿ����  ����������� ���ҷ��ظö���
        if (availableTea_.find(preference) == availableTea_.end())
            // ��������������ﹹ��
            availableTea_.insert({preference, new KarakTea()});

        return availableTea_.at(preference);
    }

private:

    // ��¼��Ԫģʽ����
    // ��¼�ܹ������̲������?

    // ��¼�˸�֮������
    std::unordered_map<std::string, KarakTea*> availableTea_;
};




// û�м̳�ֻ�й���
class TeaShop {
public:
    TeaShop(TeaMaker& teaMaker): teaMaker_(teaMaker) {}

    // ���  �㵥
    void TakeOrder(const std::string& teaType, int table) {
        orders_[table] = teaMaker_.Make(teaType);
    }

    // ����
    void Serve() {
        for(auto order : orders_)
            std::cout << "Serving tea to table# " << order.first << std::endl;
    }

private:

    // int ��ʾ��λ����    karak��ʾ�������
    std::unordered_map<int, KarakTea*> orders_;
    TeaMaker& teaMaker_;
};

int main()
{

    // �̲�ʦ
    TeaMaker teaMaker;

    //  �̲��
    TeaShop shop(teaMaker);


    // �̲�괴���̲�
    // �̲�������̲�ʦ�ļ��ܺ͹���  
    // ͨ���̲����������̲�
    shop.TakeOrder("less sugar", 1);
	shop.TakeOrder("more milk", 2);
	shop.TakeOrder("less milk",3);
    shop.TakeOrder("without sugar", 5);

    shop.Serve();
   
    getchar();
}
