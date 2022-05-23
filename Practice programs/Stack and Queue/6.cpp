#include <iostream>
using namespace std;
#include "queueTemplate.h"
#include "stackTemplate.h"

template <class T> bool transfer(Stack<T> *s, Queue<T> *q) {
   T element;
   bool status;
   status = s->pop(element);
   if (status == false)
      return true;
   status = q->enqueue(element);
   if (status == false)
      return false;
   return transfer(s, q);
}

int main(void) {
   Queue<int> q;

   Stack<int> s;
   s.push(13);
   s.push(14);
   s.push(15);
   s.push(16);
   s.push(17);
   s.print();

   transfer(&s, &q);
   q.print();

   // Stack->Queue
   // element koji je bio na vrhu stoga bude prvi na izlazu iz reda
   // Ulazni stog nakon izvršavanja funkcije transfer ostaje prazan
}