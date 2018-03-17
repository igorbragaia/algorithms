#include<iostream>
using namespace std;

bool isSubstring(string s1, string s2){
  return true;
}

bool isRotation(string s1, string s2){
  s2 += s2;
  return isSubstring(s1, s2);
}

int main(){
  string s1 = "waterbottle";
  string s2 = "erbottlewat";

  cout << isRotation(s1, s2) << endl;

  return 0;
}
