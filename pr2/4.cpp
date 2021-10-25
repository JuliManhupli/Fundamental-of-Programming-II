#include <iostream>
using namespace std;
 
class card {
    string title;
    string author;
    int n;
public:
    void store();
    void show();   
};

void card::store (){
     cout<<"Введіть назву книги"<<"\n"; 
     cin>>title;
     cout<<"Введіть автора"<<"\n"; 
     cin>>author;
     cout<<"Введіть кількість примірників"<<"\n"; 
     cin>>n;
}

void card::show ()
{   
    cout<<title<<' '<<author<<' '<<n;
}
 
int main(){
    card example;
    example.store();
    example.show();
    return 0;
};