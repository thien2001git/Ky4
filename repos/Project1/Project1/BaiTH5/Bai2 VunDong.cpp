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
void heapNode(int node, int* a, int n)
{
	int ln = 2 * node + 1;
	if (ln<n && a[ln]<a[node])
	{
		swap(a[ln], a[node]);
		heapNode(ln, a, n);
	}
	int rn = 2 * node + 2;
	if (rn<n && a[rn]<a[node])
	{
		swap(a[ln], a[node]);
		heapNode(rn, a, n);
	}
}
void heapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapNode(i, a, n);
	}
	for (int i = n; i >= 2; i--)
	{
		swap(a[0], a[i - 1]);
		heapNode(0, a, i - 1);
	}
}
int main()
{
	int* a, n;
	n = nm0();
	a = new int[n];
	nm(a, n);
	heapSort(a, n);
	xm(a, n);
	return 0;
}