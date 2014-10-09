#include <stdio.h>
#define MAX 1000005

int padres[MAX];
int numVertices[MAX];

void initSet(int n)
{
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
		numVertices[xRoot] += numVertices[yRoot];
		padres[xRoot] = yRoot;
	}		
}

int main()
{
	int T, N, i, j, suc=0, uns=0;
	char input[3], c;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);		
		while (getchar() != '\n') ;
		initSet(N);
		char line[100];
		while(gets(line)  &&  sscanf(line, " %c %d %d", &c, &i, &j) == 3)
		{
			if(c == 'c'){
				unionSet(i, j);
			}
			else {
				if(isSameSet(i, j))
					suc++;
				else
					uns++;
			}

		}
		printf("%d,%d\n", suc, uns);
		suc = 0; uns = 0;
		if(T)		
		  printf("\n");
	}
	
	return 0;
}
