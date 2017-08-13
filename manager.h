/* This Module is Developed by Saqib Aleem 
//Variables 
ID       : ProductID
record   : Stroing information on File Input Stream
name     : Name of the Product
qty      : Quantity
User     : User's Input 
entery   : Number of record to be create initially
total    : Total Number of records
fl       : For File Handling
yn       : Yes or No
a        : Temporary Variable for loop
--------------------------------------------------

//Functions
1	ProductData		: For Entering All of the Product Data 
2	checkFile		: Check File if Exist
3	ProductsEntery	: Create Product.dat File and Enter Record Initially
4	AddProduct		: Adding Single Record
5	DeleteRecord	: Delete Single Record
6	ViewRecord		: View Single Record
7	ModifyRecord	: Change Single Product
8	ListProducts	: List All
	
*/
#ifndef _manager_h
#define _manager_h

#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "functions.h"
using namespace std;
class privacy{
	private:
		string password,pass,pro;
		fstream fl,fl1;
	public:
 		 privacy(){
 		 	check();
	 		in();
 			loop:
 		 	cls();
 		 	newl_tab(4,3);
			cout<<"Enter your Password  >> ";
 		 	getline(cin,pass);
 		 	if(pass!=password){
				cout<<"[x] Error ! Wrong Password"<<endl;
				system("pause");
				goto loop;
			}
	 	}
		  void encrypt(){
		  	pro="ThisisEncyptedFile";
		  	int len,x,y;
		  	string key="th3b0dy0fP@kist@n";
		  	len=key.length();
		  	for (x=0, y=0; pass[x]!='\0'; x++){
 		  	    if (y == len) y = 0;
            	    pass[x] += key[y];
    		      }
    		      for (x=0, y=0; pro[x]!='\0'; x++){
 		  	    if (y == len) y = 0;
            	    pro[x] += key[y];
    		      }
		  }
		  void decrypt(){
		  	int len,x,y;
		  	string key="th3b0dy0fP@kist@n";
			//Decrypting Start here
			for (x=0 , y=0 ;password[x]!='\0' ; x++){
			    if (y == len) y = 0;
			    password[x] -= key[y];
			}
			for (x=0 , y=0 ;pro[x]!='\0' ; x++){
			    if (y == len) y = 0;
			    pro[x] -= key[y];
			}
		  }
		  void error_gen(int a){
		  	colour(13);
		  	cout<<a<<"There is a problem with files";
		  	MessageBox(NULL,"Contact your Develper ASAP","Error File not Found",MB_OK|MB_ICONINFORMATION|MB_DEFBUTTON1);
			exit(-1);
		  }
		  void in(){
		  	fl.open("data.ini",ios::in);
		  	fl>>pro;
		  	fl>>password;
		  	decrypt();
		  	if(pro!="ThisisEncyptedFile"){
		  		fl.close();
			  	error_gen(1);
	  		}
		  }
		  bool check(){
		  	fl.open("data.ini",ios::in);
		  	if(!fl){
		  		fl1.open("log.csv",ios::in);
		  		if(!fl1){
		  			fl.close();
		  			fl1.close();
		  			set();
				}
			      else{
			      	fl1.close();
			      	fl.close();
				  	error_gen(2);
				}
			  }
			  fl.close();
		  	  return 1;
		  }
		  void set(){
		  	fl.open("data.ini",ios::out);
		  	cout<<"Set your new Password Carefully... and please remember it later"<<endl;
		  	getline(cin,pass);
		  	encrypt();
		  	fl<<pro<<endl;
		  	fl<<pass<<endl;
		  	fl.close();
		  }
		  
};
class Products{
	private:
		string name,ID,record; 
		char yn;
		float price,qty;
		int User,entery,a,total,size;
		int choice,bg,high;
		fstream fl;
		//1
		
		void ProductData(){
			wapis:
			fflush(stdin);
			cout <<"   [?] Name of the product >> ";
			getline(cin,name);
			if(name==""){
				wrong_input();
				goto wapis;
			}
			for(a=0;a<name.length();a++){if(name[a]==' ')name[a]='_';}
			 //I have used a trick here to Eleminated spaces Error
			wapis2:
			cout <<"   [?] Item Code # ";
			cin >>ID;
			if(ID==""){
				goto wapis2;
			}
			wapis3:
			cout <<"   [?] Price >> ";
			cin >> price;
			if(cin.fail()){
				wrong_input();
				goto wapis3;
			}
			wapis4:
			cout <<"   [?] Quantity >> ";
			cin>>qty;
			if(cin.fail()){
				wrong_input();
				goto wapis4;
			}
		}
		
