template <typename T> class Queue {
 private:
   static const int MAX = 100;
   T queue[MAX];
   int write = 0;
   int read = 0;

 public:
   bool enqueue(T item) {
      if (read == (write + 1) % MAX)
         return false;
      queue[write] = item;
      write = (write + 1) % MAX;
      return true;
   }
   bool dequeue(T &item) {
      if (read == write)
         return false;
      item = queue[read];
      read = (read + 1) % MAX;
      return true;
   }

   int count() {
      if (write >= read)
         return write - read;
      else
         return write + MAX - read;
   }

   void print() {
      int i = read;
      while (i != write) {
         cout << queue[i] << " ";
         i = (i + 1) % MAX;
      }
      cout << endl;
   }

   bool peek(T &item) {
      Queue<T> tmp;
      T item2;
      if (!this->dequeue(item))
         return false;
      tmp.enqueue(item);
      while (this->dequeue(item2)) {
         tmp.enqueue(item2);
      }

      while (tmp.dequeue(item2))
         this->enqueue(item2);

      return true;
   }
};