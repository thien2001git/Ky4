#pragma once
#pragma once
#include<iostream>
using namespace std;
class PhanSo
{
	
public:
	PhanSo operator+(PhanSo q);
	PhanSo operator*(PhanSo q);
	PhanSo operator/(PhanSo q);
	PhanSo operator-(PhanSo q);
	PhanSo operator-();
	friend istream& operator>>(istream& x, PhanSo& p);
	friend ostream& operator<<(ostream& x, PhanSo p);
private:
	float x, y;
};

PhanSo PhanSo::operator+(PhanSo q)
{
	PhanSo p;
	if (y = q.y)
	{
		p.x = x + q.x;
		p.y = y;
	}
	else
	{
		p.y = y * q.y;
		p.x = y * q.x + x * q.y;
	}
	return p;
}
PhanSo PhanSo::operator-(PhanSo q)
{
	PhanSo p;
	if (y = q.y)
	{
		p.x = x - q.x;
		p.y = y;
	}
	else
	{
		p.y = y * q.y;
		p.x = - y * q.x + x * q.y;
	}
	return p;
}
PhanSo PhanSo::operator-()
{
	x = -x;
	return *this;
}
inline PhanSo PhanSo::operator*(PhanSo q)
{
	PhanSo p;
	p.x = x * q.x;
	p.y = y * q.y;
	return p;
}
inline PhanSo PhanSo::operator/(PhanSo q)
{
	PhanSo p;
	p.x = x * q.y;
	p.y = y * q.x;
	return p;
}
istream& operator>>(istream& x, PhanSo& p)
{
	cout << "\nNhap tu so: ";
	x >> p.x;
	do
	{
		cout << "Nhap mau so: ";
		x >> p.y;
	} while (p.y<0);
	return x;
}
ostream& operator<<(ostream& x, PhanSo p)
{
	x << "\n" << p.x << "/" << p.y;
	return x;
}
///////////////////////////
class Complex
{
public:
	Complex();
	~Complex();

private:

};

Complex::Complex()
{
}

Complex::~Complex()
{
}