#include "Mediator.h"
#include "Colleague.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    ConcreteMediator* m = new ConcreteMediator();
    ConcreteColleagueA* cA = new ConcreteColleagueA(m);
    ConcreteColleagueB* cB = new ConcreteColleagueB(m);

    m->IntroColleague(cA,cB);

    cA->SetState("old");
    cB->SetState("old");
    cA->Aciton();
    cB->Aciton();
    cout<<endl;

    cA->SetState("new");
    cA->Aciton();
    cB->Aciton();
    cout<<endl;

    cB->SetState("old");
    cB->Aciton();
    cA->Aciton();

    delete m;
    delete cA;
    delete cB;

    return 0;
}
