#include <iostream>
using namespace std;

struct RetValSearch {
   bool found;
   int index;
   RetValSearch() : found(false), index(-1) {}
   RetValSearch(bool found, int index) : found(found), index(index) {}
};

template <typename T> class ISearch {
 public:
   virtual RetValSearch search(const T A[], const size_t n, const T &item) = 0;
};

template <typename T> class LinearSearchRec : public ISearch<T> {
 public:
   RetValSearch search(const T A[], const size_t n, const T &item) override {
      if (n == 0)
         return RetValSearch(false, -1);
      else if (A[n - 1] == item)
         return RetValSearch(true, n - 1);
      else
         return search(A, n - 1, item);
   }
};

int main(void) { return 0; }
