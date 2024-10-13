#include <iostream>
#include <math.h>
using namespace std;

int maxProfit(int p[], int n) {
    if(n == 0)  return 0;
    int best = 0;
    for(int len = 1; len <= n; len++) {
        int profit = p[len] + maxProfit(p, n - len);
        best = max(best, profit);
    }
    return best;
}

int main()
{
    int n = 4;
    int profit[4] ={2, 3, 2, 5};
    cout<<maxProfit(profit, 4);

    return 0;
}
