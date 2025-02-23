# include<stdio.h>
#include<conio.h> 
int max(int a, int b) { return (a > b)? a : b; } 
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Base Case 
   if (n == 0 || W == 0) 
       return 0; 
/* If weight of the nth item is more than Knapsack capacity W, then 
this item cannot be included in the optimal solution */
   if (wt[n-1] > W) 
       return knapSack(W, wt, val, n-1); 
/*Return the maximum of two cases:(1) nth item included (2) not included */
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
                    knapSack(W, wt, val, n-1)); 
} 
int main() 
{ 
    int val[] = {3,4,5,6}; 
    int wt[] = {2,3,4,5}; 
    int  W = 5; 
    int n = 4; 
    printf(" Maximum vlaue we can put into knapsack is %d", knapSack(W, wt, val, n)); 

}
