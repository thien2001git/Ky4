#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
#pragma warning(disable 4996)
using namespace std;
int nm0()
{
	int n;
	do
	{
		cout << "Gia tri: ";
		cin >> n;
	} while (n < 0);
	return n;
}
int gt(int a, int n)
{
	if (n == 1) return a;
	else if (n % 2 == 1) return gt(a, n / 2) * gt(a, n / 2) * a;
	else return gt(a, n / 2) * gt(a, n / 2);
}
int main()
{

	
	int n, a;
	cout << "Nhap so can luy thua. ";
	a = nm0();
	cout << "Nhap so mu. ";
	n = nm0();
	cout << "\n" << a << "^" << n << " = " << gt(a, n);
	break;
	
	return 0;
}