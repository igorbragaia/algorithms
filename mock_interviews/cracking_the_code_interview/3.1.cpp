#include<stdio.h>
#define MAX 500
#define threshold -1


class TripleStack{
private:
  int top[5];
public:
  TripleStack(){
    top[0] = threshold;
    top[1] = -1;
    top[2] = -1;
    top[3] = -1;
  }
  int a[MAX];
  void push(int val, int stack);
  int pop(int stack);
  void printAll();
};

void TripleStack::printAll(){
  for(int k = 1; k <= 3; k++){
    printf("top[%d]: %d, top[%d] = %d => ", k-1, top[k-1], k, top[k]);
    printf("Printing stack %d: ", k);
    for(int i = top[k - 1] + 1; i <= top[k]; i++){
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  printf("\n");
}

void TripleStack::push(int val, int stack){
  switch (stack) {
    case 1:
      for(int i = top[3] + 1; i > top[1] + 1; i--){
        a[i] = a[i - 1];
      }
      a[++top[1]] = val;
      top[2]++;
      top[3]++;
      break;
    case 2:
      for(int i = top[3] + 1; i > top[2] + 1; i--){
        a[i] = a[i - 1];
      }
      a[++top[2]] = val;
      top[3]++;
      break;
    case 3:
      a[++top[3]] = val;
      break;
  }
}

int TripleStack::pop(int stack){
  switch (stack) {
    case 1:
      if(top[1] == -1){
        return 0;
      } else {
        int pop = a[top[1]];
        for(int i = top[1]; i < top[3]; i++){
          a[i] = a[i + 1];
        }
        top[1]--;
        top[2]--;
        top[3]--;
        return pop;
      }
    case 2:
      if(top[2] == -1){
        return 0;
      } else {
        int pop = a[top[2]];
        for(int i = top[2]; i < top[3]; i++){
          a[i] = a[i + 1];
        }
        top[2]--;
        top[3]--;
        return pop;
      }
    case 3:
      if(top[3] == -1){
        top[3]--;
      } else {
        int pop = a[top[3]];
        top[3]--;
        return pop;
      }
  }
}

int main(){
  TripleStack triplestack;
  triplestack.push(1, 1);
  triplestack.push(2, 2);
  triplestack.push(3, 3);
  triplestack.push(10, 1);
  triplestack.push(20, 2);
  triplestack.push(30, 3);

  triplestack.printAll();

  triplestack.pop(1);
  triplestack.pop(1);
  triplestack.pop(1);
  triplestack.pop(2);
  triplestack.push(10, 1);
  triplestack.push(20, 2);
  triplestack.push(30, 3);

  triplestack.printAll();

  return 0;
}
