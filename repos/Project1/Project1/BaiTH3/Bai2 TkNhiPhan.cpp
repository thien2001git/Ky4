#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
void Xep0(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[m])
				m = j;
		swap(a[m], a[i]);
	}
}
int timNhi(int* a, int l, int r, int key)
{
	if (l < r)
	{
		float m = (l + r) / 2;
		if (a[(int)m] == key)
			return (int)m + 1;
		else
		{
			if (a[(int)m] < key)
				return timNhi(a, l, (int)m - 1, key);
			else
				return timNhi(a, (int)m + 1, r, key);
		}
	}
}
void nm(int* a, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "Pt thu " << i + 1 << ": ";
		cin >> a[i];
	}
}
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
void nm0(int& n)
{
	//int n;
	do
	{
		cout << "Gia tri: ";
		cin >> n;
	} while (n < 0);
	//return n;
}
int main()
{
	cout << "Nhap so pt: ";
	int n = nm0();
	cout << "Nhap phan tu\n";
	int* a = new int[n];
	nm(a, n);
	cout << "\nNhap so can tim. ";
	int k;
	nm0(k);
	int kq = timNhi(a, 0, n + 1, k);
	if (kq > 0)
		cout << "\nSo can tim o vi tri: " << kq;
	else
		cout << "\nKhong tim thay";
	return 0;
}