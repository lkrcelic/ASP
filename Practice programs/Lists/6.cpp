#include "template.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T> void List<T>::reverseList() {
   ListElement<T> *el = head;
   ListElement<T> *elnext = nullptr;
   ListElement<T> *elprev = nullptr;

   while (el) {
      elnext = el->next;
      el->next = elprev;
      elprev = el;
      el = elnext;
   }
   head = elprev;
}

int main(void) {

   List<int> l;
   l.append(4);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);

   l.print();

   l.reverseList();

   return 0;
}