	public:
		void Choose(){
			bg=10;
			high=15;
			choice=1;
			do{
				cls();
				colour(bg);
				cout<<"Press Enter ."<<endl<<"\t\t";					if(choice==1){colour(high);}
					cout<<": Viewing a single Record "<<endl;   colour(bg);cout<<"\t\t";	if(choice==2){colour(high);}
					cout<<": Deleting a single Record "<<endl;	colour(bg);cout<<"\t\t";	if(choice==3){colour(high);}
					cout<<": Modifying a Single Record "<<endl;	colour(bg);cout<<"\t\t";	if(choice==4){colour(high);}
					cout<<": Viewing all Records "<<endl;		colour(bg);cout<<"\t\t";	if(choice==5){colour(high);}
					cout<<": Adding a Record "<<endl;		colour(bg);
					cout<<"\n\tPress Esc Key for previous menu"<<endl;
					a=getch();
					if(a==ESC_KEY)return;
				else if(a==UP_KEY){
					if(choice==1)	choice=5;
					else 			choice--;
				}
				else if (a==DOWN_KEY){
					if(choice==5)	choice=1;
					else			choice++;
				}
			}while(a!=ENTER_KEY);
			//switch here
			switch(choice){
				case 1:
					colour(11);
					ViewRecord();
					break;
				case 2:
					DeleteRecord();
					break;
				case 3:
					ModifyRecord();
					break;
				case 4:
					colour(11);
					ListProducts();
					break;
				case 5:
					AddProduct();
					break;
			}
			getch();
		}
		void S_CHK(){
			 fl.open("product.dat",ios::in);
			 for(a=1;!fl.eof();a++){
			 	getline(fl,record);
			 }
	 		 fl.close();
	 		 total=a-1;
	 		 cout<<"Total = "<<total<<endl;
		}
		//2
		bool checkFile(){
			fl.open("product.dat",ios::in);
			if(!fl){
			msg_ok("Products Data file Not Found \nI am Creating New a one");	
			fl.close();
			return 0;
			}
			else{
				fl.close();
				return 1;
			}
		}
		
