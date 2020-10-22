#ifndef _RECEIVER_H_
#define _RECEIVER_H_

class Receiver
{
public:
    Receiver();
    ~Receiver();
    void ActionA(); // to be called in Command::Execute()
    void ActionB(); // to be called in Command::Execute()

protected:
private:
};

#endif //~_RECEIVER_H_
