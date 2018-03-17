#include<bits/stdc++.h>
using namespace std;


bool isAnagram_sorting(string str1, string str2){
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  return str1 == str2;
}

bool isAnagram_masking(string str1, string str2){
  bool response = (str1.size() == str2.size());

  if(response){
    int mask1[256];
    int mask2[256];
    for(int i = 0; i < 256; i++){
      mask1[i] = 0;
      mask2[i] = 0;
    }
    for(int i = 0; i < str1.size(); i++){
      mask1[str1[i]]++;
      mask2[str2[i]]++;
    }
    for(int i = 0; i < 256 && response; i++){
      if(mask1[i] != mask2[i]){
        response = false;
      }
    }
  }

  return response;
}

int main(){
  printf("%d\n", isAnagram_sorting("abcd", "abdc"));
  printf("%d\n", isAnagram_sorting("abcdx", "abdc"));

  printf("%d\n", isAnagram_masking("abcd", "abdc"));
  printf("%d\n", isAnagram_masking("abcdx", "abdc"));

  return 0;
}
