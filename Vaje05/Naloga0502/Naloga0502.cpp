#include <Bank.hpp>
#include <Account.hpp>
#include <SavingAccount.hpp>
#include <Person.hpp>
#include <iostream>

int main()
{
    Person ownerOne("John", "Doe", 70, 78.2f, 182);

    Person ownerTwo("Jason", "Jack", 64, 65.4f, 192);

    Bank bank;

    bank.addAccount(new Account(1, 1000.0f, &ownerOne));
    bank.addAccount(new Account (2, 154.0f, &ownerTwo));
    bank.addAccount(new SavingAccount(3, 278.0f, &ownerOne, 1.2f));

    if(bank.makeDepostOnAccount(100.0f, 1))
        std::cout << "Succesfuly deposited 100.0f" << std::endl;

    if(!bank.makeWithdrawalOnAccount(100.0f, 4))
        std::cout << "Failed to withdraw money from nonexistant account" << std::endl;

    if(!bank.makeDepostOnAccount(-100.0f, 2))
        std::cout << "Failed to deposit -100.0f" << std::endl;

    if(bank.makeDepostOnAccount(100.0f, 3))
        std::cout << "Deposited 100.0f to savings account" << std::endl;

    if(!bank.makeDepostOnAccount(-100.0f, 3))
        std::cout << "Failed to deposit -100.0f to savings account" << std::endl;

    if(!bank.makeWithdrawalOnAccount(200.0f, 2))
        std::cout << "Failed to withdraw 200.0f" << std::endl;

    if(!bank.makeWithdrawalOnAccount(-200.0f, 2))
        std::cout << "Failed to withdraw 200.0f" << std::endl;

    if(!bank.makeWithdrawalOnAccount(100.0f, 2))
        std::cout << "Failed to withdraw 200.0f" << std::endl;

    if(bank.makeWithdrawalOnAccount(100.0f, 3))
        std::cout << "Withdrew 100.0f from savings account" << std::endl;

    if(!bank.makeWithdrawalOnAccount(100.0f, 3))
        std::cout << "Failed to withdraw 100.0f from savings account" << std::endl;

    // tukaj bi blo treba preverjat ce je returnalo true al false in bo devalo warning da sem vrednost discardo
    bank.makeDepostOnAccount(243.0f, 2);
    bank.makeDepostOnAccount(132.0f, 2);
    bank.makeWithdrawalOnAccount(12.0f, 2);
    bank.makeDepostOnAccount(43.0f, 2);
    bank.makeWithdrawalOnAccount(43.0f, 2);

    std::cout << bank.toString() << std::endl;

    bank.printTransactionsOnAccount(2);
}