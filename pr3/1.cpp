#include<iostream>
#include<cstring>
using namespace std;
enum color {red,yellow,green,orange};
enum ans {yes, no};
void out(bool x);
char const *c[] = {"red", "yellow", "green", "orange"};

class Fruit {
public:
	bool annual;
	bool perennial;
	bool tree;
	bool tropical;
	enum color clr;
	char name[40];
};

class Apple: public Fruit {
	bool cooking;
	bool crunchy;
	bool eating;
public:
	void seta(char const *n, enum color c, bool ck, bool crchy, bool e);
	void seta(char const *n, enum color c, enum ans ck, enum ans crchy, enum ans e);
	void show();
};

class Orange: public Fruit {
	bool juice;
	bool sour;
	bool eating;
public:
	void seto(char const *n, enum color c, bool j, bool sr, bool e);
	void seto(char const *n, enum color c, enum ans j, enum ans sr, enum ans e);
	void show();
};

void out(bool x){
	cout<<((x==false)? "no":"yes")<<"\n";
}

void Apple::seta(char const *n, enum color c,
					bool ck, bool crchy, bool e){
	strcpy(name, n); annual = false; perennial = true;
	tree = true; tropical = false; clr = c; cooking = ck;
	crunchy = crchy; eating = e;
}

void Apple::seta(char const *n, enum color c,
					enum ans ck, enum ans crchy, enum ans e){
	strcpy(name, n); annual = false; perennial = true;
	tree = true; tropical = false; clr = c; 
	((ck == yes)? cooking = true: cooking = false);
	((crchy == yes)? crunchy = true: crunchy = false);
	((e == yes)? eating = true: eating = false);
}

void Orange::seto(char const *n, enum color c,
					bool j, bool sr, bool e){
	strcpy(name, n); annual = false; perennial = true;
	tree = true; tropical = true; clr = c;juice = j;
	sour = sr; eating = e;
}

void Orange::seto(char const *n, enum color c,
					enum ans j, enum ans sr, enum ans e){
	strcpy(name, n); annual = false; perennial = true;
	tree = true; tropical = true; clr = c;
	((j == yes)? juice = true: juice = false);
	((sr == yes)? sour = true: sour = false);
	((e == yes)? eating = true: eating = false);
}

void Apple::show(){
	cout<<name<<"apple is: " << "\n";
	cout<<"Annual: "; out( annual );
	cout<<"Perennial: "; out(perennial);
	cout<<"Tree: "; out(tree);
	cout<<"Tropical: "; out(tropical);
	cout<<"Color: "<<c[clr]<<"\n";
	cout<<"Good for cooking: "; out(cooking);
	cout<<"Crunchy: "; out(crunchy);
	cout<<"Good for eating: "; out(eating);
	cout<<"\n";
}

void Orange::show(){
	cout<<name<<"orange is " << "\n";
	cout<< "Annual: "; out(annual);
	cout<<"Perennial: "; out(perennial);
	cout<<"Tree: "; out(tree);
	cout<<"Tropical: "; out(tropical);
	cout<<"Color: "<<c[clr]<<"\n";
	cout<<"Good for juice: "; out(juice);
	cout<<"Sour: "; out(juice);
	cout<<"Good for eating: "; out(eating);
	cout<<"\n";
}

int main(){
	Apple a1, a2;    
	Orange o1, o2;
	a1.seta("Red Delicious ", red, false, true,true);
	a2.seta("Jonathan ", red, yes, no, yes);
	o1.seto("Navel ", orange, false, false, true);
	o2.seto("Valencia ", orange, yes, yes, no);
	a1.show(); 
	a2.show(); 
	o1.show();
	o2.show();
	return 0;
}