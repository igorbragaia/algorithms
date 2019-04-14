#include<bits/stdc++.h>
#include<tuple>
using namespace std;

int main(){
  tuple<int,string,float> test(1,"sdfd",0.123);

  cout << get<0>(test) << endl;
  cout << get<1>(test) << endl;
  cout << get<2>(test) << endl;
  return 0;
}
