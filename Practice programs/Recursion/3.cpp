#include <iostream>
using namespace std;

// g – glavnica
// n – trajanje oročenja u godinama
// p – kamatna stopa u postotcima
float kamrac(float g, int n, float p) {
   if (n <= 0)
      return g;
   else {
      g = (1 + p / 100) * g;
      return kamrac(g, n - 1, p);
   }
}

int main(void) {
   cout << kamrac(1100, 9, 3);
   cin.get();
   return 0;
}
