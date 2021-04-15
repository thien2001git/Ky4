#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
unsigned int fibonaci(int n)
{
	if (n <= 1) return 1;
	else
	{
		return fibonaci(n - 1) + fibonaci(n - 2);
	}
}
int nm0()
{
	int n;
	do
	{
		cout << "Nhap so n(> 0): ";
		cin >> n;
	} while (n<0);
	return n;
}
int main()
{
	int n = nm0();
	cout << "\nHam fibonaci: f(" << n << ") = " << fibonaci(n);
	return 0;
}