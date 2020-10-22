#ifndef _CONTEXT_H_
#define _CONTEXT_H_

class Strategy;

/**
 * The Context class is the key point of Strategy pattern,
 * and it is the essential difference between templete and strategy pattern.
 * To realize the algorithm:
 *   Strategy uses a composing method
 *   Template uses an inheritance method
 */
class Context
{
public:
    Context(Strategy* stg);
    ~Context();
    void DoAction();

protected:
private:
    Strategy* _stg;

};

#endif //~_CONTEXT_H_
