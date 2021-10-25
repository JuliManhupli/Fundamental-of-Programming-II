#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main(){
	ifstream fin("file.txt");
	if(!fin){
		cout<<"Can't open input file.\n";
		return 1;
	}
	char ch;
	int arr[26] = {0}, j = 0;
	char alph[27]="abcdefghijklmnopqrstuvwxyz";
	while(!fin.eof()){
		ch = fin.get();
		if(fin.eof()){
			break;
		}
		if(islower(ch)){
			j = ch - 'a';
			arr[j]++;
		}
		if(isupper(ch)){
			j = ch - 'A';
			arr[j]++;
		}
	}
	for(int i = 0; i<26; i++){
		cout<<"Буква "<<alph[i]<<" появляется "<<arr[i]<<" раз(а)\n";
	}
	return 0;	
 }
