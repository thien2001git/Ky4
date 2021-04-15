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
void insertion(int* a, int n)
{
	//cout << "*";
	for (int i = 1; i < n; i++)
	{
		int tam = a[i];
		int j = i;
		//cout << ".";
		while (j > 0 && a[j - 1] < tam)
		{
			//cout << "`";
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tam;
	}
}
int main()
{
	int* a, n;
	n = nm0();
	a = new int[n];
	nm(a, n);
	insertion(a, n);
	xm(a, n);
	return 0;
}