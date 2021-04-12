#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
int gt(int a, int n)
{
	if (n == 1) return a;
	else if (n % 2 == 1) return gt(a, n / 2) * gt(a, n / 2) * a;
	else return gt(a, n / 2) * gt(a, n / 2);
}
void buble(int* a, int n)
{
	int i = 0;
	while (i < n - 1)
	{
		int j = n - 1;
		while (j > i)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
			j--;
		}
		i++;
	}
}
#define ma 10
#define ten 30
class ListSV;
class SINHVIEN
{
public:
	//SINHVIEN();
	//SINHVIEN(char *a0, char *a1, char *a2, int a3, int a4, float a5);
	void nhap();
	friend ostream& operator<<(ostream& x, SINHVIEN y);
	friend void chonTen(ListSV l);
private:
	char Masv[ma], HoDem[ten], Ten[ma];
	int gt, ns;
	float diem;
};

class ListSV
{
public:
	ListSV();
	//ListSV(SINHVIEN* z);
	~ListSV();
	int empty();
	int full();
	int add(SINHVIEN e);
	int insert(SINHVIEN e, int k);
	int remove(int k);
	friend ostream& operator<<(ostream& x, ListSV y);
	friend void chonTen(ListSV a);
private:
	int count;
	SINHVIEN* a;
};

#pragma warning(disable 4996)

ostream& operator<<(ostream& x, SINHVIEN y)
{
	x << setw(10) << y.Masv << setw(ten) << y.HoDem << setw(ma) << y.Ten << setw(ma);
	if (y.gt == 0) x << "Nu";
	else x << "Nam";
	x << setw(ma) << y.ns << setw(ma) << y.diem;
	return x;
}
class Node;
class Node
{
public:
	~Node();
	int empty();
	SINHVIEN infor;
	Node* next;
};
typedef Node* tro;
void nhap(tro& l)
{
	tro q = l;
	char tt;
	//cout << "\nsikajs";
	do
	{
		Node* p;
		p = new Node;
		SINHVIEN e;
		e.nhap();
		p->infor = e;
		p->next = NULL;
		if (l == NULL)
		{
			l = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
		cout << "\nCo nhap ko: ";
		cin >> tt;
		fflush(stdin);
		cin.ignore();
	} while (tt == 'c');

}

Node::~Node()
{
}

int Node::empty()
{
	return this == NULL;
}

void Finsert(tro& l, SINHVIEN e)
{
	tro p;
	p = new Node;
	p->infor = e;
	p->next = l;
	*l = *p;
}

void Einsert(tro& l, SINHVIEN e)
{
	tro p, q;
	p = new Node;
	p->infor = e;
	p->next = NULL;
	if (l->empty() == 1) l = p;
	else
	{
		q = l;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

void Minsert(Node* q, SINHVIEN e)
{
	tro p;
	p = new Node;
	p->infor = e;
	p->next = q->next;
	q->next = p;
}

void Fremove(tro& l)
{
	tro q = l;
	l = q->next;
	delete q;
}

void Mremove(Node* m)
{
	tro q = m->next;
	m->next = q->next;
	delete q;
}

Node* search(tro l, int k)
{
	tro q = l;
	int i = 0;
	while (q != NULL && i < k)
	{
		q = q->next;
		i++;
	}
	return q;
}

inline void travel(tro l)
{
	if (l != NULL)
	{
		tro q = l;
		while (q != NULL)
		{
			cout << "\n" << q->infor;
			q = q->next;
		}
	}
}