#include <stdio.h>
#include <string.h>
#include <utility>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#define MAX 101

typedef pair <int, int> Coord;
int square[MAX][MAX];
bool visitado[MAX][MAX];

void dfs(Coord s, int n)
{
	stack <Coord> pila;
	pila.push(s);	
	visitado[s.first][s.second] = true;
	
	while(!pila.empty())
	{
		Coord act = pila.top();
		pila.pop();
		
		if(!visitado[act.first - 1][act.second] && square[act.first - 1][act.second] == square[s.first][s.second] && (act.first - 1) >= 0){
			visitado[act.first - 1][act.second] = true;
			pila.push(make_pair(act.first - 1, act.second));
		}
		if(!visitado[act.first][act.second - 1] && square[act.first][act.second - 1] == square[s.first][s.second] && (act.second - 1) >= 0){
			visitado[act.first][act.second - 1] = true;
			pila.push(make_pair(act.first, act.second - 1));
		}
		if(!visitado[act.first + 1][act.second] && square[act.first + 1][act.second] == square[s.first][s.second] && (act.first + 1) < n){
			visitado[act.first + 1][act.second] = true;
			pila.push(make_pair(act.first + 1, act.second));
		}
		if(!visitado[act.first][act.second + 1] && square[act.first][act.second + 1] == square[s.first][s.second] && (act.second + 1) < n){
			visitado[act.first][act.second + 1] = true;
			pila.push(make_pair(act.first, act.second + 1));
		}
	}
}

int dfs_visitar(int n)
{
	int numComp = 0;	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visitado[i][j]){
				numComp++;
				dfs(make_pair(i, j), n);
			}
		}
	}

	return numComp;
}

int main()
{
	int n, x, y, l, total;
	char line[250];

	while(1)
	{
		scanf("%d", &n);
		if(n == 0) break;
		cin.ignore();
		for (int i = 0; i < n - 1; ++i) {
			string s; getline(cin, s);
			stringstream sin(s);
			for (int a, b; sin >> a >> b;)
		        	square[a - 1][b - 1] = i + 1;
		 }
		total = dfs_visitar(n);
		if(total == n)
			printf("good\n");
		else
			printf("wrong\n");
		memset(square, 0, sizeof(square));
		memset(visitado, false, sizeof(visitado));
	}

	return 0;
}
