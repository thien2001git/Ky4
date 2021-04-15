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
	} while (so < 0);
}

Stnd::~Stnd()
{
	so = NULL;
}
long luyThua(int a, int n)
{
	if (n == 0) return 1;
	else if (n == 1) return a;
	else if (n % 2 == 1) return luyThua(a, n / 2) * luyThua(a, n / 2) * a;
	else return luyThua(a, n / 2) * luyThua(a, n / 2);
}
int main()
{
	Stnd a(1), n(2);
	cout << "\nLuy thua " << a.so << "^" << n.so << " = " << luyThua(a.so, n.so);
	return 0;
}