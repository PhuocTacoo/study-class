#include<bits/stdc++.h>
using namespace std;

class Ngay
{
	private:
		int ngay,thang,nam;
	public:
		int get_day();
		int get_month();
		int get_year();
		void nhap_day();
		void nhap_month();
		void nhap_year();
		bool namnhuan(int n);
		int khoangcach();
};
bool Ngay::namnhuan(int n)
{
	if((n%400==0)||(n%4==0&&n%100!=0)) return 1;
	else
	return 0;
}

int Ngay::khoangcach()
{
	int kc=0;
	if(nam!=1)
		for(int i=1;i<nam;i++)
		{
			if(Ngay::namnhuan(i)==1)
			kc=kc+366;
			else
			kc=kc+365;
		}
	for(int i=1;i<thang;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			kc=kc+31;
		else if(i==4||i==6||i==9||i==11)
			kc=kc+30;
		else if(i==2)
		{
			if(Ngay::namnhuan(nam)==1) 
				kc=kc+29;
			else
				kc=kc+28;
		}
	}
	kc = kc + ngay - 1;
	return kc;
}
void Ngay::nhap_day()
{
	cin>>ngay;
}
void Ngay::nhap_month()
{
	cin>>thang;
}
void Ngay::nhap_year()
{
	cin>>nam;
}
int Ngay::get_day(){
	return ngay;
}
int Ngay::get_month(){
	return thang;
}
int Ngay::get_year(){
	return nam;
}
class Sachi4
{
	private:
		int masach;
		string tensach;
		string tacgia;
		Ngay xuatban;
		int soluong;
	public:
		void nhap1();
		int travekhoangcach();
		void in();
		void inle();
		int travesoluong();
		int travenam();
};
int	Sachi4::travenam()
{
	return xuatban.get_year();
}
int Sachi4::travesoluong()
{
	return soluong;
} 
void Sachi4::inle()
{
	cout<<left<<setw(15)<<"Ma sach"<<left<<setw(20)<<"ten sach"<<left<<setw(20)<<"tac gia"<<left<<setw(15)<<"so luong"<<"ngay xuat ban"<<endl;
}
void Sachi4::in()
{
	cout<<left<<setw(15)<<masach<<left<<setw(20)<<tensach<<left<<setw(20)<<tacgia<<left<<setw(15)<<soluong<<xuatban.get_day()<<"/"<<xuatban.get_month()<<"/"<<xuatban.get_year()<<endl;
}
int Sachi4::travekhoangcach()
{
	return xuatban.khoangcach();
}
void Sachi4::nhap1()
{
	cout<<"Ma sach: ";
	cin>>masach	;
	cout<<"Ten sach: ";
	fflush(stdin);
	getline(cin,tensach);
	fflush(stdin);
	cout<<"Tac gia: ";
	fflush(stdin);
	getline(cin,tacgia);
	fflush(stdin);
	cout<<"So luong: ";
	cin>>soluong;
	cout<<"Ngay xuat ban: ";
	xuatban.nhap_day();
	cout<<"Thang xuat ban: ";
	xuatban.nhap_month();
	cout<<"Nam xuat ban: ";
	xuatban.nhap_year();
}
class Sach
{
	private:
		Sachi4 a[100];
	public:
		void nhapn();
		void sapxep(int n);
		void soluonglonnhat(int n);
		void sach2020(int n);
};
void Sach::nhapn()
{
	cout<<"Nhap so luong sach: ";
			int n;
			cin>>n;
			while(n>100||n<0)
			{
				if(n>100)
				{
					cout<<"So luong sach khong duoc qua 100, vui long nhap lai: ";
					cin>>n;
				}
				if(n<0)
				{
					cout<<"Nhap sai, vui long nhap lai: ";
					cin>>n;
				}
			}
	for(int i = 0 ; i < n ; i++)
	{
		cout<<"Thong tin cua sach thu "<<i+1<<" :"<<endl;
		a[i].nhap1();
	}
	sapxep(n);
	soluonglonnhat(n);
	sach2020(n);
}
void Sach::sapxep(int n)
{
	for(int i = 0;i<n-1;i++)
		for(int j = i+1;j<n;j++)
			if(a[i].travekhoangcach()>a[j].travekhoangcach())
			{
				Sachi4 x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"Sap xep sach theo thu tu tang dan ngay cap phep xuat ban: "<<endl;
	a[0].inle();
	for(int i=0;i<n;i++)
		a[i].in();
}
void Sach::soluonglonnhat(int n)
{
	for(int i = 0;i<n-1;i++)
		for(int j = i+1;j<n;j++)
			if(a[i].travesoluong()<a[j].travesoluong())
			{
				Sachi4 x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"Cac cuon sach co so luong lon nhat: "<<endl;
	a[0].inle();
	int MAX = a[0].travesoluong();
	for(int i=0;i<n;i++)
		if(a[i].travesoluong()==MAX)
		a[i].in();
}
void Sach::sach2020(int n)
{
	cout<<"--------------------------------------------------------------------"<<endl;
	int dem=0;
	for(int i=0;i<n;i++)
		if(a[i].travenam()==2020)
			dem++;
	if(dem==0)
	cout<<"\nKhong co cuon sach nao co giay phep xuat ban nam 2020\n";
	else
	{
		cout<<"Cac cuon sach co giay phep xuat ban nam 2020: "<<endl;
		a[0].inle();
		for(int i=0;i<n;i++)
			if(a[i].travenam()==2020)
			a[i].in();
	}
}
int main()
{
	Sach T;
	T.nhapn();
}
