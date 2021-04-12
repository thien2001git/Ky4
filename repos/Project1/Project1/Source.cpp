#include"CTDL/BaiTH1.h"
#include"CTDL/BaiTH2.h"
#include"CTDL/BaiTH3.h"
#include"CTDL/BaiTH4.h"
#include"BaiTH5.h"
#include"BaiTH6.h"
#include"BaiTH7.h"
#include"BaiTH8.h"
//#include"BaiTH6.1.h"

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
		case 3:
		{
			int* a, n;
			n = nm0();
			a = new int[n];
			nm(a, n);
			mergeSort(a, n);
			xm(a, n);
			break;
		}
		case 4:
		{
			int n;
			cout << "n = ";
			cin >> n;
			sv* a = new sv[n];
			for (int i = 0; i < n; i++) cin >> a[i];
			for (int i = 0; i < n; i++) cout << a[i];
			qs1(0, n - 1, a);
			for (int i = 0; i < n; i++) cout << a[i];
			break;
		}
		default: return main();
			break;
		}
		break;
	}
	case 6:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			ListSV l;
			cout << "\n" << l;
			l.remove(0);
			cout << "\n" << l;
			SINHVIEN e;//(masv, "pp", "cc", 2001, 0, 9.5);
			e.nhap();
			l.insert(e, 2);
			cout << "\n" << l;
			chonTen(l);
			cout << "\n" << l;
			break;
		}
		case 2:
		{
			cout << "O file BaiTH6.1.cpp";
			break;
		}
		default: return main();
			break;
		}
		break;
	}
	case 7:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			int n;
			cout << "n = ";
			cin >> n;
			int q;
			cout << "Nhap he so: ";
			cin >> q;
			Stack s{};
			init(s);
			cd(s, n, q);
			xx(s);
			break;
		}
		case 2:
		{
			Stack1 s{};
			init1(s);
			/*cout << "Nhap day ngoac: ";
			fflush(stdin);
			cin.ignore();*/
			string a;
			cout << "Nhap day ngoac: ";
			cin >> a;
			for (int i = 0; i < a.length(); i++)
				s.a[i] = a[i];
			s.top = a.length() - 1;
			int kq = cd1(s);
			if (kq == 1) cout << "\nDay dung";
			else cout << "\nDay sai";
			break;
		}
		case 3:
		{
			int n = nm0();
			Stack2 s;
			s.top = n - 1;
			nm(s.a, n);
			xm(s.a, s.top + 1);
			loai2(s, 2);
			cout << "\n";
			xm(s.a, s.top + 1);
			break;
		}
		default: return main();
			break;
		}


		break;
	}
	case 8:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			Quere x;
			init2(x);
			nhapKT(x);
			cout << x.a;
			break;
		}
		default: return main();
			break;
		}
		break;
	}
	case 9:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{
			break;
		}
		default: return main();
			break;
		}
		break;
	}
	case 10:
	{
		int qq = nhapB();
		switch (qq)
		{
		case 1:
		{

			break;
		}
		default: return main();
			break;
		}
		break;
	}
	default: return main();
		break;
	}
	return 0;
}

