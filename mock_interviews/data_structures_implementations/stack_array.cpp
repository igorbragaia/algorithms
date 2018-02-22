#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 500

class Stack{
private:
  int top;
public:
  int a[MAX];
  Stack(){
    top = -1;
  }
  void printAll();
  bool push(int x);
  int pop();
  bool isEmpty();
};

void Stack::printAll(){
  printf("Printing:");
  for(int i = 0; i <= top; i++){
    printf("%3d ", a[i]);
  }
  printf("\n");
}

bool Stack::push(int x){
  if(top >= MAX){
    cout << "Stack overflow" << endl;
    return false;
  } else {
    a[++top] = x;
    return true;
  }
}

int Stack::pop(){
  if(top < 0){
    return 0;
  } else {
    int x = a[top--];
    return x;
  }
}

bool Stack::isEmpty(){
  return (top < 0);
}

int main(){
  Stack stack;

  stack.push(1);
  stack.push(3);
  stack.push(5);

  stack.printAll();

  stack.pop();

  stack.printAll();

  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();

  stack.printAll();

  return 0;
}
