#include <stdio.h>
#include <string.h>

#define MAX 205

int N, M, D, Q;
int set[MAX], memo[MAX][MAX][15];

int dp(int i, int sum, int c)
{
	if(c == M && sum == 0)
		return 1;
	if(c == M && sum != 0)
		return 0;
	if(i == N)
		return 0;
	if(memo[i][sum][c] != -1)
		return memo[i][sum][c];

	memo[i][sum][c] = dp(i+1, sum%D, c) + dp(i+1, (sum+set[i])%D, c+1);

	return memo[i][sum][c];
}

int main()
{
	int i, j, res;

	j = 1;
	while(1)
	{
		scanf("%d %d", &N, &Q);
		
		if(N == 0 && Q == 0)
			break;

		for(i = 0; i < N; i++){
			scanf("%d", &set[i]);
		}
		printf("SET %d:\n", j);
		for(i = 0; i < Q; i++){
			scanf("%d %d", &D, &M);
			memset(memo, -1, sizeof(memo));
			res = dp(0, 0, 0);
			printf("QUERY %d: %d\n", i+1, res);
		}
		j++;
	}	
	return 0;
}
