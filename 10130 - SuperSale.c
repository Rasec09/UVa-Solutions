#include <stdio.h>

struct item
{
    int peso;
    int valor;
};

int max(int a, int b){ return (a > b)? a : b; }
struct item mochila[1001];
int DP[1002][3002];

void Knapsack(int n, int W)
{
    int i, w;

    for(i = 0; i < n; i++)
        DP[0][i] = 0;

    for(i = 1; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(mochila[i-1].peso <= w)
                DP[i][w] = max(DP[i-1][w], DP[i-1][w - mochila[i-1].peso] + mochila[i-1].valor);
            else
                DP[i][w] = DP[i-1][w];
        }
    }
}

int main()
{
    int i, g, mw, sol, TC, n;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d %d", &mochila[i].valor, &mochila[i].peso);
        Knapsack(1000, 3000);
        scanf("%d", &g);
        sol = 0;
        for(i = 0; i < g; i++){
            scanf("%d", &mw);
            sol += DP[n][mw];
        }
        printf("%d\n", sol);
    }
    return 0;
}
