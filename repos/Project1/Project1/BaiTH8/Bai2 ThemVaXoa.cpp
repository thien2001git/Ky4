#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
#define Max 100
struct Quere1
{
	int front;
	int rear;
	int a[Max];
};

void init2(Quere1& x)
{
	x.front = 0;
	x.rear = -1;
}

int empty2(Quere1 x)
{
	return x.rear == -1;
}

int full2(Quere1 x)
{
	return x.rear == Max - 1;
}

int push(Quere1& x, int e)
{
	if (full2(x)) return 0;
	else
	{
		x.rear++;
		x.a[x.rear] = e;
		return 1;
	}
}

int pop(Quere1& x, int& e)
{
	if (empty2(x)) return 0;
	else
	{
		e = x.a[x.front];
		x.a[x.front] = NULL;
		x.front++;
		return 1;
	}
}

void nhapKT(Quere1& x)
{
	char tt;
	do
	{
		if (full2(x)) break;
		int c;
		cout << "\nNhap so: ";
		cin >> c;
		push(x, c);
		cout << "Tiep tuc(c/k)? ";
		cin >> tt;
	} while (tt == 'c');
}
ostream& operator<<(ostream& xx, Quere1 x)
{
	xx << "\n";
	for (int i = x.front; i <= x.rear; i++)
		xx << "\t" << x.a[i];
	return xx;
}
void duy(Quere1& x, int k)
{
	for (int i = 0; i <= k; i++)
	{
		int xx;
		pop(x, xx);
		push(x, xx);
		push(x, xx);
	}
}
int main()
{

	
	Quere x;
	init2(x);
	nhapKT(x);
	cout << x;
	cout << "\nLOAI KI TU THU 3\n";
	loai(x, 2);
	cout << x;
	cout << "\nTHEM KI TU THU 4\n";
	them(x, 4, 99);
	cout << x;
	
	return 0;
}