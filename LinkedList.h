
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   LinkedList(LinkedList& other);
   
   bool addBack(Tile* tile);
   bool addFront(Tile* tile);
   bool remove(int index);
   bool removeFront();
   bool removeBack();
   Tile* get(int index);
   bool contains(Tile* tile);
   int getIndex(Tile* tile);
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
