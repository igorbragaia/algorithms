#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;


// with extra memory in O(n)
bool unique_char_verifying(string str){
  bool alphabet[256];
  memset(alphabet, false, 256);
  bool response = true;
  for(int i = 0; i< str.size() && response; i++){
    if(alphabet[str[i]]){
      response = false;
    } else{
      alphabet[str[i]] = true;
    }
  }
  return response;
}

// with less extra memory in O(n)
bool unique_char_verifying_with_less_memory(string str){
  int checker = 0;
  bool response = true;
  for(int i = 0; i< str.size() && response; i++){
    if(checker & (i << (int) str[i])){
      response = false;
    } else{
      checker |= (i << (int) str[i]);
    }
  }
  return response;
}

// with neighboring checking after sorting O(nlogn), where n is str.size()
bool unique_char_verifying_through_neighboring_checking(string str){
  sort(str.begin(), str.end());
  bool response = true;
  for(int i = 1; i < str.size() && response; i++){
    if(str[i - 1] == str[i]){
      response = false;
    }
  }
  return response;
}


int main(){
  string str;

  str = "papilo$$sc*opista";
  cout << str << " " << unique_char_verifying(str) << endl;
  str = "ig(@or";
  cout << str << " " << unique_char_verifying(str) << endl;

  str = "papilo$$sc*opista";
  cout << str << " " << unique_char_verifying_with_less_memory(str) << endl;
  str = "ig(@or";
  cout << str << " " << unique_char_verifying_with_less_memory(str) << endl;

  str = "papilo$$sc*opista";
  cout << str << " " << unique_char_verifying_through_neighboring_checking(str) << endl;
  str = "ig(@or";
  cout << str << " " << unique_char_verifying_through_neighboring_checking(str) << endl;

  return 0;
}
