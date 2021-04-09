#pragma once
#include<iostream>
#include<string.h>
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
	for (int i = n - 1; i >= 1; i--)
	{
		swap(a[0], a[i]);
		heapNode(0, a, i - 1);
	}
}