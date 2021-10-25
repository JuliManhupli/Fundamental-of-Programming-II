#include<iostream>
using namespace std;
class base {
	int x;
public:
	void setx(const int n) { x = n;}
	void showx() const { cout << x << ' '; }
};

class derived : private base{
	int y;
public:
	void setxy(int n, int m) { 
		setx(n); 
		y =m; 
	}
	void showxy() {
		showx(); 
		cout << y << endl;
	}
};

int main(){
	derived obj;
	obj.setxy(10, 10);
	obj.showxy();
	return 0;
}
