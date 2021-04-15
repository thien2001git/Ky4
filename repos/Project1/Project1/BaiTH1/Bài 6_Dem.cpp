#pragma once
#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
using namespace std;
class List
{
public:
	List();
	~List();
	friend int main();
private:
	int* a, n;
};

List::List()
{
	do
	{
		cout << "Nhap so pt mang: ";
		cin >> n;
	} while (n < 1);
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap pt thu " << i << ": ";
		cin >> a[i];
	}
}

List::~List()
{

}
int dem0(int* a, int l, int r, int k)
{
	if (r == l)
	{
		if (a[r] == k) return 1;
		else return 0;
	}
	else
	{
		int m = (l + r) / 2;
		return dem0(a, l, m, k) + dem0(a, m + 1, r, k);
	}
}
int main()
{
	List z;
	cout << "Nhap so can dem: ";
	int k;
	cin >> k;
	cout << "\nCo " << dem0(z.a, 0, z.n, k) << " phan tu.";
	return 0;
}