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
		int khoangcach();
		bool namnhuan(int n);
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

void Ngay::nhap_day(){
	cin>>ngay;
}

void Ngay::nhap_month(){
	cin>>thang;
}

void Ngay::nhap_year(){
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

class Nhanvien
{
	private:
		int manv;
		char hoten[99];
		int hesoluong;
		int hesophucap;
		Ngay ngayvaocoquan;
	public:
		void nhap1();
		void ngayvao();
		void in();
		int get_kc();
};
int Nhanvien::get_kc()
{
	return ngayvaocoquan.khoangcach();
}

void Nhanvien::in()
{
	cout<<manv<<"\t"<<hoten<<"\t"<<hesoluong<<"\t"<<hesophucap<<"\t";
	ngayvaocoquan.get_day();
	cout<<"/";
	ngayvaocoquan.get_month();
	cout<<"/";
	ngayvaocoquan.get_year();
	cout<<endl;
}

void Nhanvien::nhap1()
{
	cout<<"Ma nhan vien: ";
	cin>>manv;
	cout<<"Ho ten: ";
	fflush(stdin);
	gets(hoten);
	fflush(stdin);
	cout<<"He so luong: ";
	cin>>hesoluong;
	cout<<"He so phu cap: ";
	cin>>hesophucap;
	cout<<"Ngay vao co quan: ";
	ngayvaocoquan.nhap_day();
	cout<<"Thang vao co quan: ";
	ngayvaocoquan.nhap_month();
	cout<<"Nam vao co quan: ";
	ngayvaocoquan.nhap_year();
}

class Coquan
{
	private:
		Nhanvien a[50];
	public:
		void nhap(int n);
		void sapxep(int n);
		void hienthi(int n);
};

void Coquan::nhap(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap nhan vien thu "<<i+1<<" :"<<endl;
		a[i].nhap1();
	}
}

void Coquan::sapxep(int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].get_kc()>a[j].get_kc())
			{
				Nhanvien x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	    }
	}
	for(int i=0;i<n;i++)
	a[i].in();
}

int main()
{
	int n;
	cin>>n;
	Coquan T;
	T.nhap(n);
	T.sapxep(n);
	
	
}
