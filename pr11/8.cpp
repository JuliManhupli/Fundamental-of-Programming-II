#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 5
template <class X> X sort(X *list, int size){
	X temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
	return *list;
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
	char list3[SIZE]={'e', 'd', 'c', 'b', 'a'};
	print(list1, SIZE);
	sort(list1, SIZE);
	cout << "Sort: ";
	print(list1, SIZE);
	cout << endl;

	print(list2, SIZE);
	sort(list2, SIZE);
	cout << "Sort: ";
	print(list2, SIZE);
	cout << endl;	

	print(list3, SIZE);
	sort(list3, SIZE);
	cout << "Sort: ";
	print(list3, SIZE);
	return 0;
}
