#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
#define ma 10
#define ten 30
using namespace std;
#pragma warning(disable: 4996)
#define Max 100
struct Stack2
{
	int top;
	int a[Max];
};
void init1(Stack2& z)
{
	z.top = -1;
}
int empty1(Stack2 z)
{
	return z.top == -1;
}
int full1(Stack2 z)
{
	return z.top == Max - 1;
}
int add1(Stack2& z, int e)
{
	if (full1(z)) return 0;
	else
	{
		z.top++;
		z.a[z.top] = e;
		return 1;
	}
}
int get1(Stack2& z, int& e)
{
	if (empty1(z)) return 0;
	else
	{
		e = z.a[z.top];
		z.a[z.top] = 0;
		z.top--;
		return 1;
	}
}

void loai2(Stack2& z, int k)
{
	int dem = 0;
	Stack2 x;
	init1(x);
	int e;
	while (dem < k)
	{
		get1(z, e);
		add1(x, e);
		dem++;
	}
	get1(x, e);
	while (!empty1(x))
	{
		get1(x, e);
		add1(z, e);
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
int main()
{
	cout << "Nhap so pt. ";
	int n = nm0();
	Stack2 s;
	s.top = n - 1;
	nm(s.a, n);
	xm(s.a, s.top + 1);
	cout << "\nXOA PT SO 2";
	loai2(s, 2);
	cout << "\n";
	xm(s.a, s.top + 1);
	return 0;
}