#include<stdio.h>
using namespace std;


class Node{
public:
  int val;
  Node * next, * prev;
};


class Stack{
private:
  Node * head, * tail;
public:
  Stack(){
    head = NULL;
    tail = NULL;
  }
  void printAll();
  void push(int val);
  Node * pop();
  bool isEmpty();
};

void Stack::printAll(){
  printf("Printing: ");
  Node * p = head;
  while(p != NULL){
    printf("%3d ", p->val);
    p = p->next;
  }
  printf("\n");
}

void Stack::push(int val){
  Node * node = new Node;
  node->val = val;
  node->next = NULL;
  if(head == NULL){
    node->prev = NULL;
    head = node;
    tail = node;
  } else {
    tail->next = node;
    node->prev = tail;
    tail = tail->next;
  }
}

Node * Stack::pop(){
  if(tail == NULL){
    return NULL;
  } else {
    if(head != tail){
      Node * top = tail;
      tail = tail->prev;
      tail->next = NULL;
      return top;
    } else {
      Node * top = tail;
      head = NULL;
      tail = NULL;
      return top;
    }
  }
}

bool Stack::isEmpty(){
  return (head == NULL);
}


int main(){
  Stack stack;
  stack.push(1);
  stack.push(5);
  stack.push(3);
  stack.push(7);
  stack.push(10);

  stack.printAll();
  printf("Is empty? %d\n", stack.isEmpty());

  stack.pop();
  stack.pop();

  stack.printAll();

  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();

  stack.printAll();
  printf("Is empty? %d\n", stack.isEmpty());
  return 0;
}
