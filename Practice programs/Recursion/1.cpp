#include <iostream>
using namespace std;

int kvazi_binomi(int n, int m) {
   if (m == n || m == 0)
      return 1;
   else if (n < 0 || m > n)
      return 0;

   return kvazi_binomi(n - 1, m - 1) + m * kvazi_binomi(n - 1, m + 1);
}

int main(void) {
   int n, m;

   cin >> n >> m;

   cout << kvazi_binomi(n, m);
   return 0;
}
