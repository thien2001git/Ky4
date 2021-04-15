#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
#define Max 100
struct Quere
{
	int front;
	int rear;
	char a[Max];
};

void init2(Quere& x)
{
	x.front = 0;
	x.rear = -1;
}

int empty2(Quere x)
{
	return x.rear == -1;
}

int full2(Quere x)
{
	return x.rear == Max - 1;
}

int push(Quere& x, char e)
{
	if (full2(x)) return 0;
	else
	{
		x.rear++;
		x.a[x.rear] = e;
		return 1;
	}
}

int pop(Quere& x, char& e)
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

void nhapKT(Quere& x)
{
	char tt;
	do
	{
		if (full2(x)) break;
		char c;
		cout << "\nNhap ki tu: ";
		cin >> c;
		push(x, c);
		cout << "Tiep tuc(c/k)? ";
		cin >> tt;
	} while (tt == 'c');
}
ostream& operator<<(ostream& xx, Quere x)
{
	xx << "\n";
	for (int i = x.front; i <= x.rear; i++)
		xx << x.a[i];
	return xx;
}
void loai(Quere& x, int k)
{
	for (int i = x.front; i <= x.rear; i++)
	{
		if (i - x.front == k - 1)
		{
			for (int j = i; j < x.rear; j++)
				x.a[j] = x.a[j + 1];
			break;
		}
	}
	x.rear--;
}

void them(Quere& x, int k, int tar)
{
	if (k >= (x.rear - x.front))
	{
		x.rear++;
		x.a[x.rear] = tar;
	}
	else
	{


		x.rear++;
		int j = x.rear;
		while (j > (x.front + k))
		{
			x.a[j] = x.a[j - 1];
			j--;
		}
		x.a[j] = tar;
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