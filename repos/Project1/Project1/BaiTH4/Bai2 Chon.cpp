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

void nm(int* a, int& n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}
void selection(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++)
			if (a[m] < a[j])
				m = j;
		swap(a[i], a[m]);
	}
}
int main()
{
	int* a, n;
	n = nm0();
	a = new int[n];
	nm(a, n);
	selection(a, n);
	xm(a, n);
	return 0;
}