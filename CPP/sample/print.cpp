#include<iostream>
#include<string>

using namespace std;  //Make std accessible globablly

void f(){
	int i=10;
	cout<<"The integer variable i contains "<<i<<" and the address is "<<&i<<"\n";
}

void g(){
	string s1="Hello";
	string s2="my name is ";
	string name;
	cin>>name;
	string s4="Nice to meet you!\n";
	string s3=s1+ ", " + s2 + name + ".\n" + s4;
	cout<<s3;
}
void h(string& s){
	s="Push down automata is simply a non deterministic finite state autotma with a stack!\n";	
}

int main(){
	cout<<"Ignorance is bliss!\n";

	string s="Anti Social Social Club\n";
	string& slogan=s;
	cout<<s;
	f();
	g();
	h(slogan);
	cout<<s;
	return 0;
}
