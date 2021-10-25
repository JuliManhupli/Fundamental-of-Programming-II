#include<iostream>
using namespace std;

class planet {
	int moons;
	double dist_from_sun; // in miles
	double diameter;
	double mass;
public:
	planet(double d);
	double get_miles() { return dist_from_sun; }
};

planet::planet(double d){
	dist_from_sun = d;
}

double light(planet p){
	return p.get_miles()/186000;
}

int main(){
	planet m(146880000);
	cout<<light(m);
	return 0;
}

