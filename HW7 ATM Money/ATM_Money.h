#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Money
{
protected:
    int nominal;
    Money* next;

public:
    Money(int _nominal) : nominal(_nominal), next(nullptr) {}

    void Set_next(Money* next_money) { next = next_money; }
    void Withdraw(int amount);
    virtual ~Money();
};

class ATM_Money
{
private:
    Money* chain_start;

public:
    ATM_Money();
    ~ATM_Money() { delete chain_start;}
    void withdraw(int amount) { chain_start->Withdraw(amount); }
};

void menu();

