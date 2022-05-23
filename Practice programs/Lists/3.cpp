#include <iostream>
#include <string>

#include "template.h"
using namespace std;

template <typename T> int List<T>::length() {
   ListElement<T> *p;
   int i;
   for (i = 0, p = this->head; p; i++, p = p->next)
      cout << p << endl;
   cout << p << endl;

   return i;
}

int main(void) {

   List<int> l;
   l.append(4);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);

   l.print();

   cout << l.length();
   return 0;
}