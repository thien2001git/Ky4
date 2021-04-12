#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
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

//SINHVIEN::SINHVIEN()
//{
//	cout << "Nhap ma sv: ";
//	fflush(stdin);
//	cin.ignore();
//	cin.getline(Masv, ma);
//	cout << "Nhap ho dem sv: ";
//	/*fflush(stdin);
//	cin.ignore();*/
//	cin.getline(HoDem, ma);
//	cout << "Nhap ten sv: ";
//	/*fflush(stdin);
//	cin.ignore();*/
//	cin.getline(Ten, ma);
//	cout << "Nhap nam sinh sv: ";
//	/*fflush(stdin);
//	cin.ignore();*/
//	cin >> ns;
//	cout << "Nhap gioi tinh sv: ";
//	/*fflush(stdin);
//	cin.ignore();*/
//	cin >> gt;
//	cout << "Nhap diem sv: ";
//	/*fflush(stdin);
//	cin.ignore();*/
//	cin >> diem;
//
//}
#pragma warning(disable 4996)
void SINHVIEN::nhap()
{
	cout << "Nhap ma sv: ";
	fflush(stdin);
	cin.ignore();
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
//SINHVIEN::SINHVIEN(char* a0, char* a1, char* a2, int a3, int a4, float a5)
//{
//	strcpy(Masv, a0);
//	strcpy(HoDem, a1);
//	strcpy(Ten, a2);
//	ns = a3;
//	gt = a4;
//	diem = a5;
//}
ostream& operator<<(ostream& x, SINHVIEN y)
{
	x << setw(10) << y.Masv << setw(ten) << y.HoDem << setw(ma) << y.Ten << setw(ma);
	if (y.gt == 0) x << "Nu";
	else x << "Nam";
	x << setw(ma) << y.ns << setw(ma) << y.diem;
	return x;
}

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

ListSV::ListSV()
{
	cout << "\nNhap n = ";
	cin >> count;
	a = new SINHVIEN[count];


}



ListSV::~ListSV()
{
}

int ListSV::empty()
{
	return count == -1;
}

int ListSV::full()
{
	return count == count + 20;
}

int ListSV::add(SINHVIEN e)
{
	if (full() == 1)
		return 0;
	else
	{
		a[count] = e;
		count++;
		return 1;
	}
}

inline int ListSV::insert(SINHVIEN e, int k)
{
	if (full() == 1)
		return 0;
	else
	{

		for (int i = count; i > k; i--)
			a[i] = a[i - 1];
		a[k] = e;
		count++;
		return 1;
	}
}

int ListSV::remove(int k)
{
	if (empty() == 1)
		return 0;
	else
	{
		for (int i = k; i < count; i++)
			a[i] = a[i + 1];
		count--;
		return 1;
	}
}

ostream& operator<<(ostream& x, ListSV y)
{
	for (int i = 0; i < y.count; i++)
	{
		x << "\n" << y.a[i];
	}
	return x;
}

void chonTen(ListSV l)
{

	for (int i = 0; i < l.count - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < l.count; j++)
		{
			char* z1 = new char[sizeof(l.a[m].Ten)];
			char* z2 = new char[sizeof(l.a[j].Ten)];
			strcpy(z1, l.a[m].Ten);
			strcpy(z2, l.a[j].Ten);
			if (strcmp(z1, z2) == 1)
				m = j;
		}
		swap(l.a[i], l.a[m]);
	}
}

/*---------------------------------
-----------------------------------*/

class Node
{
public:
	void nhap();
	~Node();
	int empty();

	void Finsert(SINHVIEN e);
	void Einsert(SINHVIEN e);
	void Minsert(Node* q, SINHVIEN e);
	void Fremove();
	void Mremove(Node* m);
	Node* search(int k);
	void travel();
private:
	SINHVIEN infor;
	Node* next;
};
typedef Node* tro;
void Node::nhap()
{
	tro p, q;
	q = this;
	char tt;
	//cout << "\nsikajs";

	{
		SINHVIEN e;
		e.nhap();
		p = new Node;
		p->infor = e;
		p->next = NULL;
		if (this == NULL) *this = *p;
		else
		{
			q->next = p;
		}
		q = p;
		cout << "\nCo nhap ko: ";
		cin >> tt;
	} while (tt == 'c');

}

Node::~Node()
{
}

int Node::empty()
{
	return this == NULL;
}

void Node::Finsert(SINHVIEN e)
{
	tro p;
	p = new Node;
	p->infor = e;
	p->next = this;
	*this = *p;
}

inline void Node::Einsert(SINHVIEN e)
{
	tro p, q;
	p = new Node;
	p->infor = e;
	p->next = NULL;
	if (this->empty() == 1) *this = *p;
	else
	{
		q = this;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

void Node::Minsert(Node* q, SINHVIEN e)
{
	tro p;
	p = new Node;
	p->infor = e;
	p->next = q->next;
	q->next = p;
}

void Node::Fremove()
{
	tro q = this;
	*this = *q->next;
	delete q;
}

void Node::Mremove(Node* m)
{
	tro q = m->next;
	m->next = q->next;
	delete q;
}

Node* Node::search(int k)
{
	tro q = this;
	int i = 0;
	while (q != NULL && i < 2)
	{
		q = q->next;
		i++;
	}
	return q;
}

inline void Node::travel()
{
	if (this != NULL)
	{
		tro q = this;
		while (q != NULL)
		{
			cout << "\n" << q->infor;
			q = q->next;
		}
	}
}