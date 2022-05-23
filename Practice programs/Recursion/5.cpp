#include <iostream>
using namespace std;

void okreni_oduzmi(int polje[], int n) {
   if (n == 0) {
      cout << endl;
      return;
   } else {
      cout << polje[n - 1] - polje[0] << " ";
      return okreni_oduzmi(polje, n - 1);
   }
}

int main(void) {
   int polje[6] = {2, 6, 8, 11, -3, 100};
   okreni_oduzmi(polje, 5);
   return 0;
}