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
	else
		if(choice1==3)
			{
				ptr3=&Headph;		//for HeadPhones catagory
				Headph.showHeadPhoneMenu();
				ptr3->get_item();
			}
			
	
		//for exit
			
		else
		 if(choice1==4)
			{
				break;
			}
		else 
			{
				cout<<"Invalid Input";
				
				cont='y';
			}
		
		bool valid = true;
				

		do {
			
			cout << "\nDo you want to continue?(Y/N) ";
			
			cin >> cont;

			if ((cont == 'y') || (cont == 'Y') || (cont == 'n') || (cont == 'N')) 
			
			{
				
					valid = true;
					
			}
			
			else 
				{
					cout << "Invalid Entry" << endl;
					valid = false;
				}
		} while (!valid);

	} while (cont == 'y' || cont == 'Y');
		
		//Ending Message to Customer
	ctmr.purch_complt();
	
	cout<<"\n\t\t\t\t_________________________\n";
	cout<<"\n\n\t\t\t\tTHNAKS FOR YOUR VISIT\n";
	cout<<"\t\t\t\t_________________________\n";
	system("pause");
}
		
