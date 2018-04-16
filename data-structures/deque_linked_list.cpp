#include<stdio.h>
using namespace std;


class Node{
public:
  int val;
  Node * next, * prev;
};


class Deque{
private:
  Node * head, * tail;
public:
  Deque(){
    head = NULL;
    tail = NULL;
  }
  void printAll();
  void push_back(int val);
  void push_front(int val);
  Node * pop_back();
  Node * pop_front();
  bool isEmpty();
};

void Deque::printAll(){
  printf("Printing: ");
  Node * p = head;
  while(p != NULL){
    printf("%3d ", p->val);
    p = p->next;
  }
  printf("\n");
}

void Deque::push_back(int val){
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

void Deque::push_front(int val){
  Node * node = new Node;
  node->val = val;
  node->prev = NULL;
  if(head == NULL){
    node->next = NULL;
    head = node;
    tail = node;
  } else {
    node->next = head;
    head->prev = node;
    head = head->prev;
  }
}

Node * Deque::pop_back(){
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

Node * Deque::pop_front(){
  if(head == NULL){
    return NULL;
  } else {
    if(head != tail){
      Node * front = head;
      head = head->next;
      head->prev = NULL;
      return front;
    } else {
      Node * front = head;
      head = NULL;
      tail = NULL;
      return front;
    }
  }
}

bool Deque::isEmpty(){
  return (head == NULL);
}


int main(){
  Deque deque;
  
  deque.push_back(1);
  deque.push_back(5);
  deque.push_back(3);
  deque.push_front(7);
  deque.push_front(10);

  deque.printAll();
  printf("Is empty? %d\n", deque.isEmpty());

  deque.pop_back();
  deque.pop_front();

  deque.printAll();

  printf("Is empty? %d\n", deque.isEmpty());

  return 0;
}
