#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
//https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem

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


class LRUCache: public Cache {
    private:
        int current_fill;
    public:
        LRUCache(int capacity): current_fill(0) {
            cp = capacity;
            head = new Node(NULL, NULL, -1, -1);
            tail = new Node(NULL, NULL, -1, -1);
            head->next = tail;
            tail->prev = head;
        }
        ~LRUCache() {
            //Delete nodes in LL
            Node* del_node;
            while (head->next != tail) {
                del_node = head->next;
                head->next = del_node->next;
                del_node->next->prev = head;
                delete del_node;
            }
            delete head;
            delete tail;
        }
        void set(int set_key, int val) {
            if (mp.find(set_key) != mp.end()) {
                //cache hit
                mp[set_key]->value = val;
                mp[set_key]->prev->next = mp[set_key]->next;
                mp[set_key]->next->prev = mp[set_key]->prev;
                head->next->prev = mp[set_key];
                mp[set_key]->next = head->next;
                head->next = mp[set_key];
                mp[set_key]->prev = head;
                return;
            }
            // otherwise Cache miss
            // Key isn't in cache, cache isn't full
            if (current_fill < cp) {
                // Add key to front of cache, add <key,Node> to map
                // Create node
                Node* new_node = new Node(set_key, val);
                new_node->prev = head;
                new_node->next = head->next;
                head->next->prev = new_node;
                head->next = new_node;
                mp.insert(pair<int, Node*>(set_key, new_node));
                ++current_fill;
                return;
            } else {
                // Cache full, remove last element from map, transition it to new val
                // Move to front of cache
                Node* temp_node = tail->prev;
                mp.erase(temp_node->key);
                temp_node->key = set_key;
                temp_node->value = val;
                tail->prev = temp_node->prev;
                temp_node->prev->next = tail;
                temp_node->prev = head;
                temp_node->next = head->next;
                temp_node->next->prev = temp_node;
                head->next = temp_node;
                mp.insert(pair<int, Node*>(set_key, temp_node));
                return;
            }
        }
        int get(int get_key) {
            if (mp.find(get_key) != mp.end()) {
                //cache hit, move up node and return value
                mp[get_key]->next->prev = mp[get_key]->prev;
                mp[get_key]->prev->next = mp[get_key]->next;
                head->next->prev = mp[get_key];
                mp[get_key]->next = head->next;
                head->next = mp[get_key];
                mp[get_key]->prev = head;
                return mp[get_key]->value;
            }
            else return -1;
        }
};

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
