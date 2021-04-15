#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
void thapHaNoi(char a, char b, char c, int n)
{
	if (n == 1) cout << "\n" << a << " -> " << c;
	else
	{
		thapHaNoi(a, c, b, n - 1);
		thapHaNoi(a, b, c, 1);
		thapHaNoi(b, a, c, n - 1);
	}
}
int nm0()
{
	int n;
	do
	{
		cout << "Nhap tang cua thap n(> 1): ";
		cin >> n;
	} while (n < 1);
	return n;
}
int main()
{
	int n = nm0();
	cout << "\nXep thap: ";
	thapHaNoi('a', 'b', 'c', n);
	return 0;
}