#include <stdio.h>
#include <string.h>

int M, C, K, price[25][25];
int memo[210][25];
int max(int a, int b){ return (a > b)? a : b; }

int shop(int money_left, int garment_id)
{
    if(money_left < 0)
        return -1000000000;
    if(garment_id == C)
        return M - money_left;
    if(memo[money_left][garment_id] != -1)
        return memo[money_left][garment_id];
    int model, max_value = -1000000000;
    for(model = 1; model <= price[garment_id][0]; model++)
        max_value = max(max_value, shop(money_left - price[garment_id][model], garment_id + 1));
    return memo[money_left][garment_id] = max_value;
}

int main()
{
    int i, j, TC, score;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &M, &C);
        for(i = 0; i < C; i++){
            scanf("%d", &K);
            price[i][0] = K;
            for(j = 1; j <= K; j++)
                scanf("%d", &price[i][j]);
        }
        memset(memo, -1, sizeof(memo));
        score = shop(M, 0);
        if(score < 0)
            printf("no solution\n");
        else
            printf("%d\n", score);
    }
    return 0;
}
