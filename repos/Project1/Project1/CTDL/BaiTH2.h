#include<iostream>
using namespace std;
/*Cho dãy a có n số nguyên và số nguyên s. Cần lấy ít nhất bao nhiêu số trong dãy a
để được tổng p lớn hơn s.
Yêu cầu:
- Thiết kế giải thuật tìm p theo chiến lược tham lam.
- Cài đặt chương trình ứng dụng.
*/
int itNhat(int *a, int n, int target)
{
    int sum=0,dem=0;
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[m]<a[j])
            {
                m=j;
            }
            
        }
        swap(a[m],a[i]);
        sum+=a[i];
        dem++;
    }
    return dem;
}
/*Bài 2: Xếp ba lô
Một chiếc ba lô có thể chứa được các đồ vật với tổng khối lượng tối đa là w. Có n
đồ vật ký hiệu v1, ..., vn, mỗi đồ vật vi (i = 1, ..., n) có khối lượng là mi và giá trị là
ci. Hãy xếp các đồ vật vào ba lô sao cho giá trị đạt được là lớn nhất.
Yêu cầu:
- Mô tả quá trình xếp các đồ vật vào ba lô theo chiến lược tham lam.
- Thiết kế giải thuật giải quyết bài toán theo chiến lược tham lam.
- Cài đặt chương trình ứng dụng.*/
struct DoVat
{
    char id[10];
    float kl,gt;
};
struct Balo
{
    int count;
    int gt;
    DoVat value[100];
};
int giaTri(Balo a)
{
    int sum=0;
    for(int i=0;i<a.count;i++)
    {
        sum+=a.value[i].gt;
    }
}

Balo Xep(DoVat*a, int n, int klbl)
{
    //Balo *target;
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[m].kl>a[j].kl)
            {
                m=j;
            }           
        }
        swap(a[m],a[i]);
    }
    Balo bl[n+1][klbl+1];
    for (int i = 0; i <= n; i++)
    {
        for(int j=0;j<=klbl;j++)
        {
            if(i==0||j==0) bl[i][j].gt=0;
            else if(j<a[i].kl)
                bl[i][j] =bl[i-1][j];
            else
            {
                bl[i][j].gt = max(bl[i-1][j].gt,a[i].gt+bl[i-1][j-a[i].kl].gt);
                if(bl[i-1][j].gt<a[i].gt+bl[i-1][j-a[i].kl].gt)
                {
                    bl[i][j].value[bl[i][j].count] = a[i];
                    bl[i][j].count++;
                    bl[i][j].gt += a[i].gt;
                }
                else bl[i][j] =bl[i-1][j];
            }
        }
        
    }
    return bl[n][klbl];
    
}
/*Cho một bàn cờ n x n ô, và vị trí xuất phát của một quân mã trên bàn cờ. Tìm một
phương án sao cho sau n2
- 1 bước đi theo luật cờ vua quân mã thăm kín bàn cờ, mỗi
ô thăm đúng 1 lần.
Yêu cầu:
- Mô tả một phương án.
- Thiết kế giải thuật theo chiến lược quay lui.
- Cài đặt chương trình ứng dụng.
*/
int a[100][100];
struct nuocDi
{
    int x,y;
}nd[10];
nd[0].x=-2;
nd[1].x=-2;
nd[2].x=-1;
nd[3].x=-1;
nd[4].x=1;
nd[5].x=1;
nd[6].x=2;
nd[7].x=2;

nd[0].y=-1;
nd[1].y=1;
nd[2].y=-2;
nd[3].y=2;
nd[4].y=-2;
nd[5].y=2;
nd[6].y=-1;
nd[7].y=1;

void xu(int *a[][100], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"\t"a[i][j];
        }
        cout<<"\n";
    }
}
int dem=0;
int dc(int x, int y, int n)
{
    dem++;
    a[x][y] = dem;
    for(int i=0;i<n;i++)
    {
        if(dem == n*n)
        {
            cout<<"\nNuoc di:\n";
            xu(a,n);
        }
        else
        {
            int u = x+nd[i].x;
            int v=y+nd[i].y;
            if(u>=0&&u<n&&v>=0&&v<n)
                dc(u,v,n);
        }
    }
    dem--;
    a[x][y] = 0;
}