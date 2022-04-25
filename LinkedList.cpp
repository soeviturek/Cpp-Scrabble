
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   head->next = nullptr;
   tail = nullptr;
}

LinkedList::~LinkedList() {
   clear();
}

LinkedList::LinkedList(LinkedList& other){

}
bool LinkedList::add_front(Tile* tile){
   Node* node = new Node(tile, head);
   head = node;
   tail = head;
   return true;
}
bool LinkedList::add_back(Tile* tile){
   Node* node = new Node(tile,nullptr);
    if(head == nullptr){
        head = node;
    }else{
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = node;
    }
   return true;
}

bool LinkedList::remove(int index){
   if(index >= 0 && index < size){
        if(head != nullptr){
            int counter = 0;
            Node* current = head;
            //pre should point to node before current;
            Node* prev = nullptr;

            while(counter != index){
                ++counter;
                prev = current;
                current = current->next;
            }

            if(prev == nullptr){
                head = current->next;
            }else{
                prev->next = current->next;
            }

            delete current->tile;
            delete current;
        }
    }
}
bool LinkedList::remove_front(){
   bool check = true;
   if(head != nullptr){
        Node* node = head;
        head = head->next;

        delete node->tile;
        delete node;
    }
    else{
       check = false;
    }
   //  else{
   //      throw std::runtime_error("Nothing to remove");
   //  }
   return check;
}
bool LinkedList::remove_back(){
   bool check = false;
   if(head != nullptr){
        Node* current = head;
        Node* prev = nullptr;
        if(tail == head){
           head = nullptr;
        }else{
           while(current->next != nullptr){
              prev = current;
              current = current->next;
              }
            prev->next = nullptr;
            tail = prev;
        }
        
        delete current->tile;
        delete current;
    }
    return check;
}
Tile* LinkedList::get(int index){
   Tile* nodeTile = nullptr;

    if(index >= 0 && index < size){

        int counter = 0;
        Node* current = head;

        while(counter<index){
            ++counter;
            current = current->next;
        }

        nodeTile = current->tile;

    }
    return nodeTile;
}
bool LinkedList::contains(Tile* tile){
   bool check = false;
   for(int i = 0; i < size; ++i){
      Tile* nodeTile = get(i);
      if(nodeTile->letter == tile->letter && nodeTile->value == tile->value){
         check = true;
      }
   }
   return check;
}
bool LinkedList::modify(){
   
}
void LinkedList::clear(){
   while(head != nullptr){
      remove_front();
   }
}

int LinkedList::getSize(){
   return size;
}
bool LinkedList::empty(){
   bool empty = false;
   if(size == 0){
      empty = true;
   }
   return empty;
}
