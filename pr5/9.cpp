#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
class Date {
	int day, month, year;
public:
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	Date(char const* str) {
		sscanf(str, "%d%*c%d%*c%d", &day, &month, &year);
	}
	Date(time_t time) {
		struct tm* tmdate;
		tmdate = localtime(&time);
		/* Day.        [1-31] */
		day = tmdate->tm_mday;
		/* Month.    [0-11] */
		month = tmdate->tm_mon + 1;
		/* Year    - 1900.  */
		year = tmdate->tm_year - 100;
	}
	void show() {
		cout << day << '/' << month << '/' << year << "\n";
	}
};

int main() {
	Date strdate("19/03/19");
	strdate.show();

	Date intdate(19, 03, 19);
	intdate.show();

	Date timedate(time(NULL));
	timedate.show();
	return 0;
}