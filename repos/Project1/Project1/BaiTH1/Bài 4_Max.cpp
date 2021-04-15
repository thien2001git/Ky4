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
int max(int* a, int l, int r)
{
	if (l == r) return a[r];
	else if (r == l + 1)
	{
		if (a[l] > a[r]) return a[l];
		else return a[r];
	}
	else
	{
		int m = (l + r) / 2;
		int d1 = max(a, l, m);
		int d2 = max(a, m + 1, r);
		if (d1 < d2) return d2;
		else return d1;
	}
}

int main()
{
	List z;
	cout << "\nMax = " << max(z.a, 0, z.n - 1);
	return 0;
}