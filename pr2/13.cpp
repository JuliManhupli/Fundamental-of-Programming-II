#include<iostream>
#include<cstring>
using namespace std;

void rev_str(char *s1);
void rev_str(char *s1,char  *s2);

int main(){
	char s1[80], s2[80];
	strcpy (s1, "hello");
	rev_str(s1, s2); 
	rev_str(s1); 
	return 0;
}

void rev_str(char *s1){
	for(int i=strlen(s1); i>=0; i--)
		cout<<s1[i];
}

void rev_str(char *s1, char *s2){
	int j=0;
	int n = strlen(s2);
	for(int i=strlen(s1)-1; i>=0;i--){
		s2[j]=s1[i];
		j++;
	}
	for(j=0; j < n; j++)
		cout<<s2[j];

}

