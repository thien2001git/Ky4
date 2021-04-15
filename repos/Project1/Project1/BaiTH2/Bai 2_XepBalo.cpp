#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
int nm0()
{
	int n;
	do
	{
		cout << "Gia tri: ";
		cin >> n;
	} while (n < 0);
	return n + 1;
}
struct balo
{
	int count;
	int* kl = new int[10];
	int* gt = new int[10];
};
void nm(int* a, int& n)
{

	for (int i = 1; i < n; i++)
	{
		cout << "Pt thu " << i << ": ";
		cin >> a[i];
	}
}
void xx(balo a)
{
	cout << "\nBalo co: ";
	cout << "\nKL\tGT";
	for (int i = 0; i <= a.count; i++)
	{
		cout << "\n" << a.kl[i] << "\t" << a.gt[i];
	}
}
void xep(int* gt, int* kl, int n, int klbl, balo& a)
{
	int** b;
	b = new int* [n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[klbl];
	}
	//int b[10][10];
	balo** b0;
	b0 = new balo * [n];
	for (int i = 0; i < n; i++)
	{
		b0[i] = new balo[klbl];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++)
			if (kl[m] > kl[j])
				m = j;
		swap(kl[i], kl[m]);
		swap(gt[i], gt[m]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < klbl; j++)
		{
			if (i == 0 || j == 0)
			{
				b[i][j] = 0;
				b0[i][j].count = -1;
			}
			else if (j < kl[i])
			{
				b[i][j] = b[i - 1][j];
				b0[i][j] = b0[i - 1][j];
			}
			else
			{
				if (b[i - 1][j] >= (gt[i] + b[i - 1][j - kl[i]]))
				{
					b[i][j] = b[i - 1][j];
					b0[i][j] = b0[i - 1][j];
				}
				else
				{
					b[i][j] = gt[i] + b[i - 1][j - kl[i]];
					b0[i][j] = b0[i - 1][j - kl[i]];
					b0[i][j].count++;
					b0[i][j].gt[b0[i][j].count] = gt[i];
					b0[i][j].kl[b0[i][j].count] = kl[i];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < klbl; j++)
		{
			cout << "\t" << b[i][j];
		}
	}
	a = b0[n - 1][klbl - 1];
}
int main()
{
	cout << "Nhap so vat. ";
	int n = nm0();
	int* gt = new int[n];
	int* kl = new int[n];
	cout << "Nhap khoi luong:\n";
	nm(kl, n);
	cout << "Nhap gia tri vat.\n";
	nm(gt, n);
	cout << "Nhap khoi luong ba lo: ";
	int klbl = nm0();
	balo a;
	xep(gt, kl, n, klbl, a);
	xx(a);
	return 0;
}