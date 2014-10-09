/*
*Uva Online Judge
*459 - Graph Connectivity	
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 30 

vector <int> grafo[MAX];
bool visited[MAX];

void dfs(int u)
{
	visited[u] = true;
	for(int v=0; v < grafo[u].size(); v++){
		if(visited[grafo[u][v]] == false)
			dfs(grafo[u][v]);
	}
}

void dfs_visitar(int V)
{
	int num = 0;

	for(int i=1; i <= V; i++){
		if(visited[i] == false){
			num++;
			dfs(i);
		}
	}

	printf("%d\n", num);
}

int main()
{
	int TC, V;
	char c, a, b;
	char input[10];
		
	scanf("%d", &TC);	
	while(TC--)
	{
		memset(visited, false, sizeof(visited));
		cin >> c;
		V = c - '0' - 16;
		while(getchar() != '\n');
		while(gets(input) && sscanf(input, "%c%c", &a, &b) == 2)
		{
			int u, v;
			u = a - '0' - 16;
			v = b - '0' - 16;			
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		dfs_visitar(V);
		if(TC)	
			printf("\n");
		for(int i=0; i<MAX; i++)
			grafo[i].clear();
	}

	return 0;
}
