#include <iostream>
#include "pdf5_zad2.h"

int main()
{
	Couple data[] = {
		{{"John", {PKO, 1200}}, {"Adam", {BGZ, 1400}}},
		{{"Peter", {BGZ, 1400}}, {"Suzy", {BRE, -1500}}},
		{{"Mary", {PKO, 1600}}, {"Katy", {BPH, 1500}}},
		{{"Kenny", {BPH, 200}}, {"Kevin", {BRE, -201}}},
	};

	const Couple* p = bestClient(data, 4, BRE);

	if (p)
		std::cout << p->a.name << " and " << p->b.name << ": " << p->a.account.balance + p->b.account.balance << std::endl;
	else
		std::cout << "No such couple!\n";
}

const Couple* bestClient(const Couple* data, int size, Banks bank) {
	const Couple* result = nullptr;
	for (int i = 0; i < size; i++) {
		if (data[i].a.account.bank == bank || data[i].b.account.bank == bank) {
			if (!result || data[i].a.account.balance + data[i].b.account.balance > result->a.account.balance + result->b.account.balance)
				result = &data[i];
		}
	}
	return result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
