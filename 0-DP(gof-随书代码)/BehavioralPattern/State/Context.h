#ifndef _CONTEXT_H_
#define _CONTEXT_H_

class State;

class Context
{
public:
    Context();
    Context(State* state);
    ~Context();
    void OprationInterface();
    void OperationChangState();

protected:
private:
    /**
     * To make Context to access ChangeState() which is protected, state is declared friend class
     */
    friend class State;
    bool ChangeState(State* state);

private:
    State* _state;
};

#endif //~_CONTEXT_H_
