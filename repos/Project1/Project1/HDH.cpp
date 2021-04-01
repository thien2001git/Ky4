#include <iostream>
#include <iomanip>
using namespace std;
class List;
class process
{
private:
    float Txh, Txl;
    int Ten;

public:
    friend istream &operator>>(istream &x, process &y);
    friend ostream &operator<<(ostream &x, process y);
    friend istream &operator>>(istream &x, List &y);
    friend void xep(List &z);
    friend List fcfs(List z);
    friend int main();
};

istream &operator>>(istream &x, process &y)
{
    cout << "Nhap thoi gian xuat hien: ";
    x >> y.Txh;
    cout << "Nhap thoi gian xu li:     ";
    x >> y.Txl;
    return x;
}

ostream &operator<<(ostream &x, process y)
{
    x << "\n"
      << setw(10) << y.Ten
      << setw(10) << y.Txh << setw(10) << y.Txl;
    return x;
}

class List
{
private:
    process *a;
    int n;

public:
    friend istream &operator>>(istream &x, List &y);
    friend ostream &operator<<(ostream &x, List y);
    friend void xep(List &z);
    friend List fcfs(List z);
    friend int main();
};

istream &operator>>(istream &x, List &y)
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

ostream &operator<<(ostream &x, List y)
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

void xep(List &z)
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

List fcfs(List z)
{
    List gantt;
    gantt = z;
    //gantt.n = z.n;
    //cout << gantt.n;
    // gantt.a[0] = z.a[0];
    float tong = z.a[0].Txl;
    // float tong = 0;
    //cout<<gantt;
    for (int i = 1; i < z.n; i++)
    {
        gantt.a[i].Ten = z.a[i].Ten;
        if (z.a[i].Txh <= tong)
        {
            gantt.a[i].Txh = tong;
            gantt.a[i].Txl = z.a[i].Txl;
            tong += z.a[i].Txl;
        }
        else
        {
            gantt.a[i].Txh = z.a[i].Txh;
            gantt.a[i].Txl = z.a[i].Txh;
            tong += z.a[i].Txl + z.a[i].Txh;
        }
    }
    cout << gantt;
    //cout<<"\n"<<tong;
    // float WaitTime = 0;
    // for (int i = 0; i < z.n; i++)
    // {
    //     WaitTime += gantt.a[i].Txh - z.a[i].Txh;
    //     cout << "\n"
    //      << gantt.a[i].Txh;
    //      cout << "\n"
    //      << z.a[i].Txh;
    // }
    return gantt;
}

int main()
{
    List l;
    cin >> l;
    xep(l);
    List l1 = l;
    cout << l;
    List gantt = fcfs(l);
    float WaitTime = 0;
    for (int i = 0; i < l.n; i++)
    {
        WaitTime += gantt.a[i].Txh - l1.a[i].Txh;
    }
    cout << "\n"
         << WaitTime / l1.n;
    return 0;
}