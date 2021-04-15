#include"HDT.h"
int main()
{
	int n;
	do
	{
		cout << "Nhap so hang: ";
		cin >> n;
	} while (n < 0);

	Hang* a = new Hang[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	char s[20] = { "HANGNHAP.DAT" };
	xuat(a, n, s);
	delete[] s;
	strcpy(s, "IPHONE 12");
	choBiet(a, n, s);
	return 0;
}