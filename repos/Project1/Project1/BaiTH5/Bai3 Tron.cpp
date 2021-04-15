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
void merge(int l1, int w1, int l2, int w2, int* a, int* z)
{
	int i = l1;
	int j = l2;
	int r1 = l1 + w1 - 1;
	int r2 = l2 + w2 - 1;
	int k = l1;
	while (i <= r1 && j <= r2)
	{
		if (a[i] > a[j])
		{
			z[k] = a[i];
			i++;
			k++;
		}
		else
		{
			z[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= r1)
	{
		z[k] = a[i];
		i++;
		k++;
	}
	while (j <= r2)
	{
		z[k] = a[j];
		j++;
		k++;
	}
}

void mergePass(int k, int n, int* a, int* z)
{
	int cv = n / (2 * k);
	int sl = 2 * k * cv;
	int r = n - sl;
	for (int i = 1; i <= cv; i++)
	{
		int l1 = (2 * i - 2) * k;
		merge(l1, k, l1 + k, k, a, z);
	}
	if (r > k)
		merge(0, sl + k, k, r - k, a, z);
	else
	{
		for (int i = sl; i < n; i++) z[i] = a[i];
	}
}

void mergeSort(int* a, int n)
{
	int k = 1;
	int* z = new int[n];
	while (k < n)
	{
		mergePass(k, n, a, z);
		mergePass(2 * k, n, z, a);
		k *= 4;
	}
}
int main()
{
	int* a, n;
	n = nm0();
	a = new int[n];
	nm(a, n);
	mergeSort(a, n);
	xm(a, n);
	return 0;
}