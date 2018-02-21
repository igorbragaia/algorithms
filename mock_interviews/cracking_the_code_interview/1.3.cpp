#include<iostream>
using namespace std;


// O(n²)
string removeDuplicates_without_extra_memory(string str){
    if(str == ""){
      return str;
    }
    int length = str.size(), tail = 0;
    bool found;
    for(int i = 0; i < length; i++){
      found = false;
      for(int j = 0; j < length && !found; j++){
        if(i != j && str[i] == str[j]){
          found = true;
        }
      }
      if(!found){
        str[tail++] = str[i];
      }
    }
    str[tail] = '\0';
    str.resize(tail + 1);
    return str;
}

string removeDuplicates_with_extra_memory(string str){
  if(str == ""){
    return str;
  }

  int mask[256], length = str.size();
  for(int i = 0; i < 256; i++){
    mask[i] = 0;
  }

  for(int i = 0; i < length; i++){
    mask[str[i]]++;
  }

  int tail = 0;
  for(int i = 0; i < length; i++){
    if(mask[str[i]] == 1){
      str[tail++] = str[i];
    }
  }
  str[tail++] = '\0';
  str.resize(tail);

  return str;
}


int main(){
  cout << "removeDuplicates_without_extra_memory:" << endl;
  cout << removeDuplicates_without_extra_memory("abababc") << endl;
  cout << removeDuplicates_without_extra_memory("aaa") << endl;
  cout << removeDuplicates_without_extra_memory("abc") << endl;
  cout << removeDuplicates_without_extra_memory("aabcdeef") << endl;

  cout << "removeDuplicates_with_extra_memory:" << endl;
  cout << removeDuplicates_with_extra_memory("abababc") << endl;
  cout << removeDuplicates_with_extra_memory("aaa") << endl;
  cout << removeDuplicates_with_extra_memory("abc") << endl;
  cout << removeDuplicates_with_extra_memory("aabcdeef") << endl;


  return 0;
}
