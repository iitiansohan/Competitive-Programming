#include <bits/stdc++.h>
using namespace std;
class BankAccount
{
    int balance;

public:
    BankAccount(int b)
    {
        balance = b;
    }
    void withdraw(int delbalance)
    {
        try
        {
            try
            {
                if (balance >= delbalance)
                {
                    balance -= delbalance;
                    cout << "Account debited with : " << delbalance << endl;
                    cout << "New account balance is : " << balance << endl;
                }
                else
                    throw 404;
            }
            catch (int e)
            {
                cout << "Inner Catch block\n";
                throw;
            }
        }
        catch (int e)
        {
            cout << "Insufficient balance" << endl;
        }
    }
};
int main()
{
    cout << "Enter the amount you wanna withdraw " << endl;
    int val;
    cin >> val;
    BankAccount newAcc(10000); // initial account balance is taken as 1000
    newAcc.withdraw(val);
}
