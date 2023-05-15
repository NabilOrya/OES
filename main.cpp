#include <string>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<istream>
#include "Header.h"
using namespace std;


int main()
{
	system("CLS");
	int choice1;
	char cont = 'n';
	
	cout<<"\n\t\t\t ________________________________________________________________\n";
	cout<<"\n\t\t\t| WELCOME TO ONLINE E-SHOPPING OF PHONES, LAPTOPS AND HEADPHONES |\n";
	cout<<"\n\t\t\t ________________________________________________________________\n";
	cout<<"Made By\nNabil Orya Qureshi 2022475\nRukh-e-Zahra 2022508\nMariam 2022282";
	cout<<endl;
	
	//Base Class pointer
	
	Customer ctmr;
	ctmr.info();
	 
	system("pause");

	//Base Class Pointers to access virtual functions
	Customer *ptr1,*ptr2,*ptr3;
	
	//Derived class objects
	Phones phon;
	Laptops laptp;
	HeadPhones Headph;
	
	
//	bool flag=true;
	do
	{
		cout<<ctmr;
	
		cin>>choice1;
		system("CLS");
		if (choice1==1) 	//for Phones catagory
		
			{
				ptr1=&phon;
				phon.showPhoneMenu();
				ptr1->get_item();
			}
			
	else
		if (choice1==2)		//for Laptops catagory
			{
				ptr2=&laptp;
				laptp.showLaptopMenu();
				ptr2->get_item();
			}
