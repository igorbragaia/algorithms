#include<stdio.h>
#define MAX 10000
#define threshold -1


class NStacks{
private:
  int n, top[MAX];
public:
  NStacks(int n){
    this->n = n;
    top[0] = threshold;
    for(int i = 0; i <= n; i++){
      top[i] = -1;
    }
  }
  int a[MAX];
  void push(int val, int stack);
  int pop(int stack);
  void printAll();
};

void NStacks::printAll(){
  for(int k = 1; k <= n; k++){
    printf("top[%d]: %d, top[%d] = %d => ", k-1, top[k-1], k, top[k]);
    printf("Printing stack %d: ", k);
    for(int i = top[k - 1] + 1; i <= top[k]; i++){
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  printf("\n");
}

void NStacks::push(int val, int stack){
  for(int i = top[n] + 1; i > top[stack] + 1; i--){
    a[i] = a[i - 1];
  }
  a[++top[stack]] = val;
  for(int i = stack + 1; i <=n ; i++){
    top[i]++;
  }
}

int NStacks::pop(int stack){
  if(top[stack] == -1){
    return 0;
  } else {
    int pop = a[top[stack]];
    for(int i = top[stack]; i < top[n]; i++){
      a[i] = a[i + 1];
    }
    for(int i = stack; i <= n; i++){
      top[i]--;
    }
    return pop;
  }
}

int main(){
  NStacks sixstacks(6);
  sixstacks.push(94, 4);
  sixstacks.push(95, 5);
  sixstacks.push(1, 1);
  sixstacks.push(2, 2);
  sixstacks.push(3, 3);
  sixstacks.push(10, 1);
  sixstacks.push(20, 2);
  sixstacks.push(30, 3);

  sixstacks.printAll();
  sixstacks.push(56,6);
  sixstacks.pop(5);

  sixstacks.pop(1);
  sixstacks.pop(1);
  sixstacks.pop(1);
  sixstacks.pop(2);
  sixstacks.push(10, 1);
  sixstacks.push(20, 2);
  sixstacks.push(30, 3);
  sixstacks.push(30, 6);
  sixstacks.pop(1);
  sixstacks.pop(1);

  sixstacks.printAll();

  return 0;
}
