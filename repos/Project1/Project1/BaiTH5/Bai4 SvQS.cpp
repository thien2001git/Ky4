#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
#define ma 10
#define ten 30
using namespace std;
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
int main()
{
	int n;
	do
	{
		cout << "n = ";
		cin >> n;
	} while (n < 0);
	
	sv* a = new sv[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << "\n" << setw(ten) << "HoTen" << setw(ma) << "gt" << setw(ma) << "nam" << setw(ma) << "DiemTK";
	for (int i = 0; i < n; i++) cout << a[i];
	qs1(0, n - 1, a);
	cout << "\n" << setw(ten) << "HoTen" << setw(ma) << "gt" << setw(ma) << "nam" << setw(ma) << "DiemTK";
	for (int i = 0; i < n; i++) cout << a[i];
	return 0;
}