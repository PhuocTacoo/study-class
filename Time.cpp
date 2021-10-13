#include<bits/stdc++.h>
#include<iostream>
#include <conio.h>
using namespace std;

class Time
{
	private:
		int h,m,s;
	public:
		void nhap();
		void chuanhoa();
		void giatang();
		void dieuchinh();
		void xuat();
};
void Time::nhap()
{
	cout<<"nhap gio: ";
	cin>>h;
	cout<<"nhap phut: ";
	cin>>m;
	cout<<"nhap giay: ";
	cin>>s;
	if(h<0||m<0||s<0)
	{
		cout<<"thoi gian ban vua nhap sai , nhap lai:"<<endl;
		nhap();
	} 
}
void Time::chuanhoa()
{
	if(s>=60)
	{
	  m=m+s/60;
	  s=s%60;
	}
	if(m>=60)
	{
    	h=h+m/60;
    	m=m%60;
	}
}

void Time::xuat()
{
	cout<<h<<":"<<m<<":"<<s;
}
void Time::giatang()
{
	int gio,phut,giay;
	cout<<"nhap gio can tang: "; 
	cin>>gio;
	cout<<"nhap phut can tang: "; 
	cin>>phut;
	cout<<"nhap giay can tang: "; 
	cin>>giay;
	h=h+gio;
	m=m+phut;
	s=s+giay;
	chuanhoa();
}
int main()
{
	Time T,D;
	T.nhap();
	T.chuanhoa();
	cout<<"thoi gian ban nhap la: ";
	T.xuat();
	cout<<endl;
	D.nhap();
	D.giatang();
	cout<<"thoi gian sau khi gia tang va dieu chinh lai la: ";
	D.xuat();
	return 0;
}

