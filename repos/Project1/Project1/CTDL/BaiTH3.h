#include<iostream>
#include<string.h>
using namespace std;
/*Bài 1: Tìm kiếm tuần tự trên dãy số
Bài toán:
Cho dãy số nguyên x = {34, 14, 24, 54, 84, 64, 94, 74, 04}
Yêu cầu:
- Mô tả quá trình tìm kiếm số nguyên k1 = 94, số k2 = 55 trên dãy số nguyên x
bằng phương pháp tìm kiếm tuần tự.
- Thiết kế giải thuật tìm tìm kiếm.
- Cài đặt chương trình ứng dụng.
*/
int Tim(int *a, int n, int key)
{
    int i=0;
    a[n] = 404;
    while (a[i] == 404)
    {
        if(a[i]==key) break;
        i++;
    }
    if(i<n && a[i]==key) return i;
    else return -1;
}
/*Bài 2: Tìm kiếm nhị phân
Bài toán:
Cho dãy số nguyên x = {04, 14, 24, 34, 54, 64, 74, 84, 94}
Yêu cầu:
- Mô tả quá trình tìm kiếm số nguyên k1 = 34, k2 = 60 trên dãy số nguyên x
bằng phương pháp tìm kiếm nhị phân.
- Thiết kế giải thuật tìm tìm kiếm.
- Cài đặt chương trình ứng dụng.
*/
void Xep0(int* l)
{
    for (int i = 0; i < l.count-1; i++)   
    {
        int m=i;
        for(int j=i+1;j<l.count;j++)
            if(l[j]<l[m])
                m=j;
        swap(l[m],l[i]);
    }
}
int timNhi(int *a, int l, int r, int key)
{
    if(l>r) return -1;
    else
    {
        int m=(l+r)/2;
            return m;
        else
        {
            if(a[m]<key)
                return timNhi(a,l,m-1,key);
            else
                return timNhi(a,m+1,r,key);
        }
    }
}
/*Bài 3: Ứng dụng tìm kiếm danh sách
Yêu cầu:
- Tạo một danh sách học sinh, mỗi học sinh gồm các thông tin: họ và tên, giới
tính, năm sinh, điểm tổng kết. Danh sách được tạo sao cho điểm tổng kết của
hoc sinh trong danh sách theo thứ tự giảm dần.
- Thiết kế giải thuật tìm kiếm một học sinh theo tên và điểm tổng kết bằng
phương pháp tìm kiếm tuần tự.
- Thiết kế giải thuật tìm kiếm học sinh theo điểm tổng kết bằng phương pháp
tìm kiếm nhị phân.
- Ứng dụng các giải thuật tìm kiếm đã thiết kế.*/
#define ma 10
#define ten 30
struct Data
{
    char HoTen[ten],gt[ma];
    int nam;
    float DiemTK;
};
struct List
{
    int count;
    Data *a;
};
void Xep(List& l)
{
    for (int i = 0; i < l.count-1; i++)   
    {
        int m=i;
        for(int j=i+1;j<l.count;j++)
            if(l.a[j].DiemTK<l.a[m].DiemTK)
                m=j;
        swap(a[m],a[i]);
    }
}
int timTT(List l, char name[], float diem)
{
    int i=0;
    while (l.a[i].DiemTK<diem&&i<l.count)
    {
        if(l.a[i].DiemTK==diem&&strcmp(name,l.a[i].HoTen)==0) return 1;
    }
    return -1;
}
int BinSear(List& l, int le, int ri, float diem)
{
    int m=(le+ri)/2;
    if(l.a[m].DiemTK==diem)
        return m;
    else
    {
        if(l.a[m].DiemTK<diem)
            return BinSear(l,m+1,ri,diem);
        else
            return BinSear(l,le,m-1,diem);
    }
}