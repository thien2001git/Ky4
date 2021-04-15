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
void selection(List& l)
{
	for (int i = 0; i < l.count - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < l.count; j++)
			if (strcmp(l.a[m].HoTen, l.a[j].HoTen) == 1)
				m = j;
		swap(l.a[i], l.a[m]);
	}
}
int main()
{
	List l;
	cin >> l;
	cout << l;
	selection(l);
	cout << l;
	return 0;
}