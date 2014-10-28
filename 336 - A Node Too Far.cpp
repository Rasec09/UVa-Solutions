#include <bits/stdc++.h>

using namespace std;

map <int, vector <int> > grafo;
map <int, bool> visitado;
map <int, int> distancia;

int bfs(int s, int TTL)
{
	int cont;
	queue <int> cola;
	cola.push(s);	
	visitado[s] = true;
	distancia[s] = 0;
	cont = 0;	

	while(!cola.empty())
	{
		int act = cola.front();
		cola.pop();
		for(int i = 0; i < grafo[act].size(); i++){
			int v = grafo[act][i];
			if(!visitado[v]){
				visitado[v] = true;
				distancia[v] = distancia[act] + 1;
				if(distancia[v] > TTL) cont++;
				cola.push(v);	
			}
		}
	}

	return cont;
}

int bfs_visitar(int s, int TTL)
{
	int ans = 0;	
	map <int, vector<int> >::iterator it;
	visitado.clear();
	distancia.clear();

	ans = bfs(s, TTL);

	for(it = grafo.begin(); it != grafo.end(); it++){
		if(!visitado[it->first]){
			ans += bfs(it->first, -1000000000);
			ans++;
		}
	}
	
	return ans;
}

int main()
{
	int E, u, v, n, cont;

	cont = 1;
	while(1)
	{
		scanf("%d", &E);
		if(E == 0) break;
		while(E--)
		{
			scanf("%d %d", &u, &v);
			grafo[u].push_back(v);
			grafo[v].push_back(u);	
		}
		while(1)
		{
			scanf("%d %d", &u, &v);
			if(u == 0 && v == 0) break;
			if(grafo.find(u) != grafo.end()){
				n = bfs_visitar(u, v);
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cont, n, u, v);
			}
			else {
				printf("Case %d: %lu nodes not reachable from node %d with TTL = %d.\n", cont, grafo.size(), u, v);
			}
			cont++;			
		}
		grafo.clear();
	}

	return 0;
}
