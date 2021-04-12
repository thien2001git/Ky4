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
	x.rear++;
	int j = x.rear;
	while (j >= (x.front + k))
	{
		x.a[j] = x.a[j - 1];
		j--;
	}
	x.a[j] = tar;
}


/*-----------------
---------------
----------------*/
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
/*----------------------------------------------
-------------------------------------------
-----------------------------------------*/

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

	int qq;
	cout << "Nhap bai: ";
	cin >> qq;
	switch (qq)
	{
	case 1:
	{
		Quere x;
		init2(x);
		nhapKT(x);
		cout << x;
		loai(x, 2);
		cout << x;
		them(x, 4, 99);
		cout << x;
		break;
	}
	case 2:
	{
		Quere1 x;
		init2(x);
		nhapKT(x);
		cout << x;
		duy(x, 4);
		cout << x;
		break;
	}
	case 3:
	{
		Quere2 x;
		init2(x);
		nhapKT(x);
		cout << x;
		break;
	}
	default: return main();
		break;
	}
	return 0;
}