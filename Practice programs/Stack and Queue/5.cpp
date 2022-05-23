
#include <iostream>
using namespace std;

template <typename T> struct ListElement {
   T item;
   ListElement<T> *next;
};

template <typename T> class DynamicQueue {
 private:
   ListElement<T> *read = nullptr;
   ListElement<T> *write = nullptr;

 public:
   bool enqueue(T item) {
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;

      newElement->item = item;
      newElement->next = nullptr;

      if (write == nullptr) {
         read = newElement;
      } else {
         write->next = newElement;
      }
      write = newElement;
      return true;
   }

   bool dequeue(T &item) {
      if (read == nullptr)
         return false;
      item = read->item;
      ListElement<T> *tmp;
      tmp = read;
      read = read->next;
      if (read == nullptr)
         write = nullptr;
      delete tmp;
      return true;
   }
   bool peek(int &el, int index) {
      DynamicQueue<T> tmp;
      T el2;
      int i = 0;
      while (this->dequeue(el2) && i < index) {
         tmp.enqueue(el2);
         i++;
      }
      if (index == i) {
         tmp.enqueue(el2);
         el = el2;
      }
      while (this->dequeue(el2))
         tmp.enqueue(el2);
      while (tmp.dequeue(el2))
         this->enqueue(el2);
      return true;
   }

   void print() {
      ListElement<T> *tmp = read;
      while (tmp) {
         cout << tmp->item << " ";
         tmp = tmp->next;
      }
      cout << endl;
   }
};

int main(void) {
   DynamicQueue<int> dq;
   dq.enqueue(2);
   dq.enqueue(3);
   dq.enqueue(4);
   dq.enqueue(5);
   dq.enqueue(6);
   dq.enqueue(7);
   dq.enqueue(8);

   dq.print();

   int tmp;
   dq.peek(tmp, 4);
   cout << tmp << endl;

   dq.print();

   return 0;
}