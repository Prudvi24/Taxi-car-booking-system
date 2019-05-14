#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>

using namespace std;

string user="prince", pass="password";

void reg();
void detail();
void log_in();
void logout();
void del();

string name;
int log=0;

int main()
{
	  cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
	  cout<<"|                                                                                                          |"<<endl;
	  cout<<"|                                           TAXI BOOKING SYSTEM                                            |"<<endl;
	  cout<<"|                                                                                                          |"<<endl;
	  cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
	  
	  cout<<"Press any key to continue......"<<endl;
	  getchar();
	  
	  cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
	  cout<<"|                                                                                                          |"<<endl;
	  cout<<"|                                        WELCOME TO THE HYDEABAD TRAVELS                                   |"<<endl;
	  cout<<"|                                                                                                          |"<<endl;
	  cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
	  
menu:
	  cout<<"Press any key to continue"<<endl;
	  getchar();
	  
	  int a,b;
	  
	  cout<<"----------------------------------------------MENU---------------------------------------------------------"<<endl;
	  cout<<"|                                                                                                         |"<<endl;
	  cout<<"|                                       1.Register your details                                           |"<<endl;
	  cout<<"|                                       2.View your details                                               |"<<endl;
	  cout<<"|                                       3.cancel your booking                                             |"<<endl;
	  if(log==0)
	  cout<<"|                                       4.Login                                                           |"<<endl;
	  else
	  cout<<"|                                       4.Logout                                                          |"<<endl;
	  cout<<"|                                       5.Exit                                                            |"<<endl;
	  cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
back: 
      cout<<"Enter your option"<<endl;
      cin>>a;
      char t;
      switch(a)
      {
        case 1:
			if(log==0)
   	{
      	cout<<"Login here to continue.."<<endl;
      	getchar();
      	goto menu;
          }
          else
          {
          	cout<<"---------------------------------Registration goes here----------------------------------------------"<<endl;
          	  reg();
          	  cout<<"------------------------Thankyou for visiting Hyderabad Travels------------------------------------"<<endl;
          	  cout<<"                                                                                                   "<<endl;
          	  cout<<"------------------visit at: www.hydtravels.com-----------------------------------------------------"<<endl;
          	  goto menu;
		  }
		  break;
		  case 2:
		  	{
		  		cout<<"---------------------------Get the details of the tourist--------------------------------------"<<endl;
		  		  detail();
		  		  getchar();
		  		  goto menu;
			  }
			  break;
		 case 3:if(log==0)
		 		{
		 		  cout<<"Login here to continue..."<<endl;
				   getchar();
				   goto menu;	
				 }
				 else
				 {
				 	cout<<"-------------------------------cancel Booking here----------------------------------------"<<endl;
				 	del();
				 	goto menu;
				 }
				 break;
				 
		 case 4:
		 		cout<<"-----------------------------------Login portal-----------------------------------------------"<<endl;
		 		if(log==0)
		 		{
		 			log_in();
				 }
				 else
				 {
	
				    logout();
				    getchar();
			     }
			     goto menu;
				 break;
		 case 5:
		        cout<<"Successfully exit"<<endl;
				exit(0);
				break;
		 default:
		      cout<<"Please try again"<<endl;
			  goto back;		  	
      	
	  }
	  
	return 0;
}
void reg()
{
	string from,to;
	int km,bill;
	char name[50];
	
	cout<<"Enter your name"<<endl;
	cin>>name;
	
	cout<<"Enter the source place"<<endl;
	cin>>from;
	
	cout<<"Enter the destination place"<<endl;
	cin>>to;
	
	cout<<"Enter the no.of KM"<<endl;
	cin>>km;
	
	bill=(km*10);
	
	cout<<"The travel bill for your tour: "<<bill<<endl;
	
	ofstream fout1;
	fout1.open(name,ios::out);
	fout1<<"Name: "<<name<<endl;
	fout1<<"Source: "<<from<<endl;
	fout1<<"Destination: "<<to<<endl;
	fout1<<"Tour bill: "<<bill<<endl;
	fout1.close();	
}
void detail()
{
	string line;
	char name[50];
    cout<<"Enter the name"<<endl;
    cin>>name;
    
	ifstream fin1;
	cout<<"----------------------------------------DETAILS OF THE TOURIST-----------------------------------------------"<<endl;
	fin1.open(name,ios::in);
	while(getline(fin1,line))
	{
		cout<<line<<endl;
	}
		fin1.close();
}
void log_in()
{
	string userenter,passenter;
	cout<<"Enter the username"<<endl;
	cin>>userenter;
	cout<<"Enter the password"<<endl;
	cin>>passenter;
	
	if(userenter==user&&passenter==pass)
	{
		log=1;
		cout<<"Successfully logged_In"<<endl;
	}
	else
	{
		cout<<"Incorrect username or password"<<endl;
	}
}

void logout()
{
	log=0;
	cout<<"Successfully logged_out"<<endl;
}
void del()
{
	fstream fout1,fin1;
	string line;
	char name[50];
	cout<<"Enter the name"<<endl;
	cin>>name;
    remove(name);
}


