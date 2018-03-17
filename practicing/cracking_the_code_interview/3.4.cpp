#include<stdio.h>
#include<stack>
using namespace std;


class Hanoi{
private:
  stack<int> rod[4];
  int movements, n_max, dp[20][4][4];
public:
  Hanoi(int n_max){
    this->n_max = n_max;
    for(int i = n_max; i > 0; i--){
      rod[1].push(i);
    }
  }
  void move();
  void move_towers(int n, int from, int through, int to);
};

void Hanoi::move(){
  movements = 0;
  move_towers(n_max, 1, 2, 3);
  printf("\ntotal of %d movements\n", movements);
}

void Hanoi::move_towers(int n, int from, int through, int to){
  if(n != 0){
    move_towers(n - 1, from, to, through);
    printf("moving %d from %d-nth rod to %d-nth rod\n", n, from, to);
    movements++;
    move_towers(n - 1, through, from, to);
  }
}

int main(){
  int n = 10;
  Hanoi hanoi(n);
  hanoi.move();
  return 0;
}
