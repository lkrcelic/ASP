#include <iostream>
using namespace std;

float kamracRec(float g, int n, float p, float rez) {
   if (n <= 0)
      return g * rez;
   float percentage = (1 + p / 100);
   rez = percentage * rez;
   return kamracRec(g, n - 1, p, rez);
}
int main() {
   cout << kamracRec(1100, 9, 3, 1.0);
   return 0;
}