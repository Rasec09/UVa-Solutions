#include <stdio.h>
#include <algorithm>
using namespace std;

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

int main()
{
    DisjointSet amigos;
    int TC, N, M, a, b, tam;

    scanf("%d", &TC);
    while(TC--)
    {
        tam = 0;
        scanf("%d %d", &N, &M);
        amigos.initSet(N+1);
        for(int i = 0; i < M; i++){
            scanf("%d %d", &a, &b);
            amigos.unionSet(a, b);
        }
        for(int i = 1; i <= N; i++){
            tam = max(tam, amigos.setSize(i));
        }
        printf("%d\n", tam);
    }
    return 0;
}
