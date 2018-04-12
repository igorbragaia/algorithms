#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  void sortArray(vector<string>&array){
    sort(array.begin(), array.end(), compare);
  }
private:
  static bool compare(string&aa, string&bb){
    string a = aa, b = bb;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a < b;
  }
};


class Solution2{
public:
  void sortArray(vector<string>&array){
    unordered_map<string,vector<string>> hashmap;
    string sortedstr;
    for(string str:array){
      sortedstr = str;
      sort(sortedstr.begin(), sortedstr.end());
      if(hashmap.find(sortedstr) == hashmap.end()){
        hashmap[sortedstr] = {str};
      } else {
        hashmap[sortedstr].push_back(str);
      }
    }
    vector<string>answer;
    for(unordered_map<string,vector<string>>::iterator it = hashmap.begin(); it != hashmap.end(); it++){
      for(string el:it->second){
        answer.push_back(el);
      }
    }
    array = answer;
  }
};

int main(){
  // Extra space solution
  vector<string> array;
  array.push_back("abc");
  array.push_back("addc");
  array.push_back("acb");
  array.push_back("aasdf");
  array.push_back("dadc");
  array.push_back("cab");
  Solution solution;
  solution.sortArray(array);
  for(string el:array){
    cout << el << " ";
  }
  cout << endl;
  // No extra space solution
  array.clear();
  array.push_back("abc");
  array.push_back("addc");
  array.push_back("acb");
  array.push_back("aasdf");
  array.push_back("dadc");
  array.push_back("cab");
  Solution2 solution2;
  solution2.sortArray(array);
  for(string el:array){
    cout << el << " ";
  }
  cout << endl;
  return 0;
}
