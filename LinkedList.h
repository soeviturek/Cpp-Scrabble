
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   bool add();
   bool del();
   bool get(int i);
   bool contains(Tile tile);
   bool modify();
   void clear();

private:
   Node* head;

   Node* tail;
};

#endif // ASSIGN2_LINKEDLIST_H
