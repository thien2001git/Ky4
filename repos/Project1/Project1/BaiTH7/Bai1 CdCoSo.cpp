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
struct Stack
{
	int top;
	char a[Max];
};
void init(Stack& z)
{
	z.top = -1;
}
int empty(Stack z)
{
	return z.top == -1;
}
int full(Stack z)
{
	return z.top == Max - 1;
}
int add(Stack& z, int e)
{
	if (full(z)) return 0;
	else
	{
		z.top++;
		z.a[z.top] = e;
		return 1;
	}
}
int get(Stack& z, char e)
{
	if (empty(z)) return 0;
	else
	{
		e = z.a[z.top - 1];
		z.a[z.top - 1] = 0;
		z.top--;
		return 1;
	}
}
void cd(Stack& z, int n, int q)
{
	while (n >= 1)
	{
		//cout << n % q;
		//char cc{};
		if (n % q < 10)
			for (int i = 0; i < 10; i++)
			{
				if (n % q == i) add(z, i + 48);
			}
		else
		{
			for (int i = 10; i < 20; i++)
				if (n % q == i) add(z, i + 55);
		}
		
		n /= q;
	}
}
void xx(Stack z)
{
	cout << "\n";
	for (int i = z.top; i >= 0; i--)
	{
		cout << z.a[i];
	}
}
int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	int q;
	cout << "Nhap he so: ";
	cin >> q;
	Stack s;
	init(s);
	/*for (int i = 0; i < 256; i++)
		cout << "\n" << i << "\t" << char(i);*/
	cd(s, n, q);
	xx(s);
	return 0;
}