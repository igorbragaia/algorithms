#include<stdio.h>
#include<iostream>
using namespace std;

class Node{
public:
  int val;
  Node *next, *prev;
};

class LinkedList{
private:
  Node *head, *tail;
public:
  LinkedList(){
    head = NULL;
    tail = NULL;
  }
  void printAll();
  void pop_front();
  void pop_back();
  void append(int val);
};

void LinkedList::printAll(){
  Node * p = head;
  while(p != NULL){
    printf("%3d ", p->val);
    p = p->next;
  }
  printf("\n");
}

void LinkedList::append(int val){
  if(head == NULL){
    Node * node = new Node;
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    head = node;
    tail = node;
  } else {
    Node * node = new Node;
    node->next = NULL;
    node->prev = tail;
    node->val = val;
    tail->next = node;
    tail = tail->next;
  }
}

void LinkedList::pop_front(){
  if(tail == head){
    Node * tmp = tail;
    tail = NULL;
    head = NULL;
    delete tmp;
  } else {
    Node * tmp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete tmp;
  }
}

void LinkedList::pop_back(){
  if(tail == head){
    Node * tmp = tail;
    tail = NULL;
    head = NULL;
    delete tmp;
  } else {
    Node * tmp = head;
    head = head->next;
    head->prev = NULL;
    delete tmp;
  }
}

int main(){
  LinkedList linkedlist;

  linkedlist.append(8);
  linkedlist.append(90);
  linkedlist.append(2);

  linkedlist.printAll();

  linkedlist.pop_back();
  linkedlist.pop_front();

  linkedlist.printAll();

  return 0;
}
