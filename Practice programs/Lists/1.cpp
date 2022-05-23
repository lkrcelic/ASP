#include <string>
#include <iostream>

#include "template.h"

using namespace std;

template <typename T>
T &List<T>::at(int k) { // dohvati ref. na podatak u k-tom elementu liste
   int i;
   iterator it;
   for (i = 0, it = this->begin(); i < k && it != this->end(); i++, it++)
      ;
   if (k >= 0 && it != this->end())
      return *it;
   else
      throw std::runtime_error("Index out of range.");
}

int main(void) {

   List<int> l;
   l.append(4);
   l.append(5);
   l.insert(1);
   l.insert(2);
   l.insert(3);

   l.print();

   cout << l.at(1);
   return 0;
}