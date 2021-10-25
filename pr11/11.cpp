#include<iostream>
#include<exception>
#include<cstdlib>
using namespace std;

void my_unexpected() {
  cerr << "call unexpect" << endl;
}

void my_terminate() noexcept {
  cout << "call terminate" << endl;
  abort();
}

void func() throw(char) {
  throw 0;
}

int main() {
  set_unexpected(my_unexpected);
  set_terminate(my_terminate);
  try {
    func();
  }
  catch (int) {
    
  }
  return 0;
}

