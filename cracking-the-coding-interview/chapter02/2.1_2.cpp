#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;


// solving problem for simple linked list
class Node{
public:
  int val;
  Node * next;
};


class LinkedList{
private:
  Node * head, * tail;
public:
  LinkedList(){
    head = NULL;
    tail = NULL;
  }
  void printAll();
  void append(int val);
  void removeNode(Node * node);
  void removeHead();
  void removeDuplicates_with_buffer();
};

void LinkedList::append(int val){
  if(head == NULL){
    Node * node = new Node;
    node->val = val;
    node->next = NULL;
    head = node;
    tail = node;
  } else {
    Node * node = new Node;
    node->val = val;
    node->next = NULL;
    tail->next = node;
    tail = tail->next;
  }
}

// solving with buffer
void LinkedList::removeDuplicates_with_buffer(){
  set<int> nodes;
  Node * p = head;
  while(p != NULL && p->next != NULL){
    if(nodes.find(p->next->val) != nodes.end()){
      Node * tmp = p->next;
      p->next = p->next->next;
      delete tmp;
    } else {
      nodes.insert(p->next->val);
      p = p->next;
    }
  }
}

void LinkedList::printAll(){
  Node * p = head;
  while(p != NULL){
    printf("%3d ", p->val);
    p = p->next;
  }
  printf("\n");
}


int main(){
  LinkedList linkedlist;

  linkedlist.append(12);
  linkedlist.append(12);
  linkedlist.append(1);
  linkedlist.append(15);
  linkedlist.append(12);
  linkedlist.append(13);
  linkedlist.append(2);
  linkedlist.append(1);
  linkedlist.append(9);
  linkedlist.append(10);
  linkedlist.append(9);
  linkedlist.append(9);

  linkedlist.printAll();

  linkedlist.removeDuplicates_with_buffer();

  linkedlist.printAll();

  return 0;
}
