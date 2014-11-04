#include <bits/stdc++.h>
using namespace std;
#define MAX 20

typedef pair <int, int> Coord;
char mapa[MAX][MAX];
bool visitado[MAX][MAX];
char l;

int DFS(Coord s, int n, int m)
{
	int v = 1;
	stack <Coord> pila;
	
	pila.push(s);	
	visitado[s.first][s.second] = true;
	while(!pila.empty())
	{
		Coord act = pila.top();
		pila.pop();
				
		visitado[act.first][act.second] = true;
		if(!visitado[act.first][(act.second + 1 + m)%m] && mapa[act.first][(act.second + 1 + m)%m] == l){
			v++;	
			visitado[act.first][(act.second + 1 + m)%m] = true;
			pila.push(make_pair(act.first, (act.second + 1 + m)%m));	
		}
		if(!visitado[act.first][(act.second - 1 + m)%m] && mapa[act.first][(act.second - 1 + m)%m] == l){
			v++;
			visitado[act.first][(act.second - 1 + m)%m] = true;
			pila.push(make_pair(act.first, (act.second - 1 + m)%m));
		}
		if(!visitado[act.first + 1][act.second] && mapa[act.first + 1][act.second] == l && (act.first + 1) < n){
			v++;			
			visitado[act.first + 1][act.second] = true;
			pila.push(make_pair(act.first + 1, act.second));
		}
		if(!visitado[act.first - 1][act.second] && mapa[act.first - 1][act.second] == l && (act.first - 1) >= 0){
			v++;
			visitado[act.first - 1][act.second] = true;			
			pila.push(make_pair(act.first - 1, act.second));
		}
	}

	return v;
}

int DFS_Visitar(int n, int m)
{
	int numVer = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visitado[i][j] && mapa[i][j] == l){
				numVer = max(numVer, DFS(make_pair(i, j), n, m));			
			}		
		}
	}

	return numVer;
}

int main()
{
	int n, m, x, y, max_val;
	
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> mapa[i][j];
		}
		scanf("%d %d", &x, &y);
		l = mapa[x][y];
		DFS(make_pair(x, y), n, m);	
		max_val = DFS_Visitar(n, m);
		printf("%d\n", max_val);
		memset(visitado, false, sizeof(visitado));
	}
	return 0;
}
