#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int x[9], TC, a, b, lineCounter;

bool place(int queen, int row)
{
    for(int ant = 1; ant <= queen - 1; ant++)
        if(x[ant] == row || (abs(x[ant] - row) == abs(ant - queen)))
            return false;
    return true;
}

void NQueens(int queen)
{
    for(int row = 1; row <= 8; row++){
        if(place(queen, row)){
            x[queen] = row;
            if(queen == 8 && x[b] == a){
                printf("%2d      %d", ++lineCounter, x[1]);
                for(int j = 2; j <= 8; j++)
                    printf(" %d", x[j]);
                printf("\n");
            }
            else {
                NQueens(queen + 1);
            }
        }
    }
}

int main()
{
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &a, &b);
        memset(x, 0, sizeof(x));
        lineCounter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        NQueens(1);
        if(TC) printf("\n");
    }
    return 0;
}
