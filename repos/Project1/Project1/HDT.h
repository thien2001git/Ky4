#pragma once
#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
#define ten 30
#define ma 10
#define dc 50
#define sdt 15
class PhanSo
{

public:
	PhanSo operator+(PhanSo q);
	PhanSo operator*(PhanSo q);
	PhanSo operator/(PhanSo q);
	PhanSo operator-(PhanSo q);
	PhanSo operator-();
	friend istream& operator>>(istream& x, PhanSo& p);
	friend ostream& operator<<(ostream& x, PhanSo p);
private:
	float x, y;
};

PhanSo PhanSo::operator+(PhanSo q)
{
	PhanSo p;
	if (y = q.y)
	{
		p.x = x + q.x;
		p.y = y;
	}
	else
	{
		p.y = y * q.y;
		p.x = y * q.x + x * q.y;
	}
	return p;
}
PhanSo PhanSo::operator-(PhanSo q)
{
	PhanSo p;
	if (y = q.y)
	{
		p.x = x - q.x;
		p.y = y;
	}
	else
	{
		p.y = y * q.y;
		p.x = -y * q.x + x * q.y;
	}
	return p;
}
PhanSo PhanSo::operator-()
{
	x = -x;
	return *this;
}
inline PhanSo PhanSo::operator*(PhanSo q)
{
	PhanSo p;
	p.x = x * q.x;
	p.y = y * q.y;
	return p;
}
inline PhanSo PhanSo::operator/(PhanSo q)
{
	PhanSo p;
	p.x = x * q.y;
	p.y = y * q.x;
	return p;
}
istream& operator>>(istream& x, PhanSo& p)
{
	cout << "\nNhap tu so: ";
	x >> p.x;
	do
	{
		cout << "Nhap mau so: ";
		x >> p.y;
	} while (p.y < 0);
	return x;
}
ostream& operator<<(ostream& x, PhanSo p)
{
	x << "\n" << p.x << "/" << p.y;
	return x;
}
///////////////////////////
class Complex
{
public:
	Complex();
	~Complex();

private:

};

Complex::Complex()
{
}

Complex::~Complex()
{
}

////////////////////
class NCC
{
public:
	void nhap();
	void xuat();
private:
	char MaNCC[ma], TenNCC[ten], DCNCC[dc], SDT[sdt];
};
void NCC::nhap()
{
	cout << "Nhap MaNCC: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin.getline(MaNCC, ma);
	cout << "Nhap ten ncc: ";
	cin.getline(TenNCC, ten);
	cout << "Nhap dcncc: ";
	cin.getline(DCNCC, dc);
	cout << "Nhap sdt: ";
	cin.getline(SDT, sdt);
}

void NCC::xuat()
{
	cout << "\nMa ncc:\t\t" << MaNCC;
	cout << "\nTen NCC:\t\t" << TenNCC;
	cout << "\nDia chi:\t\t" << DCNCC;
	cout << "\nSo dt:\t\t" << SDT;
}
class Phieu;
class SP
{
public:
	void nhap();
	void xuat();
	friend int pd(int low, int high, Phieu& a);
	friend int SoSP(Phieu a);
private:
	char MaSP[ma], TenSP[ten];
	int dg;
	float sl;
};
void SP::nhap()
{
	cout << "Nhap MaSP: ";
	fflush(stdin);
	cin.ignore();
	cin.getline(MaSP, ma);
	cout << "Nhap ten SP: ";
	cin.getline(TenSP, ten);
	cout << "Nhap don gia: ";
	cin >> dg;
	cout << "Nhap so luong: ";
	cin >> sl;
}

void SP::xuat()
{
	cout << "\n" << setw(ma) << MaSP << setw(ten) << TenSP << setw(ma) << sl << setw(ma) << dg;
}

class Phieu
{
public:
	void nhap();
	void xuat();
	Phieu();
	friend int pd(int low, int high, Phieu& a);
	friend int main();
	friend int SoSP(Phieu a);
private:
	char MaPhieu[ma], NgayLap[ma];
	NCC x;
	int n;
	SP* y;
};

Phieu::Phieu()
{
	nhap();
	x.nhap();
	do
	{
		cout << "\nNhap so sp: ";
		cin >> n;
	} while (n < 0);
	y = new SP[n];
	for (int i = 0; i < n; i++)
	{
		y[i].nhap();
	}
}

void Phieu::nhap()
{
	cout << "Nhap ma phieu: ";
	cin.getline(MaPhieu, ma);
	cout << "Nhap ngay: ";
	//fflush(stdin);
	//cin.ignore();
	cin.getline(NgayLap, ma);
}

