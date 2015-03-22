#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 205

int V, E;
vector <int> ady[MAX];
int color[MAX];

bool BFS(int s)
{
    queue <int> cola;
    cola.push(s);
    color[s] = 1;

    while(!cola.empty())
    {
        int actual = cola.front();
        cola.pop();
        for(int i = 0; i < ady[actual].size(); i++){
            int v = ady[actual][i];
            if(color[v] == -1){
                color[v] = 1 - color[actual];
                cola.push(v);
            }
            else if(color[actual] == color[v])
                return false;
        }
    }
    return true;
}

int main()
{
    int u, v;

    while(1)
    {
        scanf("%d", &V);
        if(V == 0) break;
        scanf("%d", &E);
        for(int i = 0; i < E; i++){
            scanf("%d %d", &u, &v);
            ady[u].push_back(v);
            ady[v].push_back(u);
        }
        memset(color, -1, sizeof(color));
        if(BFS(0))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        for(int i = 0; i < V; i++)
            ady[i].clear();
    }
    return 0;
}
