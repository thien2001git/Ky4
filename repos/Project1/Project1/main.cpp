#include"HDT.h"
int main()
{
	//int n;
	//do
	//{
	//	cout << "Nhap so hang: ";
	//	cin >> n;
	//} while (n < 0);

	//Hang* a = new Hang[n];
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> a[i];
	//}
	//cout << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	cout << a[i];
	//}
	//char s[20] = { "HANGNHAP.DAT" };
	//xuat(a, n, s);
	////delete[] s;
	//strcpy(s, "IPHONE 12");
	//choBiet(a, n, s);
	//sep(a, n);
	//cout << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	cout << a[i];
	//}
	//strcpy(s, "HANGSORT.TXT");
	//xuat(a, n, s);
	//strcpy(s, "H005");
	//xoa(a, n, s);
	//cout << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	cout << a[i];
	//}
	//strcpy(s, "HANGREMOVE.TXT");
	//xuat(a, n, s);
	//xoa1(a, n, 20);
	//cout << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	cout << a[i];
	//}
	//strcpy(s, "HANGREMOVE.TXT");
	//xuat1(a, n, s);


	int* a = new int[5];
	a[0] = 9;
	a[1] = 9;
	a[2] = 9;
	a[3] = 9;
	cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "\t" << a[i];
	}
	cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "\t" << &a[i];
	}
	delete[] a;
	for (int i = 0; i < 4; i++)
	{
		cout << "\t" << i;
	}
	return 0;
}