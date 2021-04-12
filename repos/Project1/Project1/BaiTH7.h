#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
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
int add(Stack& z, char e)
{
	if (empty(z)) return 0;
	else
	{
		z.a[z.top] = e;
		z.top++;
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
		char cc{};
		if (n % q < 10)
			for (int i = 0; i < 10; i++)
			{
				if (n % q == i) cc = char(i + 48);
			}
		else
		{
			for (int i = 10; i < 20; i++)
				if (n % q == i) cc = char(i + 55);
		}
		add(z, cc);
		n /= q;
	}
}
void xx(Stack z)
{
	cout << "\n";
	for (int i = z.top - 1; i >= 0; i--)
	{
		cout << z.a[i];
	}
}
//int main()
//{
//
//	return 0;
//}

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
int add1(Stack1& z, char e)
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
		if (z.top != 0)
		{
			get1(z, e);
			add1(x, e);
		}
		//strcpy(xz);
		if ((z.a[z.top] == '(') && (x.a[x.top] == ')'))
		{
			get1(z, e);
			get1(x, e);
		}
		else if ((z.a[z.top] == '[') && (x.a[x.top] == ']'))
		{
			get1(x, e);
			get1(z, e);
		}
		else if ((z.a[z.top] == '{') && (x.a[x.top] == '}'))
		{
			get1(x, e);
			get1(z, e);
		}
	} while (!empty1(z));
	if (empty1(x)) return 1;
	else return 0;
}


/*-------------------------*/
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