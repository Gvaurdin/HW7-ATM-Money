#include "ATM_Money.h"

void menu()
{
	try
	{
		ATM_Money atm;
		int withdrawal_money;
		cout << "Enter the amount to withdraw: ";
		cin >> withdrawal_money;
		while (withdrawal_money <= 0 ||
			withdrawal_money % 5 != 0 ||
			!withdrawal_money)
		{
			throw invalid_argument("Error input withdrawal money...");
		}
		atm.withdraw(withdrawal_money);
		system("pause");
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}

void Money::Withdraw(int amount)
{
	int count_bills = amount / nominal;
	if (count_bills > 0) {
		cout << "Dispensing " << count_bills << " bills of " << nominal << " $ " << endl;
	}
	int remaining_money = amount % nominal;
	if (remaining_money > 0 && next != nullptr) {
		next->Withdraw(remaining_money);
	}
}

Money::~Money()
{
	if (next) delete next;
}

ATM_Money::ATM_Money()
{
	chain_start = new Money(100);
	Money* fifty = new Money(50);
	Money* twenty = new Money(20);
	Money* ten = new Money(10);
	Money* five = new Money(5);

	chain_start->Set_next(fifty);
	fifty->Set_next(twenty);
	twenty->Set_next(ten);
	ten->Set_next(five);
}
