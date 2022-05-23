#include <iostream>
using namespace std;

template <class T> class Stack {
 private:
   static const int MAX = 10;
   T stack[MAX];
   int top = -1;

 public:
   bool push(T item) {
      if (top >= MAX)
         return false;
      stack[++top] = item;
      return true;
   }
   bool pop(T &item) {
      if (top < 0)
         return false;
      item = stack[top--];
      return true;
   }
   void print() {
      cout << "TOP -> ";
      for (int i = top; i >= 0; i--) {
         cout << stack[i] << " ";
      }
      cout << endl;
   }
};