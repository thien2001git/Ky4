#include<iostream>
using namespace std;
void xm(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << a[i];
	}
}
int nm0()
{
	int n;
	cout << "n = ";
	cin >> n;
	return n;
}
void nm(int *a, int& n)
{
	
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}
/*Bài 1: Sắp xếp nổi bọt Bài toán:
Cho dãy số nguyên x = {34,   14,   24,   54,   84,   64,   94,  74,  04}
Yêu cầu:
- Mô tả quá trình sắp xếp dãy số nguyên x theo chiều giảm dần bằng phương pháp sắp xếp nổi bọt.
- Thiết kế giải thuật tìm sắp xếp.
- Cài đặt chương trình ứng dụng.*/
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
/*Bài 2: Sắp xếp lựa chọn Bài toán:
Cho dãy số nguyên x = {34,   14,   24,   54,   84,   64,   94,  74,  04}
Yêu cầu:
- Mô tả quá trình sắp xếp dãy số nguyên x theo chiều giảm dần bằng phương pháp sắp xếp lựa chọn.
- Thiết kế giải thuật tìm sắp xếp.
- Cài đặt chương trình ứng dụng. */
void selection(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++)
			if (a[m] < a[j])
				m = j;
		swap(a[i], a[m]);
	}
}
/*Bài 3: Sắp xếp chèn
Bài toán:
Cho dãy số nguyên x = {34, 14, 24, 54, 84, 64, 94, 74, 04}
Yêu cầu:
- Mô tả quá trình sắp xếp dãy số nguyên x theo chiều giảm dần bằng phương pháp sắp xếp chèn.
- Thiết kế giải thuật tìm sắp xếp.
- Cài đặt chương trình ứng dụng.*/
void insertion(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int tam = a[i];
		int j = i;
		while (a[j] > tam && j >= 0);
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tam;
	}
}