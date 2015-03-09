#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Edge;
typedef pair<int, Edge> arista;
vector <arista> aristas;

bool operator < (const arista a, const arista b){
    if(a.first < b.first)
        return true;
    return false;
}

struct DisjointSet
{
    int sets;
    int *padres;
    int *numVertices;

    void initSet(int n)
    {
        sets = n;
        padres = new int[n];
        numVertices = new int[n];
        for(int i = 0; i <= n; i++){
            padres[i] = i;
            numVertices[i] = 1;
        }
    }

    int findSet(int x)
    {
        if(x == padres[x])
            return x;
        else
            return padres[x] = findSet(padres[x]);
    }

    int setSize(int x)
    {
        return numVertices[findSet(x)];
    }

    bool isSameSet(int x, int y)
    {
        if(findSet(x) == findSet(y))
            return true;
        else
            return false;
    }

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
};

int kruskal(int v)
{
    DisjointSet mst;
    int origen, destino, peso, total = 0;

    mst.initSet(v);
    sort(aristas.begin(), aristas.end());
    for(int i = 0; i < aristas.size(); i++){
        peso = aristas[i].first;
        origen = aristas[i].second.first;
        destino = aristas[i].second.second;
        if(!mst.isSameSet(origen, destino)){
            total += peso;
            mst.unionSet(origen, destino);
        }
    }
    return total;
}

int main()
{
    int V, K, M, u, v, peso, total = 0, T = 0;

    while(scanf("%d", &V) != EOF)
    {
        for(int i = 0; i < V - 1; i++){
            scanf("%d %d %d", &u, &v, &peso);
            total += peso;
        }
        if(T != 0) printf("\n");
        printf("%d\n", total);
        scanf("%d", &K);
        for(int i = 0; i < K; i++){
            scanf("%d %d %d", &u, &v, &peso);
            aristas.push_back(arista(peso, Edge(u, v)));
        }
        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &u, &v, &peso);
            aristas.push_back(arista(peso, Edge(u, v)));
        }
        printf("%d\n", kruskal(V));
        total = 0;
        aristas.clear();
        T++;
    }
    return 0;
}
