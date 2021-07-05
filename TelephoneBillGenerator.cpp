//Coded in Turbo C++

#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>


class Cust
{
	private:
		char cn[20];
		char cc[8];
		long int sc;
		long int ba;
	
	public:
		void get(char *p)
		{
			cout<<"Enter Customer Name:";cin>>cn;
			cout<<"Enter City Code:";cin>>cc;
			strcpy(cc,p);
			cout<<"Enter No. of Seconds:";cin>>sc;
		}
	
		void show()
		{
			cout<<cn<<"\t\t"<<cc<<"\t\t"<<sc<<"\t\t"<<ba<<endl;
		}
		
		void calcbill(int km)
		{
			if(km>10&&km<100)
			ba=20*(sc/60);
			if(km>100&&km<200)
			ba=30*(sc/60);
			if(km>200&&km<500)
			ba=50*(sc/60);
			if(km>500&&km<800)
			ba=65*(sc/60);
			if(km>800&&km<1200)
			ba=85*(sc/60);
			if(km>1200)
			ba=20*(sc/60);
		}
};


class City
{
	private:
		char cc[8];
		char cn[20];
		int km;
	
	public:
		void get()
		{
			cout<<"Enter City Code :";cin>>cc;
			cout<<"Enter City Name:";cin>>cn;
			cout<<"Enter Kilometres away:";cin>>km;
		}
		
		void show()
		{
			cout<<cc<<"\t\t"<<cn<<"\t\t"<<km<<endl;
		}
		
		char* citycode()
		{
			return cc;
		}
		
		int kml()
		{
			return km;
		}
};


main()
{
	clrscr();
	int ch,cd,k;
	char ctcd[8];
	Cust cm;
	City ct;
	fstream fcm,fct;
	do
	{
		clrscr();
		cout<<
			"1.Enter New City\n"
			"2.Enter and append customer details\n"
			"3.Display all Cities\n"
			"4.Display Customer information\n"
			"5.Exit\nEnter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				fct.open("City.dat",ios::app|ios::out);
				ct.get();
				fct.write((char*)&ct,sizeof(ct));
				fct.close();
				break;
			case 2:
				fcm.open("Cust.dat",ios::app|ios::out);
				fct.open("City.dat",ios::in);
				int f=0;
				cout<<"Enter City Code :";
				cin>>ctcd;
				fct.read((char*)&ct,sizeof(ct));
				while(!fct.eof())
				{
					if(strcmp(ctcd,ct.citycode())==0)
					{
						f=1;
						break;
					}
					fct.read((char*)&ct,sizeof(ct));
				}
				if(f==0)
					cout<<"City Not Found :Try Again"<<endl;
				else
				{
					cm.get(ctcd);
					cm.calcbill(ct.kml());
					fcm.write((char*)&cm,sizeof(cm));
					cm.show();
				}
				fct.close();
				fcm.close();
				break;
			case 3:
				fct.open("City.dat",ios::in);
				cout<<"City Code"<<"\t"<<"City"<<"\t\t"<<"Kilometres away"<<endl;
				fct.read((char*)&ct,sizeof(ct));
				while(!fct.eof())
				{
					ct.show();
					fct.read((char*)&ct,sizeof(ct));
				}
				fct.close();
				break;
			case 4:
				fcm.open("Cust.dat",ios::in);
				cout<<"Name"<<"\t\t"<<"City Code"<<"\t"<<"Seconds"<<"\t\t"<<"Bill Amount"<<endl;
				fcm.read((char*)&cm,sizeof(cm));
				while(!fcm.eof())
				{
					cm.show();
					fcm.read((char*)&cm,sizeof(cm));
				}
				fcm.close();
				break;
			case 5:
			cout<<"Thank you";
		}
	cout<<"\n\nPress any key to continue.......\n\n";
	getch();
	}while(ch!=5);
	getch();
}
