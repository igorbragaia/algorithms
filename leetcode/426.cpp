/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return root;
        
        Node*ans = minNode(root);

        inOrderCurrentNode = NULL;
        inOrder(root);
        
        ans->left=inOrderCurrentNode;
        inOrderCurrentNode->right=ans;
        
        return ans;
    }
private:
    Node*inOrderCurrentNode;
    
    void inOrder(Node*node){
        if(node == NULL)
            return;
        
        inOrder(node->left);
        if(inOrderCurrentNode != NULL){
            node->left = inOrderCurrentNode;
            inOrderCurrentNode->right = node;    
        }
        inOrderCurrentNode = node;
        inOrder(node->right);
    }
    
    Node*minNode(Node*root){
        Node*p = root;
        while(p->left != NULL)
            p = p->left;
        return p;
    }
};