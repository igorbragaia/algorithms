#include<stdio.h>
#include<stack>


class Stack{
private:
  std::stack<int>pilha;
public:
  void push(int val);
  void pop();
  std::stack<int> sort();
};

void Stack::push(int val){
  pilha.push(val);
}

void Stack::pop(){
  if(!pilha.empty()){
    pilha.pop();
  }
}

std::stack<int> Stack::sort(){
  std::stack<int>pilha_aux;
  while(!pilha.empty()){
    int tmp = pilha.top(), tmp_aux;
    pilha.pop();
    while(!pilha_aux.empty() && pilha_aux.top() > tmp){
      tmp_aux = pilha_aux.top();
      pilha_aux.pop();
      pilha.push(tmp_aux);
    }
    pilha_aux.push(tmp);
  }
  pilha = pilha_aux;
  return pilha;
}

int main(){
  Stack stack;
  stack.push(5);
  stack.push(2);
  stack.push(10);
  stack.push(7);
  stack.push(8);
  stack.push(1);
  stack.push(3);

  std::stack<int> sorted = stack.sort();
  while(!sorted.empty()){
    printf("%d ",sorted.top());
    sorted.pop();
  }
  
  return 0;
}