		//3
		void ProductsEntery(){
			title("Products Entering");
			cout<<"[?] How many Products you want to enter "<<endl;
			cin>>entery;
			fl.open("product.dat",ios::out);
			for(a=1; a <=entery; a++){
				cout <<" #"<<a<<endl;
				ProductData();
				fl<<name<<" "<<ID<<" "<<price<<" "<<qty;
				if(a<entery){
					fl<<endl;
				}
			}
			fl.close();
		}
		//4
		void AddProduct(){
			title("Add Products");
			fl.open("product.dat",ios::app);
			ProductData();
			fl<<endl<<name<<" "<<ID<<" "<<price<<" "<<qty;
			fl.close();
		}
		//5
		void DeleteRecord(){
			title("Delete Products");
			ViewRecord();
			fl.open("product.dat",ios::in);
			fstream temp("temp.dat",ios::out);
			a=MessageBox(NULL,"Are you sure ? \n You want to delete that record","Warning",MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON1);
			if(a==7||a==2){
				cout<<"Record is not deleted... ";
				return ;
			}
			for(a=1;fl.good();a++){
				getline(fl,record);
				if(a!=User){
					temp<<record<<endl;	
				}
			}
			fl.close();
			temp.close();
			remove("product.dat");
			rename("temp.dat","product.dat");
			cout<<"Deleted   ";
			ID=name="";
			price=qty=0;
			Remove_lines("product.dat");
		}
		bool by_itemcode(string code){
			fl.open("product.dat",ios::in);
			cout<<"Viewing Products"<<endl;
			for(a=1;!fl.eof();a++){
				fl>>name>>ID>>price>>qty;
				if(code==ID) {
					fl.close();
					return true;	
				}
			}
			fl.close();
			return false;
		}
		//6
		void ViewRecord(int u=0,bool called=true){
			S_CHK();
			fl.open("product.dat",ios::in);
			if(called!=true && u==0) title("Viewing Product");
			
			Loop:
			if(u==0){
				cout<<"Enter Number of Record you want ";
				cin>>User;
			}
			else User=u;
			u=0;
			if(User>total||User<=0){
				MessageBox(NULL,"Record you're finding doesn't exits","Error 404",MB_OK|MB_ICONWARNING|MB_DEFBUTTON1);
				cout<<"Invalid Input # "<<endl;
				goto Loop;
			}
			newl_tab(1);
			record_header();
			for(a=1;!fl.eof();a++){
				fl>>name>>ID>>price>>qty;
				if(User==a)break;				
			}
			if(u==0)
			cout<<left<<setw(3)<<a<<"\t"<<setw(20)<<name.c_str()<<"  "<<setw(9)<<ID<<"   "<<setw(8)<<price<<"      "<<qty<<endl;
			fl.close();
		}
		//7
		void ModifyRecord(){
			title("Modify Record");
			ViewRecord();
			ProductData();
			fl.open("product.dat",ios::in);
			fstream temp("temp.dat",ios::out);
			for(a=1;fl.good();a++){
				getline(fl,record);
				if(User==a){
					if(a!=1)temp<<endl;
					temp<<name<<" "<<ID<<" "<<price<<" "<<qty;
					continue;
				}
				if(a==1){
					temp<<record;
					continue;
				}
				temp<<endl<<record;
			}
			fl.close();
			temp.close();
			remove("product.dat");
			rename("temp.dat","product.dat");
			cout<<"Modified"<<endl;
			MessageBox(NULL,"Record Successfully Modified","Information",MB_ICONINFORMATION|MB_DEFBUTTON1);
		}
		void ModifyRecord(int _num,int _qty){//For Changing result after selling
			fl.open("product.dat",ios::in);
			fstream temp("temp.dat",ios::out);
			for(a=1;!fl.eof();a++){
				getline(fl,record);
				if(a==_num){
					if(a!=1)temp<<endl;
					temp<<name<<" "<<ID<<" "<<price<<" "<<_qty;
					continue;
				}
				if(a==1){
					temp<<record;
					continue;
				}
				temp<<endl<<record;
			}
			fl.close();
			temp.close();
			remove("product.dat");
			rename("temp.dat","product.dat");
		}
		//8
		void ListProducts(){
			title("List of Product");
			newl_tab(2);
			fl.open("product.dat",ios::in);
			record_header();
			for(a=1;!fl.eof();a++){
				fl>>name>>ID>>price>>qty;
				cout<<" "<<left<<setw(3)<<a<<"\t"<<setw(20)<<name.c_str()<<setw(9)<<ID<<"   "<<setw(8)<<price<<"      "<<qty<<endl;
				
			}
			fl.close();
		}
		friend class Customer;
};
void csv_read(string name);
class inventory{
	private:
		fstream fl;
		int pos1,pos2,bg,high;
		string record,temp;
		string Date,Time,item_code,price,qty,trans,name;
	public:
		inventory(){
			fl.open("log.csv",ios::in);
			if(!fl){
				fl.close();
				fl.open("log.csv",ios::out);
				fl<<"Date ,"<<"Time ,"<<"Name,"<<"item_code,"<<"Price,"<<"Quantity,"<<"Trans";
			}
			fl.close();
		}
		void log(string name,string ID,float price,float qty,string trans){
			get_date();
			fl.open("log.csv",ios::app);
			fl<<endl<<Date<<","<<Time<<",";
			fl<<name<<","<<ID<<","<<price<<","<<qty<<","<<trans;
			fl.close();
		}
		void Choose(){
			bg=15;
			high=112;
			char a;
			int choice;
			system("color 7");
			choice=1;
			do{
			cls();
			colour(bg);
			cout<<"\t\tPress Enter"<<endl<<endl<<"\t\t\t";	if(choice==1){colour(high);}
			cout<<" On MS Excel   "<<endl<<endl;			colour(bg);cout<<"\t\t\t";	if(choice==2){colour(high);}
			cout<<" On console    "<<endl<<endl;				colour(bg);
			cout<<"\t\tEsc key for back menu";	
			a=getch();
			if(a==ESC_KEY){
				return ;
			}
			else if(a==UP_KEY){
				if(choice==1)	choice=2;
				else 			choice--;
			}
	 	 	else if (a==DOWN_KEY){
				if(choice==2)	choice=1;
				else			choice++;
			}
			}while(a!=ENTER_KEY);
			switch(choice){
				case 1:
					cout<<"\n\n[!] Please wait "<<endl;
					system("start log.csv");
					break;
				case 2:
					show();
					break;
			}
			cout<<endl;
			system("pause");
		}
		void get_date(){
			string temp=date_time();
			Date=temp.substr(0,temp.find("_"));
			Time=temp.substr(temp.find("_")+1);
		}
		void show(){
			csv_read("log.csv");
			fl.open("temp1",ios::in);
			cout<<"\n\n\n";
			char li=186;
			cout<<"# "<<li<<"   Date     "<<li<<"   Time    "<<li<<" Item Code "<<li<<"Price "<<li<<" Qty  "<<li<<" Debit/Credit"<<endl;
			line(70);
			for(int a=1;!fl.eof();a++){
				fl>>Date>>Time>>name>>item_code>>price>>qty>>trans;
				colour(7);
				cout<<left<<setw(3)<<a<<" ";
				cout<<setw(11)<<Date<<"   ";colour(13);
				cout<<Time<<"     ";colour(14);
				cout<<left<<setw(7)<<item_code.c_str()<<" ";colour(12);
				cout<<right<<setw(5)<<price<<"    ";colour(15);
				cout<<setw(4)<<qty<<"        ";
				cout<<left<<setw(6)<<trans.c_str()<<endl;
			}
			getch();
			fl.close();
			remove("temp1");
		}
		
};

