#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stack>


class Stack{
private:
  std::stack<int> pilha;
  std::stack<int> pilha_min;
public:
  void push(int val);
  int pop();
  int min();
};

void Stack::push(int val){
  pilha.push(val);

  if(pilha_min.empty() || val <= pilha_min.top()){
    pilha_min.push(val);
  }
}

int Stack::pop(){
  if(pilha.empty()){
    return 0;
  } else {
    int top = pilha.top();
    pilha.pop();
    if(pilha_min.top() == top){
      pilha_min.pop();
    }
    return top;
  }
}

int Stack::min(){
  return pilha_min.top();
}

int main(){
  int current_min, val;
  Stack pilha;

  srand (time(NULL));
  for(int i = 0; i < 10; i++){
    val = rand() % 10 + 1;
    printf("%3d ", val);

    pilha.push(val);
  }

  printf("\n");

  printf("mínimo = %d\n", pilha.min());

  pilha.pop();
  pilha.pop();
  pilha.pop();
  pilha.pop();
  pilha.pop();
  pilha.pop();

  printf("mínimo = %d\n", pilha.min());

  return 0;
}
