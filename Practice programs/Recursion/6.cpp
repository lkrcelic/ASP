#include <iostream>
using namespace std;

int provjeri_sortiranost(int *niz, int n) {
   if (n == 1)
      return 1;
   if (*niz <= *(niz + 1))
      return provjeri_sortiranost(niz + 1, n - 1);
   else
      return 0;
}

int main(void) {
   int polje[3] = {1, 2, 3};
   cout << provjeri_sortiranost(&polje[0], 3);
   return 0;
}