#include<iostream>
using namespace std;

union bits {
    int n;
    unsigned char cval[sizeof(int)]; //cval[4]
};

void print(unsigned char u);

int main() {
    bits u;
    char tmp;
    u.n = 12; //00000000 00000000 00000000 00001100
    for (int j = sizeof(int) - 1; j >= 0; j--) {
        print(u.cval[j]);
        cout << " ";
    }
    tmp = u.cval[0];
    u.cval[0] = u.cval[sizeof(int) - 1];
    u.cval[sizeof(int) - 1] = tmp;
    cout << "\n";
    for (int j = sizeof(int) - 1; j >= 0; j--) {
        print(u.cval[j]);
        cout << " ";

    }
    return 0;
}

void print(unsigned char u) {
    for (int i = 128; i; i = i / 2) {
        if (i & u)
            cout << "1";
        else
            cout << "0";
    }
}
