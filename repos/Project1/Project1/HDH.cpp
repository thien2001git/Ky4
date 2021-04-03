#include <iostream>
#include <iomanip>
#include<string.h>
using namespace std;
class List;
class process
{
private:
	float Txh, Txl;
	int Ten;

public:
	friend istream& operator>>(istream& x, process& y);
	friend ostream& operator<<(ostream& x, process y);
	friend istream& operator>>(istream& x, List& y);
	friend void xep(List& z);
	friend float fcfs(List z);
	friend int main();
	friend float waitTime(process* gantt, int n, int m, List z);
	friend void sjf(List z);
};

istream& operator>>(istream& x, process& y)
{
	cout << "Nhap thoi gian xuat hien: ";
	x >> y.Txh;
	cout << "Nhap thoi gian xu li:     ";
	x >> y.Txl;
	return x;
}

ostream& operator<<(ostream& x, process y)
{
	x << "\n"
		<< setw(10) << y.Ten
		<< setw(10) << y.Txh << setw(10) << y.Txl;
	return x;
}

class List
{
private:
	process* a;
	int n;

public:
	friend istream& operator>>(istream& x, List& y);
	friend ostream& operator<<(ostream& x, List y);
	friend void xep(List& z);
	friend float fcfs(List z);
	friend int main();
	friend float waitTime(process* gantt, int n, int m, List z);
	friend void sjf(List z);
};

istream& operator>>(istream& x, List& y)
{
	do
	{
		/* code */
		cout << "Nhap so tien trinh: ";
		x >> y.n;
	} while (y.n < 0);
	int i = 0;
	y.a = new process[y.n];
	while (i < y.n)
	{
		cout << "Nhap tien trinh thu " << i + 1 << "\n";
		x >> y.a[i];
		y.a[i].Ten = i;
		bool check = true;
		for (int j = 0; j < i; j++)
		{
			if (y.a[i].Txh == y.a[j].Txh)
			{
				check = false;
				break;
			}
		}
		if (check)
			i++;
		else
			cout << "Nhap lai\n";
	}
	return x;
}

ostream& operator<<(ostream& x, List y)
{
	x << "\n"
		<< setw(10) << "Ten"
		<< setw(10) << "Txh" << setw(10) << "Txl";
	for (int i = 0; i < y.n; i++)
	{
		x << y.a[i];
	}
	return x;
}

void xep(List& z)
{
	for (int i = 0; i < z.n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < z.n; j++)
			if (z.a[m].Txh > z.a[j].Txh)
				m = j;
		process q = z.a[i];
		z.a[i] = z.a[m];
		z.a[m] = q;
	}
}


float waitTime(process* gantt, int n, int m, List z)
{
	float sum = 0, i = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int dem[100];
			int d1 = -1;
			if (gantt[i].Ten == gantt[j].Ten)
			{
				d1++;
				dem[d1] = j;
				if (d1 <= 0)sum += gantt[j].Txh - z.a[i].Txh;
				else sum += gantt[j].Txh - (gantt[dem[d1 - 1]].Txh + gantt[dem[d1 - 1]].Txl);

			}
		}
	}
	return sum;
}

float fcfs(List z)
{
	process* gantt = new process[z.n];
	//cout << gantt.n;
	gantt[0] = z.a[0];
	float tong = z.a[0].Txl;
	// float tong = 0;
	//cout<<gantt;
	for (int i = 1; i < z.n; i++)
	{
		gantt[i].Ten = z.a[i].Ten;
		if (z.a[i].Txh <= tong)
		{
			gantt[i].Txh = tong;
			gantt[i].Txl = z.a[i].Txl;
			tong += z.a[i].Txl;
		}
		else
		{
			gantt[i].Txh = z.a[i].Txh;
			gantt[i].Txl = z.a[i].Txl;
			tong += z.a[i].Txl + z.a[i].Txh;
		}
	}
	//cout << z;
	//cout<<"\n"<<tong;
	/*float WaitTime = 0;
	for (int i = 0; i < z.n; i++)
	{
		WaitTime += gantt[i].Txh - z.a[i].Txh;
	}*/
	cout << "\n"
		<< setw(10) << "Ten"
		<< setw(10) << "Txh" << setw(10) << "Txl";
	for (int i = 0; i < z.n; i++)
	{
		cout << gantt[i];
	}
	return waitTime(gantt, z.n, z.n, z) / z.n;
}
int ss(int x, int y)
{
	int re;
	if (x != y) re = 1;
	else re = 0;
	return re;
}
void sjf(List z)
{
	float tong = z.a[0].Txl;
	process* gantt = new process[z.n];
	for (int i = 1; i < z.n; i++)
	{
		process x[100];
		for (int j = 1; j < z.n; j++)
		{
			int dem = 0;
			x[dem] = z.a[i];
			if (tong >= z.a[j].Txh)
			{
				for(int k=0;k<i;k++)
					if (gantt[k].Ten != z.a[j].Ten)
					{
						
					}
			}
		}
	}
}

int main()
{
	List l;
	cin >> l;
	xep(l);
	cout << l;
	//cout << "\nTtb = " << fcfs(l);
	sjf(l);
	return 0;
}