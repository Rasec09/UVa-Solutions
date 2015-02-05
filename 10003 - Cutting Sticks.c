#include <stdio.h>
#include <limits.h>

int n, l, C[52], DP[52][52];
int min(int a, int b){ return (a < b)? a:b; }

int BottomUp(int ini, int fin)
{
    int i, j, k, L;

    /*Caso Base*/
    for(i = 0; i < fin; i++)
        DP[i][i+1] = 0;

    for(L = 2; L <= fin; L++){
        for(i = 0; i <= (fin - L); i++){
            j = i + L;
            DP[i][j] = INT_MAX;
            for(k = i+1; k < j; k++){
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j] + (C[j] - C[i]));
            }
        }
    }
    
    return DP[0][fin];
}

int main()
{
    int i, sol;

    while(1)
    {
        scanf("%d", &l);
        if(l == 0) break;
        scanf("%d", &n);
        C[0] = 0;
        for(i = 1; i <= n; i++)
            scanf("%d", &C[i]);
        C[n+1] = l;
        sol = BottomUp(0, n+1);
        printf("The minimum cutting is %d.\n", sol);
    }
    return 0;
}
