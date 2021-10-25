#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream in("file.txt", ios::in | ios::binary);
    string st1, st2;
    while (!in.eof()) {
        getline(in, st1);
        for (int i = st1.length(); i >= 0; i--){
            st2 += st1[i];
        }
        cout << st2 << endl;
    }
    in.close();
    return 0;
}


