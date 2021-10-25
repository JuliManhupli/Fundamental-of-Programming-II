#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 5
template <class X> int find(X object, X *list, int size){
	for(int i = 0; i<size; i++){
		if(object == list[i]) 
			return i;
	}
	return -1;
}

template <class X> void print( X *list, int size){
	for(int i = 0; i<size; i++){
		cout << list[i] <<' ' ;
	}
	cout<< "\n";
}

int main(){
	int list1[SIZE]={5,4,3,2,1};
	double list2[SIZE]={5.1, 4.2, 3.3,  2.4, 1.5};
	char list3[SIZE]={'a', 'b', 'c', 'd', 'e'};
	print(list1, SIZE);
	cout << "Find(2): " << find(2, list1, SIZE) << endl;
	print(list2, SIZE);
	cout << "Find(1.1): " << find(1.1, list2, SIZE) << endl;
	print(list3, SIZE);
	cout << "Find(b): " << find('b', list3, SIZE) << endl;
	return 0;
}
