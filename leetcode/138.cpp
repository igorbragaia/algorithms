/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
 
        Node*p=head,*q,*tmp;
        while(p!=nullptr){
            tmp=p->next;
            p->next = new Node(p->val);
            p->next->next=tmp;
            p=tmp;
        }
        
        p=head;
        while(p!=nullptr){
            if(p->random==nullptr)
                p->next->random=nullptr;
            else
                p->next->random=p->random->next;
            p=p->next->next;
        }
        
        p=head;
        q=p->next;
        while(p!=nullptr){
            tmp=p->next->next;
            if(tmp==nullptr){
                p->next=nullptr;
            } else {
                p->next->next=p->next->next->next;
            }
            
            p->next = tmp;
            p = p->next;
        }
        
        return q;
    }
};