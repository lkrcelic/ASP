#include <iostream>
using namespace std;

int poljeEkstrema(int *niz, int n) {
   if (n <= 2)
      return 1;
   cout << *niz << " " << *(niz + 1) << " " << *(niz + 2) << endl;

   if (*niz < *(niz + 1) && *(niz + 1) > *(niz + 2) ||
       *niz > *(niz + 1) && *(niz + 1) < *(niz + 2))
      return poljeEkstrema(niz + 1, n - 1);
   else
      return 0;
}

int main(void) {
   int polje[7] = {2, 1, 8, 7, 9, 5, 11};
   cout << poljeEkstrema(&polje[0], 7);
   return 0;
}