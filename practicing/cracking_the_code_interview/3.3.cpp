#include<stdio.h>
#define MAX 10000


class SetOfStacks{
private:
  int top[MAX], n;
  int threshold;
public:
  SetOfStacks(){
    this->threshold = 5;
    this->n = 1;
    this->top[1] = -1;
  }
  int a[MAX];
  void push(int val);
  int pop();
  void popAt(int index);
  void pushAt(int val, int index);
  void printAll();
};

void SetOfStacks::printAll(){
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

void SetOfStacks::push(int val){
  if(top[n] - top[n - 1] >= threshold){
     n++;
     top[n] = top[n - 1];
  }
  int stack = n;
  for(int i = top[n] + 1; i > top[stack] + 1; i--){
    a[i] = a[i - 1];
  }
  a[++top[stack]] = val;
  for(int i = stack + 1; i <=n ; i++){
    top[i]++;
  }
}

int SetOfStacks::pop(){
  if(top[1] == -1){
    return 0;
  } else {
    if(top[n] - top[n - 1] < 0){
       n--;
    }

    int stack = n;

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

void SetOfStacks::pushAt(int val, int index){
  int stack = index;
  for(int i = top[n] + 1; i > top[stack] + 1; i--){
    a[i] = a[i - 1];
  }
  a[++top[stack]] = val;
  for(int i = stack + 1; i <=n ; i++){
    top[i]++;
  }
}

void SetOfStacks::popAt(int index){
  if(top[index] != -1){
    if(top[index] - top[index - 1] == 1){
      n--;
    }

    int stack = index;

    int pop = a[top[stack]];
    for(int i = top[stack]; i < top[n]; i++){
      a[i] = a[i + 1];
    }
    for(int i = stack; i <= n; i++){
      top[i]--;
    }

    if(top[index + 1] - top[index] > 0){
      pushAt(a[top[index + 1]], index);
      popAt(index + 1);
    }
  }
}

int main(){
  SetOfStacks setofstacks;
  for(int i = 1; i<= 23; i++){
    setofstacks.push(i);
  }

  setofstacks.printAll();

  for(int i = 1; i<= 6; i++){
    setofstacks.pop();
  }

  setofstacks.printAll();

  for(int i = 1; i<= 50; i++){
    setofstacks.pop();
  }

  setofstacks.printAll();

  for(int i = 30; i<= 80; i++){
    setofstacks.push(i);
  }

  setofstacks.printAll();

  printf("Popping in specific positions: \n");

  setofstacks.popAt(1);
  setofstacks.popAt(2);

  setofstacks.printAll();

  return 0;
}
