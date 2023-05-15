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
			string getname()
			{
				return name;
			}
		string getcity()
			{
				return city;
			}
		string getadd()
			{
				return address;
			}
		
		//This function will be displayed at the end of the purchase
		void purch_complt()
		{
			cout<<"DEAR "<<name<<" YOUR ORDER WILL BE SHIPPED TO "<<address<<" \nAND YOU WILL RECEIVE THE CONFIRMATION MESSAGE ON YOUR PHONE NO. "<<phoneno;
		} 
	
	//overloading the << operator to show the menu
	
	friend ostream & operator << (ostream &out, const Customer &c);
};
//definition of function overloading

ostream & operator << (ostream &out, const Customer &c)
{
	system("CLS");
	cout<<"CHOOSE THE DESIRED CATEGORY \n";
	cout<<"1- PHONES\n";
	cout<<"2- LAPTOPS\n";
	cout<<"3- HEADPHONES\n";
	cout<<"4- EXIT\n";
}

//initializes the static member price
double Customer::price=0;

//Derived class of the customer for Phones Catagory

class Phones:public Customer
{
	private:
		 	
			 int qnt1;
			 
	public:
		
		//To show Phone items
	void showPhoneMenu()
	{
	    cout << "- - - - - - - - - - -"
	         << " - -\nItem       Cost\n";
	    cout << "1.Iphone    $1500/-\n";
	    cout << "2.Redmi    $500/-\n";
	    cout << "3.Samsung  $1000/-\n";
	    cout << "- - - - - - - - - - - - -\n";
	}
		//to get quantity
	void getqt()
	{
		cout<<"Enter the Number of items you want: "<<endl;
		cin>>qnt1;
	}
	
		//virtual function to get items for phones
		
	void get_item()
	{
		char cont1='n';
		
		int choose;
		do
		{
			cout<<"Enter number from the above items: ";
			cin>>choose;
			
			//If Else for choosign different options
			
		if(choose==1)
			{
				getqt();
				string items="Iphone , $1500 ,";
				price=price+(1500*qnt1)+ship_price;
				
				cout<<"Item\t  Qunatity  \t\tPrice\t\tTax \t\tShipping Charges\tTotal Prize\n\n";
				cout<<"Iphone\t\t"<<qnt1<<"\t\t"<<"$"<<1500*qnt1;
				billing();
				FileHand(items,qnt1);
			}
			
		else
			if(choose==2)
			{
				getqt();
				string items2="Redmi , $500 ,";
				price=price+(500*qnt1)+ship_price;
				cout<<"Item\t  Qunatity  \t\tPrice\t\tTax \t\tShipping Charges\tTotal Prize\n\n";
				cout<<"Redmi\t\t"<<qnt1<<"\t\t"<<"$"<<500*qnt1;
				billing();
				FileHand(items2,qnt1);
			}
			
		else 
			if(choose==3)
			{
				getqt();
				string items3="Samsung , $1000 ,";
				price=price+(1000*qnt1)+ship_price;		
				cout<<"Item\t  Qunatity  \t\tPrice\t\tTax \t\tShipping Charges\tTotal Prize\n\n";
				cout<<"Samsung\t\t"<<qnt1<<"\t\t"<<"$"<<1000*qnt1;
				billing();
				FileHand(items3,qnt1);
			}
			
		else 
			{
				cout<<"Invalid Entry";
				break;
			}
		
		bool valid1 = true;
			do 
			{
				cout << "\nDo you want to continue Shopping?(Y/N) ";
				cin >> cont1;
	
				if ((cont1 == 'y') || (cont1 == 'Y') || (cont1 == 'n') || (cont1 == 'N')) {
					valid1 = true;
				}
				else 
				{
					cout << "Invalid Entry" << endl;
					valid1 = false;
				}
			} while (!valid1);
	
	} while (cont1 == 'y' || cont1 == 'Y');
	}

}; 

//base class of customer 
class Laptops:public Customer{
	private:
		int qnt2;
	public:
		
		//To show Items in laptop catagory
	void showLaptopMenu()
	{
	    cout << "- - - - - - - - - - -"
	         << " - -\nItem       Cost\n";
	    cout << "1.Macbook  $2000/-\n";
	    cout << "2.HP       $1000/-\n";
	    cout << "3.Lenovo   $500/-\n";
	    cout << "- - - - - - - - - - - - -\n";
	}
	
	//to get qunatity
	
		void getqt()
	{
		cout<<"Enter the Number of items you want: "<<endl;
		cin>>qnt2;
	}
	
	//funtion for choices 
	
