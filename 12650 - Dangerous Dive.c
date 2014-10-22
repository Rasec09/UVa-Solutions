#include <stdio.h>
#include <string.h>

int main()
{
	int r, n, aux, i;
	int cubeta[10000];

	while(scanf("%d %d", &n, &r) != EOF)
	{
		for(i=1; i<=r; i++){
			scanf("%d", &aux);
			cubeta[aux] = 1;
		}

		if(n == r){
			printf("*");
		}		
		else {
			for(i=1; i<=n; i++){
				if(cubeta[i] == 0)
					printf("%d ", i);
			}
		}
		
		printf("\n");
		memset(cubeta, 0, sizeof(cubeta));
	}
	
	return 0;
}
