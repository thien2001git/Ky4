#include<iostream>
using namespace std;
/*Bài 1: Tìm số fibonaci
Yêu cầu:
- Viết định nghĩa đệ quy tìm số fibonaci thứ n (n ≥ 1) trong dãy số fibonaci
- Thiết kế giải thuật đệ quy theo định nghĩa trên.
- Cài đặt chương trình ứng dụng thực hiện:
o Tìm và hiển thị số fibonaci thứ n.
o Tìm và hiển thị dãy n số fibonaci.*/
unsigned int fibonaci(int n)
{
	if (n <= 1) return 1;
	else
	{
		return fibonaci(n - 1) + fibonaci(n - 2);
	}
}
/*Bài 2: Tháp Hà Nội
Yêu cầu:
- Mô tả quá trình chuyển đĩa với số lượng đĩa n = 3.
- Thiết kế giải thuật đệ quy giải quyết bài toán.
- Cài đặt chương trình ứng dụng.
- Đưa ra nhận xét khi số lượng đĩa tăng lên.*/
void thapHaNoi(char a, char b, char c, int n)
{
	if (n == 1) cout << "\n" << a << " -> " << c;
	else
	{
		thapHaNoi(a, c, b, n - 1);
		thapHaNoi(a, b, c, 1);
		thapHaNoi(b, a, c, n - 1);
	}
}
/*Bài 3: Tìm ước số chung lớn nhất
Yêu cầu:
- Viết định nghĩa đệ quy tìm ước số chung lớn nhất theo thuật toán Euclid.
- Thiết kế giải thuật đệ quy theo định nghĩa trên.
- Cài đặt chương trình ứng dụng giải thuật.
*/
unsigned int ucln(int a, int b)
{
	if (a == b) return a;
	else
	{
		if (a > b)
			return ucln(a - b, b);
		else
			return ucln(a, b - a);
	}
}
/*Bài 4: Tìm giá trị lớn nhất
Yêu cầu:
- Mô tả quá trình tìm giá trị lớn nhất trên dãy số theo chiến lược chia để trị.
- Thiết kế giải thuật tìm giá trị lớn nhất trên dãy số theo chiến lược chia để trị.
- Cài đặt chương trình ứng dụng.
*/
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
/*Bài 5: Tính an
- Mô tả cách tính 29
theo chiến lược chia để trị.
- Thiết kế giải thuật tính an
theo chiến lược chia để trị.
- Cài đặt chương trình ứng dụng.
*/
int gt(int a, int n)
{
	if (n == 1) return a;
	else if (n % 2 == 1) return gt(a, n / 2) * gt(a, n / 2) * a;
	else return gt(a, n / 2) * gt(a, n / 2);
}
/*Bài 6: Đếm số trong dãy
- Mô tả cách đếm số lần xuất hiện của một số x trong dãy a có n số theo chiến
lược chia để trị.
- Viết định nghĩa đệ quy theo mô tả trên.
- Thiết kế giải thuật đếm theo chiến lược chia để trị.*/
int dem(int* a, int l, int r,  int k)
{
	if (r == l)
	{
		if (a[r] == k) return 1;
		else return 0;
	}
	else
	{
		int m = (l + r) / 2;
		return dem(a, l, m, k) + dem(a, m + 1, r, k);
	}
}