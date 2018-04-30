#include<stdio.h>
#include<stack>
#include<queue>


class Queue{
private:
  std::stack<int> pilha;
  std::stack<int> pilha_aux;
public:
  void push(int val);
  int pop();
};

void Queue::push(int val){
  int top;
  while(!pilha.empty()){
    top = pilha.top();
    pilha.pop();
    pilha_aux.push(top);
  }
  pilha.push(val);
  while(!pilha_aux.empty()){
    top = pilha_aux.top();
    pilha_aux.pop();
    pilha.push(top);
  }
}

int Queue::pop(){
  if(pilha.empty()){
    return -666;
  } else {
    int top = pilha.top();
    pilha.pop();
    return top;
  }
}

int main(){
  Queue pilha;
  pilha.push(1);
  pilha.push(8);
  pilha.push(2);

  printf("%d\n", pilha.pop());
  printf("%d\n", pilha.pop());
  printf("%d\n", pilha.pop());
  printf("%d\n", pilha.pop());

  return 0;
}
