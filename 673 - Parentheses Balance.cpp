#include <stdio.h>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    int n, tam;
    char s[128];
    bool flag;
    stack <char> pila;

    scanf("%d", &n);
    while(getchar() != '\n');
    while(n--)
    {
        flag = false;
        gets(s);
        tam = strlen(s);
        if(tam > 0){
            for(int i = 0; i < tam; i++){
                if(s[i] == '(' || s[i] == '['){
                    pila.push(s[i]);
                }
                else if(s[i] == ')'){
                    if(!pila.empty() && pila.top() == '(')
                        pila.pop();
                    else if(pila.empty()){
                        printf("No\n");
                        flag = true;
                        break;
                    }
                }
                else if(s[i] == ']'){
                    if(!pila.empty() && pila.top() == '[')
                        pila.pop();
                    else if(pila.empty()){
                        printf("No\n");
                        flag = true;
                        break;
                    }
                }
            }
            if(!pila.empty() && !flag)
                printf("No\n");
            else if(pila.empty() && !flag)
                printf("Yes\n");
        }
        else
            printf("Yes\n");
        while(!pila.empty())
            pila.pop();
    }
    return 0;
}
