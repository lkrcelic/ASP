#include "template.h"
#include <iostream>
#include <string>

using namespace std;
template <typename T> void List<T>::reverseListRAux(ListElement<T> **p) {
   ListElement<T> *first = nullptr;
   ListElement<T> *fnext = nullptr;
   if (!*p)
      return; // prazna lista
   first = *p;
   fnext = first->next;

   if (!fnext)
      return;
   cout << "fisrt: " << first->data << "  first->next: " << first->next->data
        << endl;

   reverseListRAux(&fnext);
   cout << "  "
        << "First: " << first->data << "  First->next: " << first->next->data
        << "     Fnext: " << fnext->data << endl;
   first->next->next = first;
   first->next = nullptr;
   //*p = fnext;
   cout << "    "
        << "Fnext: " << fnext->data << endl;
}
template <typename T> void List<T>::reverseListR() { reverseListRAux(&head); }

int main(void) {

   List<int> l;
   l.append(4);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);

   l.print();

   l.reverseListR();
   cout << endl << endl;
   l.print();

   return 0;
}