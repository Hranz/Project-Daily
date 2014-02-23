/*
   Programmer: Kristoffer Larson
   Date: February 22, 2014
   
   Description: Recursively solves for a factorial.
*/


int factorial(int n) {
   if (n == 1) return 1;
   return factorial(n - 1) * n;
}

int main() {
   int num;
   scanf("%d",&num);
   printf("%d", factorial(num));
   return 0;
}
