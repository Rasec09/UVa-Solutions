#include<bits/stdc++.h>
using namespace std;
#define INF 1 << 30

typedef pair<int, int> ii;
typedef pair<int, ii> arista;
vector <arista> aristas;

bool operator < (const arista a, const arista b){
    if(a.first < b.first)
        return true;
    return false;
}

int sets;
int padres[1000002];
int numVertices[1000002];

void initSet(int n)
{
    sets = n;
    for(int i = 0; i <= n; i++){
        padres[i] = i;
        numVertices[i] = 1;
    }
}
int findSet(int x){ return(x == padres[x])? x: padres[x] = findSet(padres[x]);}
bool isSameSet(int x, int y){ return findSet(x) == findSet(y);}
void unionSet(int x, int y)
{
    int xRoot = findSet(x);
    int yRoot = findSet(y);

    if(!isSameSet(xRoot, yRoot)){
        numVertices[yRoot] += numVertices[xRoot];
        padres[xRoot] = yRoot;
        sets--;
    }
}

vector <arista> kruskal(int v)
{
    vector <arista> MST;
    initSet(v);
    sort(aristas.begin(), aristas.end());
    for(int i = 0; i < aristas.size(); i++){
        int peso = aristas[i].first;
        int origen = aristas[i].second.first;
        int destino = aristas[i].second.second;
        if(!isSameSet(origen, destino)){
            MST.push_back(arista(peso, ii(origen, destino)));
            unionSet(origen, destino);
        }
    }
    return MST;
}

int second_mst(int V, int O, int D)
{
    int total = 0;
    initSet(V);
    for(int i = 0; i < aristas.size(); i++){
        int origen = aristas[i].second.first;
        int destino = aristas[i].second.second;
        if(origen == O && destino == D)
            continue;
        if(!isSameSet(origen, destino)){
            unionSet(origen, destino);
            total += aristas[i].first;
        }
    }
    if(sets != 1)
        return INF;
    return total;
}

int main()
{
    int TC, V, E, a, b, w, s1, s2;
    vector <arista> MST;
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; i++){
            scanf("%d %d %d", &a, &b, &w);
            aristas.push_back(arista(w, ii(a, b)));
        }
        MST = kruskal(V);
        s1 = 0, s2 = INF;
        for(int i = 0; i < MST.size(); i++){
            s2 = min(s2, second_mst(V, MST[i].second.first, MST[i].second.second));
            s1 += MST[i].first;
        }
        if(s2 == INF)
            printf("%d %d\n", s1, s1);
        else
            printf("%d %d\n", s1, s2);
        aristas.clear();
    }
    return 0;
}
