#include<iostream>
#include<ctime>
using namespace std;
class watch {
	time_t t;
public:
	watch() { t = time(0); }
	friend ostream &operator <<(ostream &stream, watch obj);
};

ostream &operator <<(ostream &stream, watch obj) {
	struct tm *time;
	time = localtime(&obj.t);
	stream << asctime(time) << endl;
	return stream;
}

int main() {
	watch obj1;
	cout << obj1;
	return 0;
}