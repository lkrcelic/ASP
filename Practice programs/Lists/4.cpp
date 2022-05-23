#include "template.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T> int List<T>::countItem(T item) {
   ListElement<T> *t;
   int count = 0;
   for (t = this->head; t; t = t->next) {
      if (t->data == item)
         count++;
   }
   return count;
}

int main(void) {

   List<int> l;
   l.append(3);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);

   l.print();

   cout << l.countItem(3);
   return 0;
}