//#include<iostream>
//#include<iomanip>
//using namespace std;
//struct pr
//{
//	int Txh, Tth, Ten;
//};
//istream& operator>>(istream& x, pr& y)
//{
//	cout << "Nhap Txh: ";
//	x >> y.Txh;
//	cout << "Nhap Tth: ";
//	x >> y.Tth;
//	return x;
//}
//ostream& operator<<(ostream& x, pr& y)
//{
//	cout << "\n" << setw(10) << y.Ten << setw(10) << y.Txh << setw(10) << y.Tth;
//	return x;
//}
//
//void sjf(pr* z, int n)
//{
//	pr* gantt = new pr[n];
//	//cout << gantt.n;
//	gantt[0] = z[0];
//	float tong = z[0].Tth;
//	int tm = 0;
//	int dem = 1, dem1 = 0;
//	pr d[100];
//	for (int i = 1; i < n; i++)
//	{
//		gantt[i].Txh = tong;
//		pr d[100];
//		int dem = 0;
//		pr min;
//		for (int j = 1; j < n; j++)
//		{
//			if (tong >= z[j].Txh)
//			{
//				for (int k = 1; k < j; k++)
//				{
//					if (gantt[k].Ten != z[j].Ten)
//					{
//						if (dem == 0)
//						{
//							min = z[j];
//							dem++;
//						}
//						else
//						{
//							if (min.Tth > z[j].Tth) min = z[j];
//							dem++;
//						}
//
//					}
//				}
//			}
//		}
//
//		gantt[i].Ten = min.Ten;
//		gantt[i].Tth = min.Tth;
//		tong += min.Tth;
//	}
//	cout << "\n"
//		<< setw(10) << "Ten"
//		<< setw(10) << "Txh" << setw(10) << "Tth";
//	for (int i = 0; i < n; i++)
//	{
//		cout << gantt[i];
//	}
//}
//
//int main()
//{
//	int n;
//	cout << "n = ";
//	cin >> n;
//	pr* a = new pr[n];
//	for (int i = 0; i < n; i++)
//	{
//		a[i].Ten = i;
//		cout << i + 1 << " --- ";
//		cin >> a[i];
//	}
//	cout << "\n" << setw(10) << "Ten" << setw(10) << "Txh" << setw(10) << "Tth";
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i];
//	}
//	sjf(a, n);
//	return 0;
//}

// C++ program to implement Shortest Job first with Arrival Time
//#include<iostream>
//using namespace std;
//int mat[10][6];
//
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void arrangeArrival(int num, int mat[][6])
//{
//	for (int i = 0; i < num; i++)
//	{
//		for (int j = 0; j < num - i - 1; j++)
//		{
//			if (mat[j][1] > mat[j + 1][1])
//			{
//				for (int k = 0; k < 5; k++)
//				{
//					swap(mat[j][k], mat[j + 1][k]);
//				}
//			}
//		}
//	}
//}
//
//void completionTime(int num, int mat[][6])
//{
//	int temp, val;
//	mat[0][3] = mat[0][1] + mat[0][2];
//	mat[0][5] = mat[0][3] - mat[0][1];
//	mat[0][4] = mat[0][5] - mat[0][2];
//
//	for (int i = 1; i < num; i++)
//	{
//		temp = mat[i - 1][3];
//		int low = mat[i][2];
//		for (int j = i; j < num; j++)
//		{
//			if (temp >= mat[j][1] && low >= mat[j][2])
//			{
//				low = mat[j][2];
//				val = j;
//			}
//		}
//		mat[val][3] = temp + mat[val][2];
//		mat[val][5] = mat[val][3] - mat[val][1];
//		mat[val][4] = mat[val][5] - mat[val][2];
//		for (int k = 0; k < 6; k++)
//		{
//			swap(mat[val][k], mat[i][k]);
//		}
//	}
//}
//
//int main()
//{
//	int num, temp;
//
//	cout << "Enter number of Process: ";
//	cin >> num;
//
//	cout << "...Enter the process ID...\n";
//	for (int i = 0; i < num; i++)
//	{
//		cout << "...Process " << i + 1 << "...\n";
//		cout << "Enter Process Id: ";
//		cin >> mat[i][0];
//		cout << "Enter Arrival Time: ";
//		cin >> mat[i][1];
//		cout << "Enter Burst Time: ";
//		cin >> mat[i][2];
//	}
//
//	cout << "Before Arrange...\n";
//	cout << "Process ID\tArrival Time\tBurst Time\n";
//	for (int i = 0; i < num; i++)
//	{
//		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t" << mat[i][2] << "\n";
//	}
//
//	arrangeArrival(num, mat);
//	completionTime(num, mat);
//	cout << "Final Result...\n";
//	cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
//	for (int i = 0; i < num; i++)
//	{
//		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t" << mat[i][2] << "\t\t" << mat[i][4] << "\t\t" << mat[i][5] << "\n";
//	}
//}
