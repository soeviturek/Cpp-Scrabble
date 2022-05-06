
#include "LinkedList.h"

LinkedList::LinkedList()
{
   head = nullptr;
   tail = nullptr;
}

LinkedList::~LinkedList()
{
   clear();
}

LinkedList::LinkedList(LinkedList &other)
{
   head = nullptr;
   for(int i = 0; i < other.getSize(); ++i){
        Tile* tile = new Tile(*other.get(i));
        addBack(tile);
    }
}
bool LinkedList::addFront(Tile *tile)
{
   Node *node = new Node(tile, head);
   head = node;
   tail = head;
   size++;
   return true;
}
bool LinkedList::addBack(Tile *tile)
{
   Node *node = new Node(tile, nullptr);
   if (head == nullptr)
   {
      head = node;
      tail = node;
   }
   else
   {
      Node *current = head;
      while (current->next != nullptr)
      {
         current = current->next;
      }
      current->next = node;
      tail = node;
   }
   size++;
   return true;
}

bool LinkedList::remove(int index)
{
   bool check = false;
   if (index == 0)
   {
      check = removeFront();
   }
   else if (index == size)
   {
      check = removeBack();
   }
   else if (index > 0 && index < size)
   {
      if (head != nullptr)
      {
         int counter = 0;
         Node *current = head;
         // pre should point to node before current;
         Node *prev = nullptr;

         // move current to the index and prev to the one before index
         while (counter != index)
         {
            ++counter;
            prev = current;
            current = current->next;
         }

         // if(prev == nullptr){
         //     head = current->next;
         // }else{
         //     prev->next = current->next;
         // }
         prev->next = current->next;
         current->next = nullptr;
         delete current->tile;
         delete current;
         check = true;
         size--;
      }
   }
   return check;
}
/*
 * checks if the node is empty, if yes, return false, else remove the first node
 */
bool LinkedList::removeFront()
{
   bool check = true;
   if (head != nullptr)
   {
      Node *node = head;
      head = head->next;
      delete node->tile;
      delete node;
      size--;
   }
   else
   {
      check = false;
   }
   //  else{
   //      throw std::runtime_error("Nothing to remove");
   //  }
   return check;
}
bool LinkedList::removeBack()
{
   bool check = false;
   if (head != nullptr)
   {
      Node *current = head;
      Node *prev = nullptr;
      if (tail == head)
      {
         head = nullptr;
         check = true;
         size--;
      }
      else
      {
         while (current->next != nullptr)
         {
            prev = current;
            current = current->next;
         }
         prev->next = nullptr;
         tail = prev;
         check = true;
         size--;
      }
      delete current->tile;
      delete current;
      size--;
   }
   return check;
}
Tile *LinkedList::get(int index)
{
   Tile *nodeTile = nullptr;
   if (index >= 0 && index < size)
   {
      int counter = 0;
      Node *current = head;

      while (counter < index)
      {
         ++counter;
         current = current->next;
      }

      nodeTile = current->tile;
   }
   return nodeTile;
}
bool LinkedList::contains(Tile *tile)
{
   bool check = false;
   for (int i = 0; i < size; ++i)
   {
      Tile *nodeTile = get(i);
      if (nodeTile->letter == tile->letter && nodeTile->value == tile->value)
      {
         check = true;
      }
   }
   return check;
}
int LinkedList::getIndex(Tile *tile)
{
   int index = -1;
   for (int i = 0; i < size; ++i)
   {
      Tile *nodeTile = get(i);
      if (nodeTile->letter == tile->letter && nodeTile->value == tile->value)
      {
         index = i;
      }
   }
   return index;
}
bool LinkedList::modify()
{
   return true;
}
void LinkedList::clear()
{
   while (head != nullptr)
   {
      removeFront();
   }
}

int LinkedList::getSize()
{
   return size;
}
bool LinkedList::empty()
{
   bool empty = false;
   if (size == 0)
   {
      empty = true;
   }
   return empty;
}