	void get_item()
	{
		char cont2='n';
		int choose1;
		
		do
		{
		cout<<"\nEnter number from the above items: ";
		cin>>choose1;
		
		//if else for different choices
		
		if(choose1==1)
		
			{
				getqt();
				string itm1="MacBook , $2000 ,";
				price=price  +(2000*qnt2) + ship_price;
				
				cout<<"Item\t  Qunatity  \t\tPrice\t\tTax \t\tShipping Charges\tTotal Prize\n\n";
				cout<<"Macbook\t\t"<<qnt2<<"\t\t"<<"$"<<2000*qnt2;
				billing();
				FileHand(itm1,qnt2);
			}
			
		else 
			if(choose1==2)
			{
				getqt();
				string itm2="HP , $1000 ,";
				price=price+(1000*qnt2)+ship_price;	
					
				cout<<"Item\t  Qunatity  \t\tPrice\t\tTax \t\tShipping Charges\tTotal Prize\n\n";
				cout<<"HP\t\t"<<qnt2<<"\t\t"<<"$"<<1000*qnt2;
				billing();
				FileHand(itm2,qnt2);
			}
			
		else 
			if(choose1==3)
			{
				getqt();
				string itm3="Lenovo , $500 ,";
				price=price+(500*qnt2)+ship_price;	
				
				cout<<"Item\t  Qunatity  \t\tPrice\t\tTax \t\tShipping Charges\tTotal Prize\n\n";
				cout<<"Lenovo\t\t"<<qnt2<<"\t\t"<<"$"<<500*qnt2;
				billing();
				FileHand(itm3,qnt2);	
			}
			
		else 
			{
				cout<<"Invalid Entry";
				break;
			}
				//for customer to continue shopping 
			
		bool valid2 = true;
		
		do {
				cout << "\nDo you want to continue Shopping?(Y/N) ";
				cin >> cont2;
	
			if ((cont2 == 'y') || (cont2 == 'Y') || (cont2 == 'n') || (cont2 == 'N')) 
				{
				
							valid2 = true;
				}
				else 
					{
						cout << "Invalid Entry" << endl;
					
						valid2 = false;
							continue;
					}
			} while (!valid2);
			
		} while (cont2 == 'y' || cont2 == 'Y');
	
	}
};

//base class of customer 

class HeadPhones:public Customer{
	private:
		int qnt3;
		
	public:
		
		//to show itmen in HeadPhones Catagory
		
	void showHeadPhoneMenu()
	{
	    cout << "- - - - - - - - - - -"
	         << " - -\nItem       Cost\n";
	    cout << "1.Sennheiser  $800/-\n";
	    cout << "2.Sony     $700/-\n";
	    cout << "3.Bose   $600/-\n";
	    cout << "- - - - - - - - - - - - -\n";
	}
	
	//to get quantity
	
	void getqt()
	{
		cout<<"Enter the Number of items you want: "<<endl;
		cin>>qnt3;
	}
	
	// funtion for choices
	
	void get_item()
	{
		char cont3='n';
		int choose2;
		
		//Customer  to chose from diff catagories
		
		do
		{
			cout<<"\nEnter number from the above items: ";
			cin>>choose2;
			
			//if else for differnet options
			
			if(choose2==1)
				{
					getqt();
					string it1="Sennheiser , $800 ,";
					price=price+(800*qnt3)+ship_price;
					cout<<"Item\t\tQunatity  \tPrice\t\tTax\tShipping Charges \t\tTotal Prize\n\n";
					cout<<"Sennheiser\t "<<qnt3<<"\t\t"<<"$"<<800*qnt3;
					billing();
					FileHand(it1,qnt3);	
					
				}
				
			else 
				if(choose2==2)
				{
					getqt();
					string it2="Sony , $700 ,";
					price=price+(700*qnt3)+ship_price;	
					cout<<"Item\t\tQunatity  \tPrice\t\tTax\tShipping Charges \t  Total Prize\n\n";
					cout<<"Sony\t\t  "<<qnt3<<"\t\t"<<"$"<<700*qnt3;
					billing();
					FileHand(it2,qnt3);	
				}
				
			else 
				if(choose2==3)
				{
					getqt();
					string it3="Bose , $600 ,";
					price=price+(600*qnt3)+ship_price;
					cout<<"Item\t\tQunatity  \tPrice\t\tTax\tShipping Charges \t  Total Prize\n\n";
					cout<<"Bose\t\t"<<qnt3<<"\t\t"<<"$"<<600*qnt3;
					billing();	
					FileHand(it3,qnt3);		
				}
				
			else 
				{
					cout<<"Invalid Entry";
					break;
				}
		
		//for continue shopping
		
			bool valid3 = true;
					
			
