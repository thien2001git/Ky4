#include"CTDL/BaiTH1.h"
#include"CTDL/BaiTH2.h"
#include"CTDL/BaiTH3.h"
#include"CTDL/BaiTH4.h"
#include"BaiTH5.h"

int nhapB()
{
	cout << "Nhap bai: ";
	int nn;
	cin >> nn;
	return nn;
}
int main()
{
	cout << "Nhap bai th: ";
	int nn;
	cin >> nn;
	switch (nn)
	{
	case 1:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			int n;
			cout << "n = ";
			cin >> n;
			cout << "\n";
			cout << fibonaci(n);
			break;
		}
		case 2:
		{
			int n;
			cout << "n = ";
			cin >> n;
			thapHaNoi('x', 'y', 'z', n);
			break;
		}
		case 3:
		{
			int n, m;
			cout << "a = ";
			cin >> n;
			cout << "b = ";
			cin >> m;
			cout << ucln(m, n);
			break;
		}

		case 4:
		{
			int n;
			cout << "n = ";
			cin >> n;
			int* a = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i + 1 << "] = ";
				cin >> a[i];
			}
			cout << max(a, 0, n);
			break;
		}
		case 5:
		{
			int n, a;
			cout << "n = ";
			cin >> n;
			cout << "a = ";
			cin >> a;
			cout << gt(a, n);
			break;
		}
		case 6:
		{
			int n;
			cout << "n = ";
			cin >> n;
			int* a = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i + 1 << "] = ";
				cin >> a[i];
			}
			cout << dem0(a, 0, n, 8);
			break;
		}
		default: return main();
			break;
		}
		break;
	}
	case 2:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			int n;
			cout << "n = ";
			cin >> n;
			int* a = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i + 1 << "] = ";
				cin >> a[i];
			}
			cout << itNhat(a, n, 5);
			break;
		}
		case 2:
		{
			int n;
			cout << "n = ";
			cin >> n;
			DoVat* a = new DoVat[n];
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i + 1 << "] = ";

			}
			break;
		}
		case 3:
		{
			int n, x, y;
			cout << "n = ";
			cin >> n;
			cout << "x = ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			if (n % 2 == 1) cout << "\nKhong co duong di";
			else if (n == 2 || n == 1 || n == 4) cout << "\nKhong co duong di";
			else dc(x, y, n);
			break;
		}
		default: return main();
			break;
		}
		break;
	}
	case 3:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			int n;
			cout << "n = ";
			cin >> n;
			int* a = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i + 1 << "] = ";
				cin >> a[i];
			}
			cout << "\n" << Tim(a, n, 8);
			break;
		}
		case 2:
		{
			int n;
			cout << "n = ";
			cin >> n;
			int* a = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i + 1 << "] = ";
				cin >> a[i];
			}
			cout << "\n" << timNhi(a, 0, n, 8);
			break;
		}
		case 3:
		{
			break;
		}
		default: return main();
			break;
		}
		break;
	}
	case 4:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			int* a, n;
			n = nm0();
			a = new int[n];
			nm(a, n);
			buble(a, n);
			xm(a, n);
			break;
		}
		case 2:
		{
			int* a, n;
			n = nm0();
			a = new int[n];
			nm(a, n);
			selection(a, n);
			xm(a, n);
			break;
		}
		case 3:
		{
			int* a, n;
			n = nm0();
			a = new int[n];
			nm(a, n);
			insertion(a, n);
			xm(a, n);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 5:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			int* a, n;
			n = nm0();
			a = new int[n];
			nm(a, n);
			qs(0, n - 1, a);
			xm(a, n);
			break;
		}
		case 2:
		{
			int* a, n;
			n = nm0();
			a = new int[n];
			nm(a, n);
			heapSort(a, n);
			xm(a, n);
			break;
		}
		default:
			break;
		}
		break;
	}
	default: return main();
		break;
	}
	return 0;
}

