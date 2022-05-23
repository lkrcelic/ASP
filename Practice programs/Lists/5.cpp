#include "template.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T> void List<T>::deleteAll() {
   while (head)
      this->remove(head->data);
}

int main(void) {

   List<int> l;
   l.append(4);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);

   l.print();

   l.deleteAll();
   cout << "Lista: ";
   l.print();

   return 0;
}