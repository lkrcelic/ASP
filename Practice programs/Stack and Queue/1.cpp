#include <iostream>

using namespace std;

template <class T> class Stack {
 private:
   static const size_t increment = 100;
   size_t size = 100;
   T *stack;
   int top = -1;

 public:
   Stack() { stack = (T *)malloc(size * sizeof(T)); }
   Stack(size_t size) : size(size) { stack = (T *)malloc(size * sizeof(T)); }

   bool push(T el) {
      if (top >= (int)(size - 1)) {
         size = size + increment;
         stack = (T *)realloc(stack, size * sizeof(T));
      }
      stack[++top] = el;
      return true;
   }
   bool pop(T &el) {
      if (top < 0) {
         return false;
      }
      if (top < (int)(size - increment)) {
         size = size - increment;
         stack = (T *)realloc(stack, size * sizeof(T));
      }
      el = stack[top--];
      return true;
   }

   void print() {
      for (int i = top; i <= 0; i--) {
         cout << stack[i] << " ";
      }
      cout << endl;
   }

   // ZADATCI
   // drugi
   bool peek(T &el);
   // ZADATCI
};