#include <stdio.h>

int main()
{
	int gam[3], i, unos, ceros, pos1, pos0;
	
	while(scanf("%d %d %d", &gam[0], &gam[1], &gam[2]) != EOF)
	{
		unos = 0; 
		ceros = 0; 		
		for(i=0; i<3; i++){
			if(gam[i] == 1){
				unos++;
				pos1 = i;
			}
			else {
				ceros++;
				pos0 = i;
			}
		}
		
		if(unos == 1)
		{
			if(pos1 == 0)
				printf("A\n");
			else if(pos1 == 1)
				printf("B\n");
			else
				printf("C\n");
		}
		else if(ceros == 1){
			if(pos0 == 0)
				printf("A\n");
			else if(pos0 == 1)
				printf("B\n");
			else
				printf("C\n");
		}
		else
			printf("*\n");
	}

	return 0;
}
