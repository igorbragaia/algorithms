#include<stdio.h>
using namespace std;


class Node{
public:
  int val;
  Node * next;
};


class Queue{
private:
  Node * head, * tail;
public:
  Queue(){
    head = NULL;
    tail = NULL;
  }
  void printAll();
  void push(int val);
  Node * pop();
  bool isEmpty();
};

void Queue::printAll(){
  printf("Printing: ");
  Node * p = head;
  while(p != NULL){
    printf("%3d ", p->val);
    p = p->next;
  }
  printf("\n");
}

void Queue::push(int val){
  Node * node = new Node;
  node->val = val;
  node->next = NULL;
  if(head == NULL){
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = tail->next;
  }
}

Node * Queue::pop(){
  if(head == NULL){
    return NULL;
  } else {
    Node * front = head;
    head = head->next;
    return front;
  }
}

bool Queue::isEmpty(){
  return (head == NULL);
}

int main(){
  Queue queue;
  queue.push(1);
  queue.push(5);
  queue.push(3);
  queue.push(7);
  queue.push(10);

  queue.printAll();

  queue.pop();
  queue.pop();
  printf("Is empty? %d\n", queue.isEmpty());

  queue.printAll();

  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  queue.pop();
  printf("Is empty? %d\n", queue.isEmpty());

  queue.printAll();

  return 0;
}
