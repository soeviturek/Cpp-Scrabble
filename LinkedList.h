
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);
   
   bool add_back(Tile* tile);
   bool add_front(Tile* tile);
   bool remove(int index);
   bool remove_front();
   bool remove_back();
   Tile* get(int index);
   bool contains(Tile* tile);
   bool modify();
   void clear();
   int getSize();
   bool empty();

private:
   Node* head;
   Node* next;
   Node* tail;
   int size;
};

#endif // ASSIGN2_LINKEDLIST_H
