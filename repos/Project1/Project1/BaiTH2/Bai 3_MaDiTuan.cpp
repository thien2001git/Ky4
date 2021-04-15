#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
int a[100][100];

void xu(int a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\t" << a[i][j];
		}
		cout << "\n";
	}
}
int dem = 0;
void dc(int x, int y, int n)
{
	int C[] = { 1,	2,	2,	1,	-1,	-2,	-2,	-1 };
	int D[] = { 2,	1, -1, -2, -2, -1,	1,	2 };
	dem++;
	a[x][y] = dem;
	//cout << "\n" << dem;
	for (int i = 0; i < n; i++)
	{
		if (dem == n * n)
		{
			cout << "\nNuoc di:\n";
			xu(a, n);
			exit(0);
		}
		else
		{
			int u = x + C[i];
			int v = y + D[i];
			if (u >= 0 && u < n && v >= 0 && v < n && a[u][v] == 0)
			{
				dc(u, v, n);
			}
		}
	}
	dem--;
	a[x][y] = 0;
}
int nm0()
{
	int n;
	do
	{
		cout << "Nhap gia tri: ";
		cin >> n;
	} while (n < 0);
	return n;
}
int main()
{
	cout << "Nhap vi tri x: ";
	int x = nm0();
	cout << "Nhap vi tri y: ";
	int y = nm0();
	cout << "Nhap do lon ban co: ";
	int n = nm0();
	dc(x, y, n);
	cout << "\nKhong tim thay duong di";
	return 0;
}