#include<bits/stdc++.h>
using namespace std;

class Date
{
	private:
		int ngay,thang,nam;
	public:
		void nhap();
		bool dieuchinh();
		bool hople();
		void tang();
		void xuat();
		bool namnhuan(int n);
		void tang_1ngay();
		void tang_kngay(int k);
		void khoangcach();

};


void Date::khoangcach()
{
	Date A,B;
	cout<<"Khoang cach giua 2 doi tuong:"<<endl;
	cout<<"Doi tuong 1: "<<endl;
	A.nhap();
	while(A.dieuchinh()==0)
	{
	cout<<"Nhap khong chinh xac,nhap lai: "<<endl;
	A.nhap();
    }
    cout<<A.ngay<<" / "<<A.thang<<" / "<<A.nam<<endl;
    cout<<"Doi tuong 2: "<<endl;
	B.nhap();
	while(B.dieuchinh()==0)
	{
	cout<<"Nhap khong chinh xac,nhap lai: "<<endl;
	B.nhap();
    }
    cout<<B.ngay<<" / "<<B.thang<<" / "<<B.nam<<endl;
	
	    
	
}
void Date::tang_kngay(int k)
{
	if(dieuchinh()==1)
	{

	for(int i=0;i<k;i++)
	{
	if(ngay==31&&(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10))
	{
		ngay=1;
		thang++;
    }
	else if(ngay==31&&thang==12)
	{
		ngay=1;
		thang=1;
		nam++;
    }
	else if((namnhuan(nam)==1&&thang==2&&ngay==31)||(namnhuan(nam)==0&&thang==2&&ngay==30))
	{
		ngay=1;
		thang++;
	}
	else if(ngay==30&&(thang==4||thang==6||thang==9|thang==11))
	{
		ngay=1;
		thang++;
	}
	else 
	ngay++;
    }
    cout<<ngay<<" / "<<thang<<" / "<<nam;
    }
    else
	{
		cout<<"Du lieu ban nhap khong hop le, hay nhap lai\n";
		nhap();
		xuat();
	}
}
void Date::tang_1ngay()
{
	if(ngay==31&&(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10))
	{
		ngay=1;
		thang++;
    }
	else if(ngay==31&&thang==12)
	{
		ngay=1;
		thang=1;
		nam++;
    }
	else if((namnhuan(nam)==1&&thang==2&&ngay==31)||(namnhuan(nam)==0&&thang==2&&ngay==30))
	{
		ngay=1;
		thang++;
	}
	else if(ngay==30&&(thang==4||thang==6||thang==9|thang==11))
	{
		ngay=1;
		thang++;
	}
	else ngay++;
	cout<<ngay<<" / "<<thang<<" / "<<nam;
}
void Date::nhap()
{
	cout<<"Nhap ngay: ";
	cin>>ngay;
	cout<<"Nhap thang: ";
	cin>>thang;
	cout<<"Nhap nam: ";
	cin>>nam;
	if(hople()==0)
	{
		cout<<"Du lieu ban vua nhap khong hop le, bui long nhap lai"<<endl;
		nhap();
	}
}
bool Date::namnhuan(int n)
{
	if(n%400==0) return 1;
	else
	return 0;
}	
bool Date::dieuchinh()
{
	if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10||thang==12) if(ngay<=31) return 1;
																			   else return 0;
	else if(thang==4||thang==6||thang==9|thang==11) if(ngay<=30) return 1;
													else return 0;
	else if(thang==2)
	{
		if(namnhuan(nam)==1) if(ngay<=29) return 1;
		else return 0;
		if(namnhuan(nam)==0) if(ngay<=28) return 1;
		else return 0;
	}
	else return 0;	
}
bool Date::hople()
{
	if(ngay>=0&&thang>=0&&nam>=0)
	return 1;
	else return 0;	
}

void Date::xuat()
{
	if(dieuchinh()==1)
	cout<<ngay<<" / "<<thang<<" / "<<nam;
	else
	{
		cout<<"Du lieu ban nhap khong hop le, hay nhap lai\n";
		nhap();
		xuat();
	}
}
int main()
{
	Date T,D,F;
	T.nhap();
	T.xuat();
	cout<<endl;
    D.nhap();
	D.xuat();		
	cout<<"\nSau khi tang 1 ngay la: ";
	D.tang_1ngay();
	cout<<endl;
	F.nhap();
	long long k;
	cout<<"Nhap k: ";
	cin>>k;
	F.tang_kngay(k);
	return 0;
}
