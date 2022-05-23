#include "1.cpp"
#include <iostream>
using namespace std;

template <typename T> bool Stack<T>::peek(T &el) {
   if (!this->pop(el))
      return false;
   this->push(el);
   return true;
}

int main(void) {

   Stack<int> s;
   s.push(3);
   s.push(4);
   s.push(5);
   s.push(6);
   s.push(7);
   s.print();

   int a;
   s.peek(a);
   cout << a << endl;
   s.print();

   return 0;
}