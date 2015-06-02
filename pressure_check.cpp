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

cout <<" Welcome to Pressure Check Program. \n Enter 1 for license and program information and 2 to continue ";
int choice;
cin >> choice;
switch (choice)
{
case 1:
cout << "\n\n\nPressure check Program is desinged to give you the Pressure loss per metre of a certain pipe for a grease pipe";
cout << "\n    Copyright (C) 2015  Samadrita Karmakar and Manoj";
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
//Density in kg/m3
double p=895;
//Viscosity in Ns/m2
double n1=0.00046;
double n=n1*p;
double ext_dia;
double pi=22/7;
double t;
double Q;

cout << "Enter external dia of pipe in mm ";
cin >> ext_dia;
cout << "Enter thickness in mm ";
cin >> t;
double int_dia=ext_dia-2*t;

int_dia= int_dia/1000;
double area= (pi*pow(int_dia,2))/4;
cout << "Enter vol flow rate in l/hr ";
cin >> Q;
Q=Q/(3600*1000);
double vel=Q/area;
double f1=f_factor_bringham (vel, int_dia);
double h_loss=4*(f1*pow(vel,2))/(2*9.81*int_dia);
double pt=(h_loss*p*9.81)*pow(10,-5);
cout << "Pressure loss in a metre of pipe of OD "<< ext_dia <<" mm and thickness "<< t << "mm is "<< pt<< " bar\n";
getchar();
}
return 0;
}

