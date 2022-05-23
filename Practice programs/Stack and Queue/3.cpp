#include <iostream>

using namespace std;

template <typename T> struct ListElement {
   T data;
   ListElement<T> *next;
};

template <typename T> class DynamicStack {
 private:
   ListElement<T> *head = nullptr;

 public:
   bool push(T data) {
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      else {
         newElement->data = data;
         newElement->next = head;
         head = newElement;
         return true;
      }
   }
   bool pop(T &data) {
      if (head == nullptr)
         return false;
      else {
         data = head->data;
         ListElement<T> *tmp = head;
         head = head->next;
         delete tmp;
         return true;
      }
   }
   bool peek(int &el, int index) {
      DynamicStack<T> tmp;
      T el2;
      int i = 0;
      while (i < index && this->pop(el2)) {
         tmp.push(el2);
         i++;
      }
      if (i == index) {
         this->pop(el);
         tmp.push(el);
      }
      while (tmp.pop(el2)) {
         this->push(el2);
      }
      if (i == index)
         return true;
      else
         return false;
   }

   void pirnt() {
      for (ListElement<T> *p = head; p; p = p->next) {
         cout << p->data << " ";
      }
      cout << endl;
   }
};

int main(void) {

   DynamicStack<int> ds;
   ds.push(2);
   ds.push(3);
   ds.push(4);
   ds.push(5);
   ds.push(6);
   ds.push(7);
   ds.push(8);
   ds.pirnt();

   int el;
   ds.peek(el, 3);
   cout << el << endl;

   ds.pirnt();
   return 0;
}