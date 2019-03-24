struct LinkedListNode {
  int key;
  LinkedListNode*next,*previuos;
  LinkedListNode(int _key, LinkedListNode*_previous, LinkedListNode*_next) key(_key), previuos(_previous), next(_next) {};
};

struct HashNode {
  int key, value;
  LinkedListNode*node;
  HashNode(int _key, int _value, LinkedListNode*_node) key(_key), value(_value), node(_node) {};
}

class LinkedList {
  private LinkedListNode*begin,*end;
  public int maxsize,size;

  LinkedList(int _size){
    begin = NULL;
    end = NULL;
    maxsize = _size;
    size = 0;
  }

  public LinkedListNode addKeyToEnd(int key){
    LinkedListNode*node(key,NULL,NULL);
    if(begin == NULL){
      begin = end = node;
    } else {
      node->previous = end;
      end->next = node;
      end = node;  
    }
    size++;
    return node;
  }

  public int deleteOldest(){
    int oldest = begin->key;
    deleteNode(begin);
    return oldest;
  }

  public void deleteNode(LinkedListNode*node){
    LinkedListNode*tmp = node;
    if(node == begin){
      begin = begin->next;
    } else {
      node->previous->next = node->next;
      node->next->previous = node->previous;
    }
    delete tmp;
    size--;
  }

  public void moveNodeToEnd(LinkedListNode*node){
      addNodeToEnd(node->key);
      deleteNode(node);
  }
};

map<int,HashNode*>LRUhash;
LinkedList linkedlist;
int oldest;

LRUCache::LRUCache(int capacity) {
    LRUhash = map<int, HashNode*>();
    linkedlist = LinkedList(capacity);
}

int LRUCache::get(int key) {
    if(LRUmap.find(key) != LRUmap.end())
        return LRUmap[key]->value;
    else
        return -1;
}

void LRUCache::set(int key, int value) {
    if(LRUmap.find(key) != LRUmap.end()){
      LRUmap[key]->value = value;
      linkedlist.moveNodeToEnd(LRUmap[key]);
    } else {
      if(linkedlist.size == linkedlist.maxsize)
        LRUmap.erase(LRUmap.find(linkedlist.deleteOldest()));
      LinkedListNode*node = inkedlist.addKeyToEnd(key);
      HashNode *hashnode(key, value, node);
      LRUmap[key] = hashnode;
    }
}
