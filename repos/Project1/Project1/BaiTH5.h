#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
void qs(int l, int r, int* a)
{
	if (l < r)
	{
		int pivot = (l + r) / 2;
		while (true)
		{

			int i = l;
			int j = r;
			while (i < j && a[i] < a[pivot])
			{
				i++;
			}
			while (i < j && a[j] > a[pivot])
			{
				j--;
			}
			if (i >= j) break;
			swap(a[i], a[j]);
			i++; j--;
		}
		qs(l, pivot - 1, a);
		qs(pivot + 1, r, a);
	}
}


void heapNode(int node, int* a, int n)
{
	int ln = 2 * node + 1;
	if (ln<n && a[ln]>a[node])
	{
		swap(a[ln], a[node]);
		heapNode(ln, a, n);
	}
	int rn = 2 * node + 2;
	if (rn<n && a[rn]>a[node])
	{
		swap(a[ln], a[node]);
		heapNode(rn, a, n);
	}
}
void heapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapNode(i, a, n);
	}
	for (int i = n; i >= 2; i--)
	{
		swap(a[0], a[i - 1]);
		heapNode(0, a, i - 1);
	}
}

void merge(int l1, int w1, int l2, int w2, int* a, int* z)
{
	int i = l1;
	int j = l2;
	int r1 = l1 + w1 - 1;
	int r2 = l2 + w2 - 1;
	int k = l1;
	while (i <= r1 && j <= r2)
	{
		if (a[i] < a[j])
		{
			z[k] = a[i];
			i++;
			k++;
		}
		else
		{
			z[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= r1)
	{
		z[k] = a[i];
		i++;
		k++;
	}
	while (j <= r2)
	{
		z[k] = a[j];
		j++;
		k++;
	}
}

void mergePass(int k, int n, int* a, int* z)
{
	int cv = n / (2 * k);
	int sl = 2 * k * cv;
	int r = n - sl;
	for (int i = 1; i <= cv; i++)
	{
		int l1 = (2 * i - 2) * k;
		merge(l1, k, l1 + k, k, a, z);
	}
	if (r > k)
		merge(0, sl + k, k, r - k, a, z);
	else
	{
		for (int i = sl; i < n; i++) z[i] = a[i];
	}
}

void mergeSort(int* a, int n)
{
	int k = 1;
	int* z = new int[n];
	while (k < n)
	{
		mergePass(k, n, a, z);
		mergePass(2 * k, n, z, a);
		k *= 4;
	}
}

struct sv
{
	char hoten[30];
	int gt, ns;
	float diem;
};

istream& operator>>(istream& x, sv& y)
{
	cout << "Nhap ho ten: ";
	fflush(stdin);
	cin.ignore();
	x.getline(y.hoten, 30);
	cout << "Nhap gt: ";
	x >> y.gt;
	cout << "Nhap ns: ";
	x >> y.ns;
	cout << "Nhap diem: ";
	x >> y.diem;
	return x;
}

ostream& operator<<(ostream& x, sv y)
{
	x << "\n" << setw(30) << y.hoten;
	if (y.gt == 0) x << setw(10) << "Nu";
	else x << setw(10) << "Nam";
	cout << setw(10) << y.ns << setw(10) << y.diem;
	return x;
}
#pragma warning(disable: 4996)
void qs1(int l, int r, sv* a)
{
	if (l < r)
	{
		int pivot = (l + r) / 2;
		while (true)
		{

			int i = l;
			int j = r;
			char* z1, * z2, * z3;
			z1 = new char[sizeof(a[i].hoten)];
			z2 = new char[sizeof(a[j].hoten)];
			z3 = new char[sizeof(a[pivot].hoten)];
			strcpy(z1, a[i].hoten);
			strcpy(z2, a[j].hoten);
			strcpy(z3, a[pivot].hoten);
			while (i < j && strcmp(z1, z3) == -1)
			{
				i++;
			}
			while (i < j && strcmp(z2, z3) == 1)
			{
				j--;
			}
			if (i >= j) break;
			swap(a[i], a[j]);
			i++; j--;
		}
		qs1(l, pivot - 1, a);
		qs1(pivot + 1, r, a);
	}
}