#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
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
void xm(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << a[i];
	}
}
void buble(int* a, int n)
{
	int i = 0;
	while (i < n - 1)
	{
		int j = n - 1;
		while (j > i)
		{
			if (a[j] > a[j - 1])
				swap(a[j], a[j - 1]);
			j--;
		}
		i++;
	}
}
void nm(int* a, int& n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}
int main()
{
	int* a, n;
	n = nm0();
	a = new int[n];
	nm(a, n);
	buble(a, n);
	xm(a, n);
	return 0;
}