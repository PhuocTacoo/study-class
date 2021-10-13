#include<bits/stdc++.h>
using namespace std;

class Thiboi
{
	private:
		char hoten[50];
		int ms,h_start,m_start,s_start,h_end,m_end,s_end;
	public:
		void nhap1sinhvien();
		void nhapnhieusinhvien(int n);
		void intangdan();
		void incaonhat();
		void sapxep(int n);
		void in();
		int get_ms();
		int get_h();
		int get_m();
		int get_s();
		int get_hh();
		int get_mm();
		int get_ss();
		int thoigianboi();
		void in1();

};
void Thiboi::nhap1sinhvien()
{
	cout<<"Ma so: ";
	cin>>ms;
	cout<<"Ho ten: ";
	fflush(stdin);
	gets(hoten);
	fflush(stdin);
	cout<<"Thoi gian bat dau: "<<endl;
	cout << "h: ";
	cin >> h_start;
	cout << "m: ";
	cin >> m_start;
	cout << "s: ";
	cin >> s_start;
	cout<<"Thoi gian ket thuc: "<<endl;
    cout << "h: ";
	cin >> h_end;
	cout << "m: ";
	cin >> m_end;
	cout << "s: ";
	cin >> s_end;
}

int Thiboi::get_ms()
{
	return ms;
}
int Thiboi::get_h()
{
	return h_start;
}
int Thiboi::get_m()
{
	return m_start;
}
int Thiboi::get_s()
{
	return s_start;
}
int Thiboi::get_hh()
{
	return h_end;
}
int Thiboi::get_mm()
{
	return m_end;
}
int Thiboi::get_ss()
{
	return s_end;
}

void Thiboi::in()
{
	cout<<left<<setw(8)<<ms<<left<<setw(20)<<hoten<<h_start<<left<<setw(0)<<":"<< m_start<<":"<<left<<setw(20)<< s_start<<left<<setw(0)<< h_end<<":"<< m_end<<":"<< s_end<<endl;
}
void Thiboi::in1()
{
	cout<<left<<setw(8)<<ms<<left<<setw(20)<<hoten<<h_start<<left<<setw(0)<<":"<< m_start<<":"<<left<<setw(20)<< s_start<<left<<setw(0)<< h_end<<":"<< m_end<<":"<< s_end<<left<<setw(60);
}
int Thiboi::thoigianboi()
{
	int tong=0;
	tong=(get_h()*3600+ get_m()*60+get_s())-( get_hh()*3600+ get_mm()*60+ get_ss());
	return tong;
}
class Nhap
{
	private:
		Thiboi a[50];
	public:
		void nhap(int n);
		void innhieu(int n);
		void sapxep(int n);
		int thoigianboi();
		void sapxeprank(int n);
		void thebest(int n);
		void rank(int n);
};
void Nhap::sapxeprank(int n)
{
	Thiboi K;
	for(int i=0;i<n;i++)
		a[i].thoigianboi();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			if(a[i].thoigianboi()>=a[j].thoigianboi())
			{
				K = a[i];
				a[i] = a[j];
				a[j] = K;
			}
	}
}
void Nhap::rank(int n)
{
	for(int i=0;i<n;i++)
		a[i].thoigianboi();
	sapxeprank(n);
	cout<<"--------------------------------------"<<endl;
	cout<<"Thu hang cua cac van dong vien:"<<endl;
	cout<<left<<setw(8)<<"Ma so"<<left<<setw(20)<<"ho va ten"<<left<<setw(24)<<"thoi gian bat dau"<<left<<setw(20)<<"thoi gian ket thuc"<<"rank"<<endl;
 	int rankk=1;
 	for(int i=0;i<n;i++)
 	{
 		a[i].in1();
 		cout<<right<<setw(17)<<rankk<<endl;
 		if(a[i].thoigianboi()>a[i+1].thoigianboi()) rankk++;
 	}
}
void Nhap::thebest(int n)
{
	for(int i=0;i<n;i++)
		a[i].thoigianboi();
	cout<<"--------------------------------------"<<endl;
	cout<<"Van dong vien co thu hang cao nhat: "<<endl;
	cout<<left<<setw(8)<<"Ma so"<<left<<setw(20)<<"ho va ten"<<left<<setw(24)<<"thoi gian bat dau"<<"thoi gian ket thuc"<<endl;
	sapxeprank(n);
	for(int i=0;i<n;i++)
	{
    	a[i].in();
    	if(a[i+1].thoigianboi()!=a[i].thoigianboi()) break;
    }
}
void Nhap::nhap(int n)
{
	for(int i=0;i<n;i++)
	{
	cout<<"Van dong vien thu "<<i+1<<" :"<<endl;
		a[i].nhap1sinhvien();
	}
}
void Nhap::sapxep(int n)
{
	Thiboi T;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(a[i].get_ms()<a[j].get_ms())
			{
			T = a[i];
			a[i] = a[j];
			a[j] = T;
		    }
		}
}
void Nhap::innhieu(int n)
{
	sapxep(n);
	cout<<"--------------------------------------";
	cout<<"\n"<<"Sap xep:"<<endl;
	cout<<left<<setw(8)<<"Ma so"<<left<<setw(20)<<"ho va ten"<<left<<setw(24)<<"thoi gian bat dau"<<"thoi gian ket thuc"<<endl;
	for(int i=0;i<n;i++)
		a[i].in();
}

int main()
{
	Nhap F;
			cout<<"Nhap so luong van dong vien: ";
			int n;
			cin>>n;
			while(n>50||n<0)
			{
				if(n>50)
				{
					cout<<"So luong van dong vien khong duoc qua 50, vui long nhap lai: ";
					cin>>n;
				}
				if(n<0)
				{
					cout<<"Nhap sai, vui long nhap lai: ";
					cin>>n;
				}
			}
	F.nhap(n);
	F.innhieu(n);
	F.thebest(n);
	F.rank(n);
	return 0;
}
	
