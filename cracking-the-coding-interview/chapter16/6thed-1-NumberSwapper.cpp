#include<stdio.h>
using namespace std;

class Solution{
public:
  void swap_In_Place(int&a,int&b){
    //a,b
    b-=a;
    //a,b-a
    a+=b;
    //b,b-a
    b-=a;
    //b,-a
    b*=-1;
    //b,a
  };
};

int main(){
  int a = 12231, b = 234023;
  printf("(%d, %d)\n",a,b);
  Solution solution;
  solution.swap_In_Place(a,b);
  printf("(%d, %d)\n",a,b);

  return 0;
}
