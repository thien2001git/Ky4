#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
struct Node
{
	int info;
	Node* le;
	Node* ri;
};
typedef Node* tro;

void init(tro& l, int i)
{
	l = new Node;
	l->info = i;
	l->le = NULL;
	l->ri = NULL;
}

int empty(tro l)
{
	return l == NULL;
}

int insert(tro& l, int x)
{
	if (l == NULL)
	{
		init(l, x);
		return 1;
	}
	else
	{
		tro nn = new Node;
		tro q = l;
		while (q != NULL)
		{
			nn = q;
			if (x < q->info) q = q->le;
			else q = q->ri;
		}
		tro nn1 = new Node;
		init(nn1, x);
		if (x < nn->info) nn->le = nn1;
		else nn->ri = nn1;
	}
}
void xm(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << a[i];
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
void nm(int* a, int& n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}
void preOr(tro l)
{
	if (l != NULL)
	{
		cout << "\t" << l->info;
		preOr(l->le);
		preOr(l->ri);
	}
}
int main()
{
	cout << "Nhap so nut cua cay. ";
	int n = nm0();
	int* a = new int[n];
	nm(a, n);
	tro l;
	init(l, a[0]);
	for (int i = 1; i < n; i++)
	{
		insert(l, a[i]);
	}
	cout << "\nPREORDER\n";
	preOr(l);
	return 0;
}