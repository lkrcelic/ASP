#include <iostream>
#include <string>

#include "template.h"

using namespace std;

template <typename T> ListElement<T> *List<T>::at2(int k) {
   if (k < 0)
      return nullptr;
   int i;
   ListElement<T> *p;
   for (i = 0, p = head; i < k && p; i++, p = p->next)
      ;
   return p;
}

int main(void) {

   List<int> l;
   l.append(4);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);

   l.print();

   cout << l.at2(1);
   return 0;
}