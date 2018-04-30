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
  LinkedList(){
    head = NULL;
    tail = NULL;
  }
  LinkedList(int num){
    head = NULL;
    tail = NULL;
    makeList(num);
  }
  Node * get_head(){
    return head;
  }
  Node * get_tail(){
    return tail;
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
  if(num == 0){
    append(0);
  } else {
    int current;
    while(num != 0){
      current = num%10;
      num /= 10;
      append(current);
    }
  }
}


int main(){
  int x = 513, y = 295;
  LinkedList linkedlist1(x);
  linkedlist1.printAll();

  LinkedList linkedlist2(y);
  linkedlist2.printAll();

  LinkedList answer;
  Node * p1 = linkedlist1.get_head();
  Node * p2 = linkedlist2.get_head();

  int plus = 0, sum;
  while(p1 != NULL || p2 != NULL){
    sum = (p1 != NULL ? p1->val : 0) + (p2 != NULL ? p2->val : 0) + plus;
    plus = sum > 9 ? sum - 9 : 0;
    sum %= 10;
    answer.append(sum);
    if(p1 != NULL){
      p1 = p1->next;
    }
    if(p2 != NULL){
      p2 = p2->next;
    }
  }

  answer.printAll();

  return 0;
}
