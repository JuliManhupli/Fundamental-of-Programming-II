#include<iostream>
using namespace std;
enum range { pounds, kilograms, tons };
class airship {
	int passengers;
	int weight;
	enum range rng;
public:
	airship(int p, int w, enum range r) {
		passengers = p;
		weight = w;
		rng = r;
	}
	void show_a() {
		cout << "Количество пасажиров: " << passengers << endl;
		cout << "Количество груза: " << weight << endl;
		cout << "Измерительные единицы: ";
		switch (rng) {
		case pounds: cout << "фунты" << endl;
			break;
		case kilograms: cout << "килограммы" << endl;
			break;
		case tons: cout << "тонны" << endl;
			break;
		}
	}
};

enum engine { spiral, reactive };
enum spacing { miles, kilometers };
class airplane : public airship {
	enum engine engn;
	int distance;
	enum spacing spcng;
public:
	airplane(int p, int w, enum range r, enum engine en, int d, enum spacing s) :
		airship(p, w, r) {
		engn = en;
		distance = d;
		spcng = s;
	}
	void show_ap() {
		show_a();
		cout << "Тип двигателя: ";
		switch (engn) {
		case spiral: cout << "винтовой" << endl;
			break;
		case reactive: cout << "реактивный" << endl;
			break;
		}
		cout << "Дальность полета: " << distance << endl;
		cout << "Измерительные единицы: ";
		switch (spcng) {
		case miles: cout << "мили" << endl;
			break;
		case kilometers: cout << "килиметры" << endl;
			break;
		}
	}
};

enum gas { hydrogen, helium };
enum height { feet, meters };
class balloon : public airship {
	enum gas gs;
	int ceiling;
	enum height hght;
public:
	balloon(int p, int w, enum range r, enum gas g, int с, enum height h) :
		airship(p, w, r) {
		gs = g;
		ceiling = с;
		hght = h;
	}
	void show_b() {
		show_a();
		cout << "Тип газа: ";
		switch (gs) {
		case hydrogen: cout << "водород" << endl;
			break;
		case helium: cout << "гелий" << endl;
			break;
		}
		cout << "Максимальный потолок: " << ceiling << endl;
		cout << "Измерительные единицы: ";
		switch (hght) {
		case feet: cout << "футы" << endl;
			break;
		case meters: cout << "метры" << endl;
			break;
		}
	}
};

int main() {
	airplane plane(350, 20, tons, spiral, 6000, kilometers);
	balloon ball(0, 50, pounds, hydrogen, 500, feet);
	cout << "Класс airplane:" << endl;
	plane.show_ap();
	cout << "\nКласс balloon:" << endl;
	ball.show_b();
	return 0;
}
