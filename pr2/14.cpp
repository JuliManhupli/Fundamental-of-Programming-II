#include<iostream>
#include<ctime>
using namespace std;

class timer{
  double start1,end1,start2,end2;
public:
  timer();
  ~timer();
  void start();
  void stop();
  void show();
};

timer::timer(){
  start1=time(0);
}

timer::~timer(){
  cout<<"Destructing...\n";
  end1=time(0);
  cout<<"Elapsed time: "<<(end1-start1)<<"\n";
}
  
void timer::start(){
  start2 = time(0);
}

void timer::stop(){
  end2= time(0);
}

void timer::show(){
  cout<<"Time: "<<(end2-start2);
  cout<<"\n";
}


int main(){
  timer ob;
  int c;
  ob.start();
    cout<<"Stopwatch started, type 0 to stop\n";
    cin>>c;
    if (c==0){
      ob.stop();
    }
  ob.show();
  cout<<"Press a key followed by ENTER: ";
  cin>>c;
  return 0;
}