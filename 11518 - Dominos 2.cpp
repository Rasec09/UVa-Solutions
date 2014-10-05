/*
*Uva Online Judge
*11518 - Dominos 2
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 10005

using namespace std;

vector <int> grafo[MAX];
int total;
bool visitado[MAX];

void dfs(int u)
{
	total++;
	visitado[u] = true;
	for(int v = 0; v < grafo[u].size(); v++){
		if(!visitado[grafo[u][v]])			
			dfs(grafo[u][v]);
	}
}

int main()
{
	int T, n, m, l, x, y, z;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &n, &m, &l);
		while(m--){
			scanf("%d %d", &x, &y);
			grafo[x].push_back(y);
		}
		while(l--){			
			scanf("%d", &z);
			if(!visitado[z])		
				dfs(z);
		}
		
		printf("%d\n", total);
		total = 0;
		fill(visitado, visitado + MAX, false);
		for(int i = 0; i < n; i++){
			grafo[i].clear();
		}
	}
	
	return 0;
}
