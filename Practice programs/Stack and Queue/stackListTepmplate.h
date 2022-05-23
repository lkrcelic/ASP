#include <iostream>

using namespace std;
template <typename T> struct ListElement {
   T data;
   ListElement<T> *next;
};

template <class T> class Stog {
 private:
   ListElement<T> *head = nullptr;

 public:
   bool push(T data) {
      ListElement<T> newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool pop(T &el) {
      if (!head)
         return false;
      else {
         el = head->data;
         ListElement<T> *tmp = head;
         head = head->next;
         delete tmp;
         return true;
      }
   }
};