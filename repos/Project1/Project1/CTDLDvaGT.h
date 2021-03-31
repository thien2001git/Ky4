#pragma once
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
void heapNode(List& z, int j)
{
	if (j * 2 + 1 < z.count)
	{
		int l = j * 2 + 1;
		int r = j * 2 + 2;
		if (z.e[l].a > z.e[j].a)
		{
			swap(z.e[j], z.e[l]);
			heapNode(z, l);
		}
		if (z.e[r].a > z.e[j].a)
		{
			swap(z.e[j], z.e[r]);
			heapNode(z, r);
		}
		heapNode(z, j - 1);
	}
}

void heapsort(List& z)
{
	for (int i = z.count - 1; i >= 0; i--)
	{
		heapNode(z, z.count / 2 - 1);
		swap(z.e[i], z.e[0]);
	}
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