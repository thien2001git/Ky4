#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
int Tim(int* a, int n, int key)
{
	int i = 0;
	a[n] = 404;
	while (a[i] != 404)
	{
		if (a[i] == key) break;
		i++;
	}
	if (i < n) return i;
	else return -1;
}
void nm(int* a, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "Pt thu " << i << ": ";
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
	int kq = Tim(a, n, k);
	if (kq > -1)
		cout << "\nSo can tim o vi tri: " << kq;
	else
		cout << "\nKhong tim thay";
	return 0;
}