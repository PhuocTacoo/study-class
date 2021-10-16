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
class Sinhvieni4
{
	private:
		int msv;
		string hoten;
		int tongdiem;
		Ngay nhaphoc;
	public:
		void nhap1();
		int travekhoangcach();
		void in();
		int travetongdiem();
		void inrank();
		void inle();
		void inlerank();
};
void Sinhvieni4::inle()
{
	cout<<left<<setw(15)<<"Ma sinh vien"<<left<<setw(20)<<"ho va ten"<<left<<setw(15)<<"tong diem"<<"ngay nhap hoc"<<endl;
}
void Sinhvieni4::inlerank()
{
	cout<<left<<setw(15)<<"Ma sinh vien"<<left<<setw(20)<<"ho va ten"<<left<<setw(15)<<"tong diem"<<left<<setw(15)<<"ngay nhap hoc"<<"rank"<<endl;
}
void Sinhvieni4::inrank()
{
	cout<<left<<setw(15)<<msv<<left<<setw(20)<<hoten<<left<<setw(15)<<tongdiem<<nhaphoc.get_day()<<"/"<<nhaphoc.get_month()<<"/"<<nhaphoc.get_year();
}

int Sinhvieni4::travetongdiem()
{
	return tongdiem;
}
void Sinhvieni4::in()
{
	cout<<left<<setw(15)<<msv<<left<<setw(20)<<hoten<<left<<setw(15)<<tongdiem<<nhaphoc.get_day()<<"/"<<nhaphoc.get_month()<<"/"<<nhaphoc.get_year()<<endl;
}
int Sinhvieni4::travekhoangcach()
{
	return nhaphoc.khoangcach();
}
void Sinhvieni4::nhap1()
{
	cout<<"Ma sinh vien: ";
	cin>>msv;
	cout<<"Ho ten: ";
	fflush(stdin);
	getline(cin,hoten);
	fflush(stdin);
	cout<<"Tong diem thi: ";
	cin>>tongdiem;
	cout<<"Ngay nhap hoc: ";
	nhaphoc.nhap_day();
	cout<<"Thang nhap hoc: ";
	nhaphoc.nhap_month();
	cout<<"Nam nhap hoc: ";
	nhaphoc.nhap_year();
}
class Sinhvien
{
	private:
		Sinhvieni4 a[50];
	public:
		void nhapn();
		void sapxep(int n);
		void tongdiemcaonhat(int n);
		void nguoicaonhat(int n);
};
void Sinhvien::nguoicaonhat(int n)
{
	for(int i = 0;i<n-1;i++)
		for(int j = i+1;j<n;j++)
			if(a[i].travetongdiem()<a[j].travetongdiem())
			{
				Sinhvieni4 x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	cout<<"---------------------------------------------------"<<endl;
	cout<<"3 sinh vien duoc khen thuong la: "<<endl;
	a[0].inlerank();
	int rank=1;
	for(int i=0;i<n;i++)
	{
		a[i].inrank();
		cout<<right<<setw(11)<<rank<<endl;
		rank++;
    }
}
void Sinhvien::tongdiemcaonhat(int n)
{
	for(int i = 0;i<n-1;i++)
		for(int j = i+1;j<n;j++)
			if(a[i].travetongdiem()<a[j].travetongdiem())
			{
				Sinhvieni4 x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	cout<<"---------------------------------------------------"<<endl;
	cout<<"Cac sinh vien co tong diem cao nhat: "<<endl;
	a[0].inle();
	int MAX = a[0].travetongdiem();
		for(int i=0;i<n;i++)
		if(a[i].travetongdiem()==MAX)
		a[i].in();
}
void Sinhvien::sapxep(int n)
{
	for(int i = 0;i<n-1;i++)
		for(int j = i+1;j<n;j++)
			if(a[i].travekhoangcach()>a[j].travekhoangcach())
			{
				Sinhvieni4 x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	cout<<"---------------------------------------------------"<<endl;
	cout<<"Sap xep sinh vien theo thu tu tang dan ngay nhap hoc: "<<endl;
	a[0].inle();
		for(int i=0;i<n;i++)
		a[i].in();
}
void Sinhvien::nhapn()
{
	cout<<"Nhap so luong sinh vien: ";
			int n;
			cin>>n;
			while(n>50||n<0)
			{
				if(n>50)
				{
					cout<<"So luong sinh vien khong duoc qua 50, vui long nhap lai: ";
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
		cout<<"Thong tin cua sinh vien thu "<<i+1<<" :"<<endl;
		a[i].nhap1();
	}
	sapxep(n);
	tongdiemcaonhat(n);
	nguoicaonhat(n);
}

int main()
{
	Sinhvien T;
	T.nhapn();
	return 0;
}
