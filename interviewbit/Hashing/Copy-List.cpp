/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A==NULL)
      return NULL;
    map<RandomListNode*,RandomListNode*>hashmap;
    RandomListNode*newA=new RandomListNode(A->label);
    RandomListNode*iteratorA=A;
    RandomListNode*iteratorNewA=newA;
    hashmap[iteratorA]=iteratorNewA;

    while(iteratorA->next!=NULL){
      iteratorNewA->next=new RandomListNode(iteratorA->next->label);
      hashmap[iteratorA->next]=iteratorNewA->next;
      iteratorA=iteratorA->next;
      iteratorNewA=iteratorNewA->next;
    }
    iteratorA=A;
    iteratorNewA=newA;
    while(iteratorA!=NULL){
      iteratorNewA->random=hashmap[iteratorA->random];
      iteratorA=iteratorA->next;
      iteratorNewA=iteratorNewA->next;
    }
    return newA;
}
