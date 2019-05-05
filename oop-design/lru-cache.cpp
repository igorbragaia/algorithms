/*
QUESTION: DESIGN LRU CACHE

*Clarifications:*
- who   => anywhere, shouldn't matter for your design, just keep it simple and generic
- where => in some application backend, so you could have anything inside this cache
- when  => how often queries? highly queried so should be optimal
- how   => for a simple cache, we would have just a hash map. Regarding we want to drop lest recently used elements, we
could have a queue where we can move elements (or add) to its end when queried or added
- why   => store recently used objects
- what  => design a cache that when reachs out its limit, drops least recently used elements. Operations required
are get(element) and set(element, value)

*Handle Ambiguity*
- it should be generic? so our cache could store integers, strings or any other data structure? yes
- how do we track least recently used elements? If an element is added to that cache, it goes do the end of that queue
and if an element is hitted, then move it also to the end of that queue


*Define core objects*
- In order to create a generic LRU cache, it makes sense creating initially a generic cache that should implement a
function that gives priority to elements once it is full.
- Then LRU cache would inherit from cache and implement its own priority elements selection function
- In order to implement a LRU cache, we would also need to implement a queue that support elements movements. If we had
just a queue, we could support insertion and remove operations in O(1) time complexity. In order to support moving
elements operation in O(1) as well, we could use a linked list. It would make our code a bit harder to be done but
would solve our problem on best way. This queue implemented via linked list would support all operations (push,pop,move)
in O(1) time. Memory complexity overral is O(max qty at cache)

So, we need the following classes
Classes: cache, lru cache(cache), linked list

*Analyze relationships*
How to they related to each other?
LRU cache inherits from cache. LRU cache also has a linked list as private member;
Each LRU cache has only one linked list.

- Cache:
private:
  hash map<structure,<linked list node, cached value>>
protected:
  virtual void hitElement(structure)
public:
  virtual T getElement(structure)
  virtual void addItem(structure)
  void clean cache()
  get cache size()

- LRU Cache(cache)
private:
  linked list
protected:
  void hitElement(structure)
public:
  T getElement(structure)

- Linked list
private:
  int capacity
  Node* root
  Node* removeNode(Node*node)
  void addNodeToEnd(Node*node)
public:
  void addElement(structure)
  void moveElementToEnd(Node*node) // remove node then add to end
  void isFull()

*Investigate Actions*
- When we try to get an element from cache, if it is there, we move it to the end of our queue and then
we return stored value. When we want to add a new element to our cache, if our queue is not full yet, we
add to queue. If it is full, we drop an element and then add this new one and finally we add to map.
*/

template<typename T>
class Cache{
private:
protected:
  virtual void hitElement(structure);
public:
  virtual T4 getElement(structure)
  virtual void addItem(structure)
  void clean cache()
  get cache size()

}

template<typename T>
Struct ListNode{
  T val;
  ListNode*next;
}

class LinkedList{
private:
  int capacity;

}

class LRUCache : public Cache{

}
