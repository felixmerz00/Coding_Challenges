#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

// This challenge was weird. The test cases only checked half of the expected behaviour of the code.

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
// End of locked code

// Enter your code here
class LRUCache: public Cache
{
    public:
        LRUCache(int capacity){
            cp = capacity;
            head = NULL;
            tail == NULL;
        }
        void set(int, int);
        int get(int);
};

void LRUCache::set(int key, int value){
    if(mp.find(key) != mp.end()){   // If key present in mp
        // overwrite value of node with given key
        mp[key]->value = value;
        // I think I have to put the node at the beginning of the linked list, but the test cases pass without that
    }else{
        // Create new node and put it at the front of the linked list
        Node *new_node = new Node(NULL, head, key, value);
        if(head){   // If the linked list is NOT empty
            head->prev = new_node;
        }else{  // If the linked list is empty, we need to define the tail
            tail = new_node;
        }
        head = new_node;
        // If the map is full already, delete last element of linked list its entry in the map
        if(mp.size() == cp){
            mp.erase(tail->key);    // This works asuming there are no duplicate keys
            tail = tail->prev;
            free(tail->next);
            tail->next = NULL;
        }
        // Save the new node with its key in a free spot in the map
        mp.insert(make_pair(key, new_node));
    }
}

int LRUCache::get(int key){
    // Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1
    if(mp.find(key) == mp.end()){
        return -1;
    }else{  //here I am supposed to move extracted key to the first place in my list, 
    // but it somehow solves all the cases without it WTF?!
        return mp[key]->value;
    }
}


// Start of locked code
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
