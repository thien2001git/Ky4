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
int itNhat(int* a, int n, int target)
{
	int sum = 0, dem = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[m] < a[j])
			{
				m = j;
			}

		}
		swap(a[m], a[i]);
		sum += a[i];
		dem++;
		if (sum > target) break;
	}
	return dem;
}
int main()
{
	List z;
	cout << "\nNhap so: ";
	int tar;
	cin >> tar;
	cout << "\nCan it nhat " << itNhat(z.a, z.n, tar) << " phan tu de lon hon " << tar;
	return 0;
}