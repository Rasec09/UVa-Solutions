#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;
#define MAX 100

char map[MAX][MAX];
bool mark[MAX][MAX];

void dfs(pair <int, int> p, int n, int m)
{
	stack <pair<int,int> > pila;
	pila.push(p);			
	mark[p.first][p.second] = true;
	
	while(!pila.empty())
	{	
		pair <int, int> act = pila.top();
		pila.pop();

		if(!mark[act.first - 1][act.second - 1] && map[act.first - 1][act.second -1] != '*' && (act.first - 1) >= 0 && (act.second - 1) >= 0){
			mark[act.first - 1][act.second - 1] = true;
			pila.push(make_pair(act.first - 1, act.second - 1));
		}
		if(!mark[act.first - 1][act.second] && map[act.first - 1][act.second] != '*' && (act.first - 1) >= 0){
			mark[act.first - 1][act.second] = true;
			pila.push(make_pair(act.first - 1, act.second));
		}
		if(!mark[act.first - 1][act.second + 1] && map[act.first - 1][act.second + 1] != '*' && (act.first - 1) >= 0 && (act.second + 1) < m){
			mark[act.first - 1][act.second + 1] = true;
			pila.push(make_pair(act.first - 1, act.second + 1));
		}
		if(!mark[act.first][act.second - 1] && map[act.first][act.second - 1] != '*' && (act.second - 1) >= 0){
			mark[act.first][act.second - 1] = true;
			pila.push(make_pair(act.first, act.second - 1));
		}
		if(!mark[act.first][act.second + 1] && map[act.first][act.second + 1] != '*' && (act.second + 1) < m){
			mark[act.first][act.second + 1] = true;
			pila.push(make_pair(act.first, act.second + 1));
		}
		if(!mark[act.first + 1][act.second - 1] && map[act.first + 1][act.second - 1] != '*' && (act.first + 1) < n && (act.second - 1) >= 0){
			mark[act.first + 1][act.second - 1] = true;
			pila.push(make_pair(act.first + 1, act.second - 1));
		}
		if(!mark[act.first + 1][act.second] && map[act.first + 1][act.second] != '*' && (act.first + 1) < n){
			mark[act.first + 1][act.second] = true;
			pila.push(make_pair(act.first + 1, act.second));
		}
		if(!mark[act.first + 1][act.second + 1] && map[act.first + 1][act.second + 1] != '*' && (act.first + 1) < n && (act.second + 1) < m){
			mark[act.first + 1][act.second + 1] = true;
			pila.push(make_pair(act.first + 1, act.second + 1));
		}
	}
}

int dfs_visitar(int n, int m)
{
	int numComp = 0;	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!mark[i][j] && map[i][j] == '@'){
				numComp++;
				dfs(make_pair(i, j), n, m);
			}
		}
	}

	return numComp;
}

int main()
{
	int n, m, total;
	
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> map[i][j];
			}
		}
		
		total = dfs_visitar(n, m);
		printf("%d\n", total);
		memset(mark, false, sizeof(mark));
	}	

	return 0;
}
