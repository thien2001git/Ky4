﻿#pragma once
#include<iostream>
using namespace std;
#define ma 100
//Danh sách tuyến tính
struct DataType
{
	int a;
};
struct List
{
	DataType* e = new DataType[ma];
	int count;
};
int nhapn()
{
	int n;
	do
	{
		cout << "Nhap n(n>0): ";
		cin >> n;
	} while (n < 0);
	return n;
}

DataType input(int i)
{
	DataType x;
	cout << "Nhap phan tu " << i << ": ";
	cin >> x.a;
	return x;
}
void nhap(List& l)
{
	for (int i = 0; i < l.count; i++)
	{
		l.e[i] = input(i + 1);
	}
}

void create(List& z)
{
	for (int i = 0; i < z.count; i++)
	{
		z.e[i].a = rand() % 99 + 0;
	}
}

void output(DataType x)
{
	cout << "\t" << x.a;
}

void xuat(List l)
{
	cout << "\n";
	for (int i = 0; i < l.count; i++)
	{
		output(l.e[i]);
	}
}

void NoiBot(List& l)
{
	for (int i = l.count - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (l.e[i].a < l.e[j].a)
			{
				DataType q = l.e[i];
				l.e[i] = l.e[j];
				l.e[j] = q;
			}
		}
	}
}

//quick sort
int PhanManh(List& z, int low, int hight)
{
	DataType pivot = z.e[hight];
	int l = low;
	int r = hight - 1;
	while (true)
	{
		while (l <= r && z.e[l].a < pivot.a)
			l++;
		while (l <= r && z.e[r].a > pivot.a)
			r--;
		if (l >= r)
			break;
		DataType q = z.e[l];
		z.e[l] = z.e[r];
		z.e[r] = q;
		l++;
		r--;
	}
	DataType q = z.e[l];
	z.e[l] = z.e[hight];
	z.e[hight] = q;
	return l;
}



void qs(List& z, int low, int hight)
{
	//cout << ".";
	if (low < hight)
	{

		int pivot = PhanManh(z, low, hight);

		qs(z, low, pivot - 1);
		qs(z, pivot + 1, hight);
	}
}

//heapsort
void heapNode(List& z, int j, int n)
{
	int l = j * 2 + 1;
	int r = j * 2 + 2;
	if (z.e[l].a > z.e[r].a)
	{
		if (z.e[j].a < z.e[l].a)
		{
			swap(z.e[j], z.e[l]);
			heapNode(z, l, n);
		}
	}
	else
	{
		if (z.e[j].a < z.e[r].a)
		{
			swap(z.e[j], z.e[r]);
			heapNode(z, r, n);
		}
	}
}

void heapsort(List& z)
{
	for (int i = z.count / 2 - 1; i >= 0; i--)
	{
		heapNode(z, i, z.count);
	}
	for (int i = z.count; i >= 2; i--)
	{
		swap(z.e[0], z.e[i - 1]);
		heapNode(z, 0, i - 1);
	}
}


///merger
void merge(List& l, List& z, int bt1, int bt2, int w1, int w2)
{
	int bp1 = bt1 + w1 - 1;
	int bp2 = bt2 + w2 - 1;
	int i = bt1;
	int j = bt2;
	int k = bt1;
	while (i <= bp1 && j <= bp2)
	{
		if (l.e[j].a < l.e[i].a)
		{
			z.e[k] = l.e[j];
			j++;
			k++;
		}
		else
		{
			z.e[k] = l.e[i];
			i++;
			k++;
		}
	}
	while (j <= bp2)
	{
		z.e[k] = l.e[j];
		j++;
		k++;
	}
	while (i <= bp1)
	{
		z.e[k] = l.e[i];
		i++;
		k++;
	}
	for (int c = bt1; c <= bp2; c++)
	{
		l.e[c] = z.e[c];
	}
}
void pass(List& l, List& z, int k)
{
	int SoCap = l.count / (2 * k);
	int SoPtTrongCap = 2 * k * SoCap;
	int SoPtLe = l.count - SoPtTrongCap;
	for (int i = 1; i <= SoCap; i++)
	{
		int bt1 = (2 * i - 2) * k;
		merge(l, z, bt1, bt1 + k, k, k);
	}
	if (SoPtLe > k)
		merge(l, z, 0, SoPtTrongCap + k, k, SoPtLe - k);
}

void mergeSort(List& l)
{
	int k = 1;
	List z;
	z.count = l.count;
	while (k < l.count)
	{
		pass(l, z, k);
		k *= 2;
	}
	xuat(l);
}

struct Node
{
	DataType e;
	Node* next;
};

typedef Node* tro;


void createNode(tro& li)
{
	li = NULL;
}

bool empty(tro li)
{
	return li == NULL;
}

void travel(tro li)
{
	if (li != NULL)
	{
		tro p = li;
		while (p != NULL)
		{
			output(p->e);
			p = p->next;
		}
		cout << "\n";
	}
}

tro search(tro li)
{
	tro q = li;
	while (q != NULL/*&& dk*/)
	{
		q->next;
	}
	return q;
}

void firstAdd(tro& li)
{
	DataType e;
	e = input(1);
	Node* p = new Node;
	p->e = e;
	p->next = li;
	li = p;
}

void endAdd(tro& li)
{
	DataType e;
	e = input(1);
	Node* p = new Node;
	p->e = e;
	p->next = NULL;
	tro q = li;
	if (li == NULL) li = p;
	else
	{
		while (q != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

void insert(tro& li)
{
	DataType e;
	e = input(1);
	Node* p = new Node;
	p->e = e;
	tro q = li;
	while (q != NULL/*&& dk*/)
	{
		q->next;
	}
	p->next = q->next;
	q->next = p;
}

void firstDel(tro& li)
{
	tro q = li;
	li = li->next;
	delete q;
}

void xoa(tro& li)
{
	DataType e;
	e = input(1);
	Node* p = new Node;
	p->e = e;
	tro q = li;
	while (q != NULL/*&& dk*/)
	{
		q->next;
	}
	tro m = q->next;
	q->next = m->next;
	delete m;
}

void createNode1(tro& li)
{
	DataType e;
	tro q = li;
	char tt;
	do
	{
		e = input(1);
		Node* p = new Node;
		p->e = e;
		p->next = NULL;
		if (empty(li)) li = p;
		else
		{
			q->next = p;
		}
		q = p;
		cout << "\nCo nhap ko(Y/N)? ";
		cin >> tt;
	} while (toupper(tt) == 'y' || toupper(tt) == 'Y');
}