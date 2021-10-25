#include<iostream>
using namespace std;
class building{
	int floor;
	int room;
	int area;
public:
	building(int f, int r, int ar){
		floor = f;
		room = r;
		area = ar;
	}
	void show_b(){
		cout<<"Число этажей: "<< floor <<endl;
		cout<<"Число комнат: "<< room <<endl;
		cout<<"Общая площадь здания: "<< area <<endl;
	}
};

class house : public building{
	int bedrooms;
	int bathrooms;
public:
	house(int f, int r, int ar, int br, int bhtr): building(f,r,ar){
		bedrooms = br;
		bathrooms = bhtr;
	}
	void show_h(){
		show_b();
		cout<<"Число спален: "<<bedrooms<<endl;
		cout<<"Число ванных комнат: "<<bathrooms<<endl;
	}
};

class office : public building{
	int extinguisher;
	int telephones;
public:
	office(int f, int r, int ar, int ex, int t):building(f,r,ar){
		extinguisher = ex;
		telephones = t;
	}
	void show_o(){
		show_b();
		cout<<"Число огнетушителей: "<<extinguisher<<endl;
		cout<<"Число телефонов: "<<telephones<<endl;
	}
};

int main(){
	house obj1(5, 20, 5000, 40, 20);
	office obj2(3, 15, 3000, 15, 30);
	cout<<"Класс house:"<<endl;
	obj1.show_h();
	cout<<"\nКласс office:"<<endl;
	obj2.show_o();
	return 0;
}
