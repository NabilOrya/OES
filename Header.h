#include <string>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<istream>

#include<iostream>
using namespace std;
//Base Class of Customer
class Customer
{
	protected:
		string name,city,address;
		int phoneno;
		string Filename;
		static double price;
		float tax;
		int quantity=0;
		int ship_price=10;
	public:
		//This function will get the username, and other data of the customer and save it into file of the customer
		ofstream file;
		void info()
		{
			if(file)
			{
				cout<<"Enter Your Name: ";
				getline(cin,name);
				Filename=name+".txt";
				cout<<"Enter Your City: ";
				getline(cin,city);
				cout<<"Enter your address: ";
				getline(cin,address);
				cout<<"Enter your Phone Number: ";
				cin>>phoneno;
				file.open(Filename.c_str(), ios::binary | ios::app );
				file<<name<<" ";
				file<<city<<" ";
				file<<address<<" ";
				file<<phoneno;
				file.close();
			}
		}
		
		//this function will make a file of receipt and will add the purchased info of the user
		void FileHand(string items,int qntity)
		{
			ofstream fhand;
			string filename="Receipt.txt";
			fhand.open(filename.c_str(),ofstream::app);
			
			fhand<<"\nItems Price Quantity Tax Shipping_Charges Total_Price\n";
			
			fhand<<items<<" "<<qntity<<" , "<<tax<<" , "<<" $10 "<<" , "<<price;
			
			file.close();
		}
		
		//this function will calcualte and show the price of the items purhased
		
		 void billing()
		{
			if(price<=1500)
				{
					tax=price*0.1;
				}
			else if(price>1500&&price<=2500)
				{
					tax=price*0.15;
				}
			else if(price>2500)
				{
					tax=price*0.2;
				} 
				
				price=price+tax;
				cout<<"\t\t"<<"$"<<tax<<"\t\t"<<"$"<<ship_price<<"\t\t\t"<<"$"<<price+ship_price;
		}
		
		//using Polymorphism
		//virtual functions to use in derived classes
		virtual void getqt()
		{
			cout<<"How many items do you want: "<<endl;
			cin>>quantity;
		}
		
		virtual void get_item()
		{
			cout<<"Enter Item";
		}
		
		//functions to get info of the customer
		
