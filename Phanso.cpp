#include<bits/stdc++.h>
using namespace std;

class Phanso
{
	private:
		int tu1;
		int mau1;
		int tu2;
		int mau2;
	public:
		void cong();
		void tru();
		void nhan();
		void chia();
		void nhap();
		void xuat();
		void rutgon(int a,int b);
		void show();
};

void Phanso::nhap()
{
	cout<< "Tu1: ";
	cin>>tu1;
	cout<< "Mau1: ";
	cin>>mau1;
	while(mau1==0)
	{
		cout<<"Mau khong the bang 0,moi nhap lai: \nMau1: ";
		cin>>mau1;
	}
	cout<< "Tu2: ";
	cin>>tu2;
	cout<< "Mau2: ";
	cin>>mau2;
	while(mau2==0)
	{
		cout<<"Mau khong the bang 0,moi nhap lai: \nMau2: ";
		cin>>mau2;
	}
}
void Phanso::show()
{
	cout<<"Phan so thu 1: "<<tu1<<"/"<<mau1<<endl;
	cout<<"Phan so thu 2: "<<tu2<<"/"<<mau2<<endl;
}

void Phanso::cong()
{
	cout<<"Tong 2 phan so la: ";
	int a,b;
	a=(tu1*mau2)+(tu2*mau1);
	b=(mau1*mau2);
	rutgon(a,b);
}
void Phanso::tru()
{
	cout<<"Hieu 2 phan so la: ";
	int a,b;
	a=(tu1*mau2)-(tu2*mau1);
	b=(mau1*mau2);
	rutgon(a,b);
}
void Phanso::nhan()
{
	cout<<"Tich 2 phan so la: ";
	int a,b;
	a=tu1*tu2;
	b=mau1*mau2;
	rutgon(a,b);
}
void Phanso::chia()
{
	if(tu2==0)
		cout<<"Khong the thuc hien duoc phep chia";
	else
	{
		cout<<"Thuong 2 phan so la: ";
		int a,b;
		a=tu1*mau2;
		b=mau1*tu2;
		rutgon(a,b);
	}
}
void Phanso::rutgon(int a,int b)
{
	long r;
	int x=a,y=b;
    while (x%y != 0)
    {
        r = x%y;
        x = y;
        y = r;
    }
    a=a/y;
    b=b/y;
    if(a==0) cout<<0<<endl;
    else if(a==1&&b==1) cout<<1<<endl;
    else
    cout<<a<<"/"<<b<<endl;
}
void Phanso::xuat()
{
	nhap();
    show();
	cong();
	tru();
	nhan();
	chia();
}
int main()
{
	Phanso t;
	t.xuat();
	return 0;
}
