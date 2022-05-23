#include <iostream>
#include <string>

using namespace std;

template <class T> struct ListElement {
   T data;
   ListElement<T> *next;
};

template <class T> class ListIterator {
 private:
   ListElement<T> *ptr = nullptr;

 public:
   ListIterator<T>() : ptr(nullptr) {}
   ListIterator<T>(ListElement<T> *ptr) : ptr(ptr) {}
   ListIterator<T> *operator++() { // prefix ++
      if (ptr)
         ptr = ptr->next;
      return this;
   }
   ListIterator<T> operator++(int i) { // postfix ++
      ListIterator<T> tmp = *this;
      ++(*this);
      return tmp;
   }
   bool operator!=(const ListIterator<T> &other) { return ptr != other.ptr; }
   T &operator*() { return ptr->data; }
};

template <class T> class List {
 private:
   ListElement<T> *head = nullptr;

 public:
   // zadatci
   // prvi
   T &at(int k);
   // drugi
   ListElement<T> *at2(int k);
   // treci
   int length();
   // cetvrti
   int countItem(T item);
   // peti
   void deleteAll();
   // setsti
   void reverseList();
   // sedmi
   void reverseListR();
   void reverseListRAux(ListElement<T> **p);
   // osmi
   int removeDuplicates();
   // zadatci

   bool remove(T data) {
      ListElement<T> **p;
      for (p = &head; *p && data != (*p)->data; p = &((*p)->next))
         ;
      if (*p) {
         ListElement<T> *tmp;
         tmp = *p;
         *p = (*p)->next;
         delete tmp;
         return true;
      } else {
         return false;
      }
   }

   bool insert(T data) { // umetanje na početak liste
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = head;
      head = newElement;
      return true;
   }
   bool append(T data) { // dodavanje na kraj liste
      ListElement<T> *newElement = new ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = nullptr;
      ListElement<T> **p;
      for (p = &head; *p; p = &((*p)->next))
         ;
      *p = newElement;
      return true;
   }
   bool insertSorted(T data) { // umetanje po sortiranom redoslijedu, T mora
                               // imati implementiran operator >
      ListElement<T> *newElement = new (nothrow) ListElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      ListElement<T> **p;
      for (p = &head; *p && data > (*p)->data; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      return true;
   }

   typedef ListIterator<T> iterator;
   iterator begin() { return iterator(head); }
   iterator end() { return iterator(); }

   void print() {
      for (ListElement<T> *p = head; p; p = p->next) {
         cout << p->data << " ";
      }
      cout << endl;
   }
};
