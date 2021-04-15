#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
#define ma 10
#define ten 30
struct Data
{
	char HoTen[ten], gt[ma];
	int nam;
	float DiemTK;
};
struct List
{
	int count;
	Data* a;
};
void Xep(List& l)
{
	for (int i = 0; i < l.count - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < l.count; j++)
			if (l.a[j].DiemTK > l.a[m].DiemTK)
				m = j;
		swap(l.a[m], l.a[i]);
	}
}
int timTT(List l, char name[], float diem)
{
	int kq = -1;

	for (int i = 0; i < l.count; i++)
	{
		//cout << "\n" << l.a[i].HoTen;
		if (l.a[i].DiemTK == diem && strcmp(name, l.a[i].HoTen) == 0)
		{
			kq = i;
		}
		else i++;
	}
	return kq;
}
int BinSear(List& l, int le, int ri, float diem)
{
	if (le < ri)
	{
		int m = (le + ri) / 2;
		if (l.a[m].DiemTK == diem)
		{
			cout << "\nSv can tim o vi tri: " << m + 1;
			exit(0);
		}
		else
		{
			if (l.a[m].DiemTK < diem)
				return BinSear(l, m + 1, ri, diem);
			else
				return BinSear(l, le, m - 1, diem);
		}
	}
}
int nm0()
{
	int n;
	do
	{
		cout << "Gia tri: ";
		cin >> n;
	} while (n < 0);
	return n;
}
ostream& operator<<(ostream& x, List y)
{
	cout << "\n" << setw(ten) << "HoTen" << setw(ma) << "gt" << setw(ma) << "nam" << setw(ma) << "DiemTK";
	for (int i = 0; i < y.count; i++)
	{
		cout << "\n" << setw(ten) << y.a[i].HoTen << setw(ma) << y.a[i].gt << setw(ma) << y.a[i].nam << setw(ma) << y.a[i].DiemTK;
	}
	return x;
}
istream& operator>>(istream& x, List& y)
{
	cout << "Nhap so sv\n";
	y.count = nm0();
	y.a = new Data[y.count];
	for (int i = 0; i < y.count; i++)
	{
		fflush(stdin);
		cin.ignore();
		cout << "Nhap ho ten sv: ";
		cin.getline(y.a[i].HoTen, ten);
		cout << "Nhap gioi tinh sv: ";
		cin.getline(y.a[i].gt, ten);
		cout << "Nhap nam sinh sv: ";
		cin >> y.a[i].nam;
		cout << "Nhap diem sv: ";
		cin >> y.a[i].DiemTK;
	}
	return x;
}
int main()
{
	List l;
	cin >> l;
	cout << l;
	Xep(l);
	cout << l;
	char a[ten];
	cout << "\nNhap ten can tim: ";
	fflush(stdin);
	cin.ignore();
	cin.getline(a, ten);
	cout << "\nNhap diem can tim: ";
	float k;
	cin >> k;
	int kq = timTT(l, a, k);
	if (kq > -1)
		cout << "\nSv can tim o vi tri: " << kq + 1;
	else
		cout << "\nKhong tim thay";
	cout << "\nNhap diem can tim: ";
	cin >> k;
	BinSear(l, 0, l.count + 1, k);
	cout << "\nKhong tim thay";
	return 0;
}