void Phieu::xuat()
{
	cout << "\nMa phieu:\t\t" << MaPhieu;
	cout << "\nNgay lap:\t\t" << NgayLap;
	x.xuat();
	cout << "\n" << setw(ma) << "MaSP" << setw(ten) << "TenSP" << setw(ma) << "sl" << setw(ma) << "dg";
	for (int i = 0; i < n; i++)
	{
		y[i].xuat();
	}
}
int pd(int low, int high, Phieu& a)
{
	int i = low, j = high;
	SP pi = a.y[(low + high) / 2];
	while (true)
	{
		while (j >= i && pi.dg > a.y[i].dg) i++;
		while (j >= i && pi.dg < a.y[j].dg) j--;
		if (j <= i) break;
		SP q = a.y[i]; a.y[i] = a.y[j]; a.y[j] = q;
		i++;
		j--;
	}
	return (low + high) / 2;
}
void xep(Phieu& a, int l, int r)
{
	if (l < r)
	{
		int pi = pd(l, r, a);
		xep(a, pi + 1, r);
		xep(a, l, pi - 1);
	}
}
int SoSP(Phieu a)
{
	int dem = 0;
	for (int i = 0; i < a.n; i++)
	{
		if (a.y[i].sl < 80) dem++;
	}
	return dem;
}
///
class Nguoi
{
public:
	void nhap();
	void xuat();

protected:
	char Ten[ten], DC[dc], NS[ma];
};

void Nguoi::nhap()
{
	cout << "Nhap ten: ";
	fflush(stdin);
	cin.ignore();
	cin.getline(Ten, ten);
	cout << "Nhap dc: ";
	//fflush(stdin);
	//cin.ignore();
	cin.getline(DC, dc);
	cout << "Nhap ngay sinh: ";
	//fflush(stdin);
	//cin.ignore();
	cin.getline(NS, ma);
}

void Nguoi::xuat()
{
	cout << "\n" << setw(ten) << Ten << setw(ma) << NS << setw(dc) << DC;
}
class LH;
class SV : public Nguoi
{
public:
	void nhap();
	void xuat();
	friend int SoSV(LH a, int k);
	friend void xep1(LH& a);
private:
	char MaSV[ma], Ng[ten];
	int Khoa;
};

void SV::nhap()
{
	Nguoi::nhap();
	cout << "Nhap ma sv: ";
	cin.getline(MaSV, ma);
	cout << "Nhap nganh: ";
	cin.getline(Ng, ten);
	cout << "Nhap khoa: ";
	cin >> Khoa;
}

void SV::xuat()
{
	Nguoi::xuat();
	cout << setw(ma) << MaSV << setw(ten) << Ng << setw(ma) << Khoa;
}

class LH
{
public:
	void nhap();
	void xuat();
	friend int SoSV(LH a, int k);
	friend void xep1(LH& a);
private:
	char MaLH[ma], TenLH[ten], NgayMo[ma], GV[ten];
	int n;
	SV* x;
};

void LH::nhap()
{
	cout << "Nhap MaLH: ";
	/*fflush(stdin);
	cin.ignore();*/
	cin.getline(MaLH, ma);
	cout << "Nhap ten lop: ";
	cin.getline(TenLH, ten);
	cout << "Nhap ngay: ";
	//fflush(stdin);
	//cin.ignore();
	cin.getline(NgayMo, ma);
	cout << "Nhap ten gv: ";
	cin.getline(GV, ten);
	do
	{
		cout << "Nhap so sv: ";
		cin >> n;
	} while (n < 0);
	x = new SV[n];
	for (int i = 0; i < n; i++)
	{
		x[i].nhap();
	}
}
void LH::xuat()
{
	cout << "\nMa lh: " << MaLH;
	cout << "\nTen lh: " << TenLH;
	cout << "\nNgay mo: " << NgayMo;
	cout << "\nGiao vien: " << GV;
	cout << "\n" << setw(ten) << "Ten" << setw(ma) << "NS" << setw(dc) << "DC";
	cout << setw(ma) << "MaSV" << setw(ten) << "Ng" << setw(ma) << "Khoa";
	for (int i = 0; i < n; i++)
	{
		x[i].xuat();
	}
}

int SoSV(LH a, int k)
{
	int dem = 0;
	for (int i = 0; i < a.n; i++)
		if (a.x[i].Khoa == 11)
			dem++;
	return dem;
}

void xep1(LH& a)
{
	for (int i = 0; i < a.n -1; i++)
	{
		int m = i;
		for (int j = i + 1; j < a.n; j++)
			if (a.x[m].Khoa < a.x[j].Khoa)
				m = j;
		swap(a.x[m], a.x[i]);
	}
}