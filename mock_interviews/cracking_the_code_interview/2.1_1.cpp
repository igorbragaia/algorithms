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
  void removeDuplicates_without_buffer();
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

// solving without buffer
void LinkedList::removeDuplicates_without_buffer(){
  Node * p = head, * q;
  while(p != NULL){
    q = p;
    while(q != NULL && q->next != NULL){
      if(q->next->val == p->val){
        Node * tmp = q->next;
        q->next = q->next->next;
        delete tmp;
      } else {
        q = q->next;
      }
    }
    p = p->next;
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

  linkedlist.removeDuplicates_without_buffer();

  linkedlist.printAll();

  return 0;
}