class Customer{
	private:
		string name,id; //Data-members from Product class
		float price,qty;//from Product class
		int num;
			   //
		int trans;
		int user;
		float total_price;
		inventory sale;
		Products data;
		int choice,bg,high;
		string temp;
		bool found;
		char a;
	public:
		void Choose(){
			choice=1;
			bg=15;
			high=240;
			do{
			cls();
			colour(bg);
			cout<<"Press enter "<<endl;			if(choice==1){colour(high);}
			cout<<"     1. By Item code"<<endl;		colour(bg);	if(choice==2){colour(high);}
			cout<<"     2. By List Number"<<endl;	colour(bg);
			cout<<endl<<"Esc key for back menu\n";	
			a=getch();
			if(a==ESC_KEY){
				return ;
			}
			else if(a==UP_KEY){
				if(choice==1)	choice=2;
				else 			choice--;
			}
	 	 	else if (a==DOWN_KEY){
				if(choice==2)	choice=1;
				else			choice++;
			}
			
			}while(a!=ENTER_KEY);
			found=true;
			switch(choice){
				case 1://by item code
				     get();
					break;
				case 2://by list number
				     get1();
					break;
			}
			cls();
			if(found){
				selling();
				cout<<"[!] Thank You";
				msg_warn("Thank you for shopping");
			}
		}
		get(){
			wapis:
			cout<<"\n\n\n Enter Item Code (ID) of the product >> ";
			cin>>temp;
			if(temp==""){
				wrong_input();
				goto wapis;
			}
			
			if(data.by_itemcode(temp)){
				name=data.name;
				id=data.ID;
				price=data.price;
				qty=data.qty;
				num=data.a;
				found=true;
			}
			else{
				cout<<"[x] Record not found"<<endl;
				msg_ok("Record you'r searching is not found'");
				found=false;
			}
		}
		void get1(){
			cout<<"\n\nEnter List number of record ";
			cin>>user;
			data.ViewRecord(user);
			name=data.name;
			id=data.ID;
			price=data.price;
			qty=data.qty;
			num=data.a;
			found=true;
		}
		void selling(){
			view();
			wapis:
			cout<<"Price per product "<<price<<"/-Rs."<<endl;
			cout<<"How many products you want to buy >> ";
			cin>>user;
			if(cin.fail()){
				wrong_input();
				goto wapis;
			}
//			if(user==0)goto akhir;
			total_price=user*price;
			cout<<"Bill= "<<total_price<<endl;
			wapis2:
			cout<<"(1). Debit"<<endl;
			cout<<"(2). Credit"<<endl;
			cin>>trans;
			if(trans>2||trans<1) {
				wrong_input();
				goto wapis2;	
			}
			qty-=user;
			if(trans==1)temp="Debit";
			else		temp="Credit";
			sale.log(name,id,price,user,temp);
			data.ModifyRecord(num,qty);
//			akhir:
		}
		void view(){
			cout<<"Name      :  "<<name<<endl;
			cout<<"Item code :  "<<id<<endl;
			cout<<"Price     :  "<<price<<" Rs."<<endl;
			cout<<"Quantiity :  "<<qty<<endl;
			cout<<"-------------------------------\n"<<endl;	
		}
};
#endif
