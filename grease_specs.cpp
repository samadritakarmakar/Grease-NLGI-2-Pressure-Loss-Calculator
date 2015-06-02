#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

double f_factor_bringham(double v, double d)
{
double u1=0.00046;
double p=895;
double u=p*u1;
//d=d/1000;
double Re=895*v*d/u;
double f;
double a;


//450Pa=yeild stress of grease
//Hedstrom Number

double He=895*(pow(d,2))*450/(pow(u,2));
if(Re<2000)
{
 f=64/Re+(10.67+0.1414*pow((He/Re),1.143))/((1+0.0149*pow((He/Re),1.16))*Re)*(He/Re);
}
else
{
 a=-1.47*(1+0.146*exp(-2.9*pow(10,-5)*He));
 f=pow(10,a)*pow(Re,-.193);
}
f=f/4;
return f;
}


int main()
{
double pi=22/7, vol1=0, int_dia;
cout <<" Welcome to Pressure Check Program. \n Enter 1 for license and program information \n 2 to continue \n ";
int choice;
cin >> choice;
switch (choice)
{
case 1:
cout << "\n\n\nPressure check Program is designed to give you the Pressure loss per metre of a certain pipe for a grease pipe";
cout << "\n    Copyright (C) 2015  Samadrita Karmakar";
cout << "\n";
cout << "\n  This program is free software: you can redistribute it and/or modify";
cout << "\n    it under the terms of the GNU General Public License as published by";
cout << "\n    the Free Software Foundation, either version 3 of the License, or";
cout << "\n    (at your option) any later version.";
cout << "\n";
cout << "\n    This program is distributed in the hope that it will be useful,";
cout << "\n    but WITHOUT ANY WARRANTY; without even the implied warranty of";
cout << "\n    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the";
cout << "\n   GNU General Public License for more details.";
cout << "\n";
cout << "\n   You should have received a copy of the GNU General Public License";
cout << "\n    along with this program.  If not, see <http://www.gnu.org/licenses/>.\n\n\n";

case 2:
//find thr right flow rate
double ext_dia1, t1, int_dia1, L, vol, Tp, q, q2, Q1, T, n, L1, pwr;
int i;
cout << "Enter the no. of different pipes used. ";
cin >>i;
for (int j=1;j<=i;j++)
{
 if (j==1)
 cout << " For pipe "<<j<<" (header), \n";
 else
 cout << " For pipe "<<j<<", \n";
 cout<<"Enter the Ext dia of pipe (mm) ";
 cin >> ext_dia1;
 cout<<"Enter the thickness of pipe (mm) ";
 cin >> t1;
 int_dia1=ext_dia1-2*t1;
 int_dia1= int_dia1/1000;
  cout <<"Enter the length of pipe (m) ";
 cin>>L;
 if(j==1)
 {
  int_dia=int_dia1;
 }
 vol=pi*pow(int_dia1, 2)*L;
 vol1=vol+vol1;
}

cout<<"Enter the Total number of ports ";
cin>>Tp;
cout<< "Enter the average amount of grease required per port per day in cc ";
cin>>q;


do
{
cout <<"Enter the number of cycles you want ";
cin >>n;
cout <<"Enter the pump flow rate (in litre/hour) you want to check against ";
cin>>q2;
Q1=Tp*q/1000+n*vol1*1000*.018;
T=Q1/q2;
if ((4*T)<24)
 cout<<"The pump is suitable as far as timing and relieving is concerned.\n";
 else
  cout<<"The pump is not suitable, please choose a higher rating. \n";
  
  cout<<"The operating time is "<<T<<" hours\n The relieving time is "<<(3*T)<<" hours \n The volume to be pumped per day is "<<Q1<<" litre \n";
  cout <<"Enter 1 to stop, 0 to try again ";
  cin>> i;
 
}
 while (i<1);



case 3:	
//Density in kg/m3
double p=895;
//Viscosity in Ns/m2
double n1=0.00046;
 n=n1*p;
double ext_dia;

double t;
double Q;

//cout << "Enter external dia of pipe in mm ";
//cin >> ext_dia;
//cout << "Enter thickness in mm ";
//cin >> t;
//int_dia=ext_dia-2*t;

//int_dia= int_dia/1000;
double area= (pi*pow(int_dia,2))/4;
cout << "Enter vol flow rate in l/hr ";
cin >> Q;
Q=Q/(3600*1000);
double vel=Q/area;
double f1=f_factor_bringham (vel, int_dia);
double h_loss=4*(f1*pow(vel,2))/(2*9.81*int_dia);
double pt=(h_loss*p*9.81)*pow(10,-5);
cout << "Pressure loss in a metre of pipe of is "<< pt<< " bar \n";

cout <<" Enter the maximum length travelled by the header (m) ";
cin>>L1;
pt=(pt*1.5)*L1;
pwr=(pt*100000*Q/.5)/1000;
cout<<"The power required for the pump is "<<pwr<<" kW" ;
getchar();
}
return 0;
}

