#include <windows.h>
#include <iostream>
#include <conio.h>
#include "manager.h"
#include "functions.h"
using namespace std;
int main(){
//	privacy _auto_;
	int choice=1,high,bg;
	char key;
	Products A;
	Customer B;
	inventory C;
	high=224;
	bg=14;
	//Check if runs-1st time
	if(!A.checkFile()){wellcome();	A.ProductsEntery();	}
	Loop:
	do{
		cls();
		newl_tab(5);
		colour(bg);
		cout<<"\t\t\tChoose option and Press Enter "<<endl<<endl;		     cout<<"\t\t\t\t";if(choice==1){colour(high);}
		cout<<"  1. Products Managment  "<<endl;	colour(bg);cout<<endl<<"\t\t\t\t";	if(choice==2){colour(high);}
		cout<<"  2. Customer Dealing    "<<endl;	colour(bg);cout<<endl<<"\t\t\t\t";	if(choice==3){colour(high);}
		cout<<"  3. Logs                "<<endl;	colour(bg);
		newl_tab(2,3);
		cout<<"Esc key exiting";	
		key=getch();
		if(key==ESC_KEY)exit(0);
		else if(key==UP_KEY){
		     if(choice==1)	choice=3;
		     else 			choice--;
		}
 	 	else if (key==DOWN_KEY){
			if(choice==3)	choice=1;
			else			choice++;
		}		
	}while(key!=ENTER_KEY);
	switch(choice){
		case 1://for Products
			A.Choose();
			break;
		case 2://For 
			B.Choose();	
			break;
		case 3://For Logs
			C.Choose();
	}
	choice=1;
	goto Loop;
	
	return 0;
}




 
