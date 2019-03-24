struct LinkedListNode{
  int key;
  LinkedListNode *next, *previous;
  LinkedListNode(int _key): key(_key), next(NULL), previous(NULL) {};
};

class LinkedList{
private:
  LinkedListNode *first, *last;
  int capacity, size;
public:
  LinkedList(){
    size = 0; first = NULL; last = NULL;
  };
  void setCapacity(int _capacity){ capacity = _capacity;};
  bool isFull() { return capacity == size; };
  int deleteOldest();
  LinkedListNode *moveNodeToThelast(LinkedListNode*node);
  LinkedListNode *addNodeToTheEnd(int key);
};

LinkedListNode *LinkedList::addNodeToTheEnd(int key){
  LinkedListNode *newnode = new LinkedListNode(key);
  if(first == NULL) {
    first = newnode;
    last = first;
  } else {
    newnode->previous = last;
    last->next = newnode;
    last = last->next;
  }
  size++;
  return newnode;
}

int LinkedList::deleteOldest(){
  int response = first->key;
  LinkedListNode*tmp = first;
  if(first == last){
    first = NULL;
    last = NULL;
  } else if(first != NULL) {
    first->next->previous = NULL;
    first = first->next;
  }
  delete tmp;
  size--;
  return response;
}

LinkedListNode * LinkedList::moveNodeToThelast(LinkedListNode *node){
  if(node == last) {

  } else if(node == first){
    first = first->next;
    first->previous = NULL;

    last->next = node;
    node->previous = last;
    node->next = NULL;
    last = last->next;
  } else {
    node->previous->next = node->next;
    node->next->previous = node->previous;
    last->next = node;
    node->previous = last;
    node->next = NULL;
    last = last->next;
  }
  return last;
}

LinkedList linkedlist;
map<int, pair<int, LinkedListNode*>>hashmap;

LRUCache::LRUCache(int capacity) {
  linkedlist.setCapacity(capacity);
  hashmap = map<int, pair<int, LinkedListNode*>>();
}

int LRUCache::get(int key) {
  if(hashmap.find(key) != hashmap.end()){
    LinkedListNode*newnode = linkedlist.moveNodeToThelast(hashmap[key].second);
    hashmap[key].second = newnode;
    return hashmap[key].first;
  }
  else
    return -1;
}

void LRUCache::set(int key, int value) {
  if(hashmap.find(key) != hashmap.end()){
    LinkedListNode*newnode = linkedlist.moveNodeToThelast(hashmap[key].second);
    hashmap[key].second = newnode;
    hashmap[key].first = value;
  } else {
    if(linkedlist.isFull())
      hashmap.erase(hashmap.find(linkedlist.deleteOldest()));
    LinkedListNode *node = linkedlist.addNodeToTheEnd(key);
    hashmap[key] = make_pair(value, node);
  }
}
