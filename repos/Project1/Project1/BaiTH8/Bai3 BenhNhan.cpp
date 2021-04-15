#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
#define Max 100
struct bn
{
	int uuTien;
	char mabn[10];
};

struct Quere2
{
	int front;
	int rear;
	bn a[Max];
};

void init2(Quere2& x)
{
	x.front = 0;
	x.rear = -1;
}

int empty2(Quere2 x)
{
	return x.rear == -1;
}

int full2(Quere2 x)
{
	return x.rear == Max - 1;
}

int push(Quere2& x, bn e)
{
	if (full2(x)) return 0;
	else
	{
		if (e.uuTien == 3)
		{
			x.rear++;
			x.a[x.rear] = e;
		}
		if (e.uuTien == 1)
		{
			if (x.a[x.rear].uuTien == NULL)
			{
				x.rear++;
				x.a[x.rear] = e;
			}
			else
			{
				x.rear++;
				int j = x.rear;
				while (j > x.front && (x.a[j - 1].uuTien != 1))
				{
					x.a[j] = x.a[j - 1];
					j--;
				}
				x.a[j] = e;
			}

		}
		if (e.uuTien == 2)
		{
			if (x.a[x.rear].uuTien == NULL)
			{
				x.rear++;
				x.a[x.rear] = e;
			}
			else
			{
				x.rear++;
				int j = x.rear;
				while (j > x.front && (x.a[j - 1].uuTien > 2))
				{
					x.a[j] = x.a[j - 1];
					j--;
				}
				x.a[j] = e;
			}
		}
		return 1;
	}
}

int pop(Quere2& x, bn& e)
{
	if (empty2(x)) return 0;
	else
	{
		e = x.a[x.front];
		x.front++;
		return 1;
	}
}

void nhapKT(Quere2& x)
{
	char tt;
	do
	{
		if (full2(x)) break;
		bn c;
		cout << "\nNhap do uu tien: ";
		cin >> c.uuTien;
		cout << "\nNhap ma bn: ";
		fflush(stdin);
		cin.ignore();
		cin.getline(c.mabn, 10);
		push(x, c);
		cout << "Tiep tuc(c/k)? ";
		cin >> tt;
	} while (tt == 'c');
}
ostream& operator<<(ostream& xx, Quere2 x)
{
	xx << "\n" << setw(10) << "mabn" << setw(10) << "uuTien";
	for (int i = x.front; i <= x.rear; i++)
		xx << "\n" << setw(10) << x.a[i].mabn << setw(10) << x.a[i].uuTien;
	return xx;
}
int main()
{

	
	Quere2 x;
	init2(x);
	nhapKT(x);
	cout << x;
	
	return 0;
}