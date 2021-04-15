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
struct Stack1
{
	int top;
	char a[Max];
};
void init1(Stack1& z)
{
	z.top = -1;
}
int empty1(Stack1 z)
{
	return z.top == -1;
}
int full1(Stack1 z)
{
	return z.top == Max - 1;
}
int add1(Stack1& z, int e)
{
	if (full1(z)) return 0;
	else
	{
		z.top++;
		z.a[z.top] = e;
		return 1;
	}
}
int get1(Stack1& z, char& e)
{
	if (empty1(z)) return 0;
	else
	{
		e = z.a[z.top];
		z.a[z.top] = '0';
		z.top--;
		return 1;
	}
}
int cd1(Stack1 z)
{
	int kq = 2;
	Stack1 x{};
	init1(x);
	do
	{

		char e;
		//cout << "\n" << z.a << "\t" << x.a;
		if ((z.a[z.top] == 41) || (z.a[z.top] == 93) || (z.a[z.top] == 125))
		{
			get1(z, e);
			add1(x, e);
		}
		//strcpy(xz);
		if ((z.a[z.top] == 40) && (x.a[x.top] == 41))
		{
			get1(z, e);
			get1(x, e);
		}
		else if ((z.a[z.top] == 91) && (x.a[x.top] == 93))
		{
			get1(x, e);
			get1(z, e);
		}
		else if ((z.a[z.top] == 123) && (x.a[x.top] == 125))
		{
			get1(x, e);
			get1(z, e);
		}
	} while (!empty1(z));
	if (empty1(x)) return 1;
	else return 0;
}
int main()
{
	/*for (int i = 0; i < 256; i++)
		cout << "\n" << i << "\t" << char(i);*/
	Stack1 s{};
	init1(s);
	/*cout << "Nhap day ngoac: ";
	fflush(stdin);
	cin.ignore();*/
	string a;
	cout << "Nhap day ngoac: ";
	cin >> a;
	for (int i = 0; i < a.length(); i++)
		s.a[i] = a[i];
	s.top = a.length() - 1;
	int kq = cd1(s);
	if (kq == 1) cout << "\nDay dung";
	else cout << "\nDay sai";
	return 0;
}