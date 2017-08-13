#ifndef _functions_h
#define _functions_h

#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;
const int UP_KEY=72,DOWN_KEY=80,ENTER_KEY=13,ESC_KEY=27,LEFT_KEY=75,RIGHT_KEY=77;
//void a(){
//	MessageBox();
//}

void cls(){
 system("cls");	
}
string chartostr(char *ch,int len){
	string str;
	for(int a=1;a<len;a++){
		str+=*ch;
		ch++;
	}
	return str;
}
void colour(int a=7) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void CH(char a,int num){
	for(int x=1;x<=num;x++){
		cout<<a;
	}
}

int _INT_(string data){
    int a;
    string temp;
    for(int x=1;x<data.length();x++){
    	
   	if(data[x]>='0'||data[x]<='9'){
//   		temp=
    		}	
    }
}
void wrong_input(){
	colour(12);
	cout<<"[x] Wrong Input !! (Error) 0x00 \n";
	cin.clear();
	fflush(stdin);
	colour();
}
void newl_tab(int a,int b=0){
	int c;
	for(c=1;c<=a;c++){
		cout<<"\n";
	}
	for(c=1;c<=b;c++){
		cout<<"\t";
	}
}

void Remove_lines(string n){
        string name=n;
  		char character;
		ifstream orignal(name.c_str());
  		ofstream temp("temp.saq");
		while(!orignal.eof()){
			character=orignal.get();
   			 if(character==10){
   				if(orignal.peek()==-1) break;
   				temp<<character;
   				while(character==10){character=orignal.get();}
   			}
   			if(character=='ÿ')break;
			temp<<character;
		}
		temp.close();
		orignal.close();
		remove(name.c_str());
		rename("temp.saq",name.c_str());
}
void title(string header){
	cout<<"\n********************************************************************************";
	cout<<"                              "<<header<<endl;
	cout<<"********************************************************************************";
}
void line(int num){
	CH(205,num);
	cout<<endl;
}
void record_header(){
	char a=201,b=187,c=200,d=188,e=186,f=124;
	cout<<a;CH(205,60);cout<<b<<endl;
	cout<<e<<" Sr#  "<<f<<"  Name         "<<f<<"  Product Code  "<<f<<" Price  "<<f<<"  Quantity "<<e<<endl;
	cout<<c;CH(205,60);cout<<d<<endl;
}
void msg_ok(string a){
	MessageBox(NULL,a.c_str(),"Information",MB_ICONINFORMATION|MB_DEFBUTTON1);
}
void msg_warn(string a){
	MessageBox(NULL,a.c_str(),"Warning",MB_OK|MB_ICONWARNING|MB_DEFBUTTON1);
}
void wellcome(){
	cls();
//	for(int a;a<=)
}
void Selection(){
	cout<<"1. Products Inventory"<<endl;
	cout<<"2. Selling"<<endl;
	cout<<"3. For Viewing Logs"<<endl;
	
}
string raw_time(string dt){
	return dt;
}
string date_time(){
      time_t now = time(0);
      char* dt = ctime(&now);
      string _raw=raw_time(dt);
      string date_=_raw.substr(8,2)+"-"+_raw.substr(4,3)+"-"+_raw.substr(20,4);
	string time_=_raw.substr(11,8);
	return date_+"_"+time_;
}
void swap(int *a,int *b){int c;c=*a;*a=*b;*b=c;}
void csv_read(string name){
	ifstream A(name.c_str());
	ofstream B("temp1");
	char x;
	string d;
	getline(A,d);
	while(!A.eof()){
		x=A.get();
		if(x==' '){
  		     B<<'_';
  		     continue;
		}else if(x==','){
			B<<' ';
			continue;
		}
		else if(x=='ÿ')break;
		B<<x;
	}
	A.close();
	B.close();
}
#endif
