#include <iostream>
using namespace std;

int provjeriZagrade(char *niz, int *zastavica) {
   if (*niz == 0) {
      return (*zastavica == 0 ? 1 : 0);
   } else if (*niz == '[')
      ++*zastavica;
   else
      --*zastavica;

   return provjeriZagrade(niz + 1, zastavica);
}

int main(void) {
   char *niz = "[[]";
   int rez = 0;
   cout << "Rez: " << provjeriZagrade(niz, &rez);
   return 0;
}