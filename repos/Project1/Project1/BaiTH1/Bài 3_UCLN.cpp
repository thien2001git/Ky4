#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
class Stnd //số tự nhiên dương
{
public:
	Stnd();
	Stnd(int i);
	~Stnd();
	friend int main();
private:
	int so;
};
Stnd::Stnd()
{
}
Stnd::Stnd(int i)
{
	do
	{
		cout << "Nhap so thu " << i << ": ";
		cin >> so;
	} while (so < 1);
}

Stnd::~Stnd()
{
	so = NULL;
}
unsigned int ucln(int a, int b)
{
	if (a == b) return a;
	else
	{
		if (a > b)
			return ucln(a - b, b);
		else
			return ucln(a, b - a);
	}
}

int main()
{
	Stnd a(1), b(2);
	cout << "\nUCLN: " << ucln(a.so, b.so);
	return 0;
}