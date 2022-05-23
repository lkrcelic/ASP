#include "template.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T> int List<T>::removeDuplicates() {
   int counter = 0;
   ListElement<T> *current = head;
   while (current) {
      ListElement<T> *following = current->next;

      if (following && following->data == current->data) {
         current->next = following->next;
         delete following;
         counter++;
      } else
         current = current->next;
   }
   return counter;
}

int main(void) {

   List<int> l;
   l.append(4);
   l.append(4);
   l.insert(5);
   l.insert(6);
   l.insert(6);
   l.insert(7);
   l.insert(7);
   l.insert(7);

   l.print();

   cout << l.removeDuplicates() << endl;

   l.print();

   return 0;
}