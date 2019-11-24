#pragma once
enum Banks { PKO, BGZ, BRE, BPH };

struct Account {
	Banks bank;
	int balance;
};

struct Person {
	char name[20];
	Account account;
};

struct Couple {
	Person a;
	Person b;
};

const Couple* bestClient(const Couple* data, int size, Banks bank);