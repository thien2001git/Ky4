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
void qs(int l, int r, int* a)
{
	if (l < r)
	{
		int pivot = (l + r) / 2;
		while (true)
		{

			int i = l;
			int j = r;
			while (i < j && a[i] > a[pivot])
			{
				i++;
			}
			while (i < j && a[j] < a[pivot])
			{
				j--;
			}
			if (i >= j) break;
			swap(a[i], a[j]);
			i++; j--;
		}
		qs(l, pivot - 1, a);
		qs(pivot + 1, r, a);
	}
}
int main()
{
	int* a, n;
	n = nm0();
	a = new int[n];
	nm(a, n);
	qs(0, n - 1, a);
	xm(a, n);
	return 0;
}