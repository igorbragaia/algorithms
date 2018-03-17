#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include<utility>


class Stack{
private:
  std::stack<std::pair<int, int> > pilha;
public:
  bool isEmpty();
  void push(int val);
  int pop();
  int min();
};

void Stack::push(int val){
  std::pair<int,int> node = std::make_pair(val, val);

  if(!pilha.empty() && val > pilha.top().second){
    node.second = pilha.top().second;
  }

  pilha.push(node);
}

int Stack::pop(){
  std::pair<int,int> top = pilha.top();
  pilha.pop();
  return top.first;
}

int Stack::min(){
  return pilha.top().second;
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

  return 0;
}
