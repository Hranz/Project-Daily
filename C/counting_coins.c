/*
   Programmer: Kristoffer Larson
   Date: February 21, 2014
   
   Description: Translating someone's java program into C.
      It's supposed to caclulate the number of ways you can
      get change with certain valued coins. 

*/

#include <stdio.h>
#include <stdlib.h>

int countingChange(int c[], int change) {
   int n = sizeof(c) / sizeof(c[0]);
   int dp[change + 1][n];
   
   int i;
   for (i = 0; i < n; i++) {
      dp[0][i]++;
   }
   
   int j;
   for (i = 1; i <= change; i++) {
      for (j = 1; j < n; j++) {
         dp[i][j] = dp[i][j-1];
         if (i - c[j] >= 0)
            dp[i][j] += dp[i - c[j]][j];
      }
   }
   
   return dp[change][n - 1];
}

int main() {
   int change;
   printf("What is the amount of change you want? ");
   scanf("%d", &change);
   
   int coins;
   printf("How many coins are in your set? ");
   scanf("%d", &coins);
   
   int i;
   int c[coins];
   for (i = 1; i <= coins; i++) {
      printf("What are the values of coin %d in your set? ", i);
      scanf("%d", &c[i - 1]);
   }
   
   printf("\nThere is/are %d way(s) to make change for %d cents.\n", countingChange(c, change) / 2, change);
      
   return 0;
}
