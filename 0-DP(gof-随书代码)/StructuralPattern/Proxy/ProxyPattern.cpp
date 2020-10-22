#include <iostream>
#include <fstream>

#define NUM_ACCOUNTS 3 // 3 million!
#define PASSWORD 123

using namespace std;

class AccountsInterface
{
public:
    virtual int getBalance(int i) = 0;
};


class HugeListOfAccounts : public AccountsInterface
{
private:
    char accountFileName[50];
    //all accounts have format: account_nnnn.txt
    int accountBalances[NUM_ACCOUNTS+1];

    void updateBalances(){
        for (int i=1; i<=NUM_ACCOUNTS; i++){
            sprintf(accountFileName, "account_%d.txt", i);
            ifstream inFile(accountFileName);
            // input
            if(!inFile) {
                cout << "Cannot open input file: " << accountFileName << endl;
            } else {
                inFile >> accountBalances[i];
                inFile.close();
            }
        }
    }
    //updateBalances
public:
    HugeListOfAccounts(){
        cout << "ctor: hugeListOfAccounts, updating accountBalances \n";
        updateBalances();
    }

    int getBalance(int i){
        return accountBalances[i];
    }
};

class AccountsProxy : public AccountsInterface
{
    HugeListOfAccounts *hugeListInstance;
public:
    AccountsProxy(){
        hugeListInstance = NULL;
    }

    //dont build until first access}
    int getBalance(int i){
        int ipassword;
        cout << "password please: ";
        cin >> ipassword;
        if (ipassword == PASSWORD) {
            if (hugeListInstance==NULL) hugeListInstance = new HugeListOfAccounts;
            return hugeListInstance->getBalance(i);
        } else {
            cout << "Password incorrect \n";
            return -999;
        }
    }
};


int main()
{
    AccountsInterface *accounts = new AccountsProxy;
    int accountNum = 1;
    while (accountNum >0 && accountNum <= NUM_ACCOUNTS)
    {
        cout << "Testing Accounts Proxy \n" << endl;
        cout << "enter account number: ";
        cin >> accountNum;
        cout << accounts->getBalance(accountNum) << endl;
    }

    return 0;
}
