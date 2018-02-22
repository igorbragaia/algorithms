#include<stdio.h>
using namespace std;

class Node{
public:
  int val;
  Node * next;
};

class LinkedList{
private:
  Node * head, * tail;
public:
  LinkedList(int num){
    head = NULL;
    tail = NULL;
    makeList(num);
  }
  void append(int num);
  void makeList(int num);
  void printAll();
};

void LinkedList::printAll(){
  Node * p = head;
  while(p != NULL){
    printf("%3d -> ", p->val);
    p = p->next;
  }
  printf("\n");
}

void LinkedList::append(int num){
  if(head == NULL){
    Node * node = new Node;
    node->val = num;
    node->next = NULL;
    tail = node;
    head = node;
  } else {
    Node * node = new Node;
    node->val = num;
    node->next = NULL;
    tail->next = node;
    tail = tail->next;
  }
}

void LinkedList::makeList(int num){
  int current;
  while(num != 0){
    current = num%10;
    num /= 10;
    append(current);
  }
}


int main(){
  int x = 513, y = 295;
  LinkedList linkedlist1(x);
  linkedlist1.printAll();

  LinkedList linkedlist2(y);
  linkedlist2.printAll();
  return 0;
}
