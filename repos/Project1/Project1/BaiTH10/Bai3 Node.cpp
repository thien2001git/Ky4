#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
#define ma 10
#define ten 30
class SINHVIEN
{
public:
	void nhap();
	//SINHVIEN(char *a0, char *a1, char *a2, int a3, int a4, float a5);
	friend ostream& operator<<(ostream& x, SINHVIEN y);
private:
	char Masv[ma], HoDem[ten], Ten[ma];
	int gt, ns;
	float diem;
};

void SINHVIEN::nhap()
{
	cout << "\nNhap ma sv: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin.getline(Masv, ma);
	cout << "Nhap ho dem sv: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin.getline(HoDem, ma);
	cout << "Nhap ten sv: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin.getline(Ten, ma);
	cout << "Nhap nam sinh sv: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin >> ns;
	cout << "Nhap gioi tinh sv: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin >> gt;
	cout << "Nhap diem sv: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin >> diem;

}
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
		cout << setw(10) << "Masv" << setw(ten) << "HoDem" << setw(ma) << "Ten" << setw(ma) << "GT" << setw(ma) << "ns" << setw(ma) << "diem";

		while (q != NULL)
		{
			cout << "\n" << q->infor;
			q = q->next;
		}
	}
}
int main()
{
	Node* l;
	l = NULL;
	nhap(l);
	cout << "\n";
	travel(l);
	Node* q = search(l, 1);
	///*q = ;*/
	SINHVIEN e;
	e.nhap();
	cout << "\nINSERT\n";
	Minsert(q, e);
	cout << "\n";
	travel(l);
	return 0;
}