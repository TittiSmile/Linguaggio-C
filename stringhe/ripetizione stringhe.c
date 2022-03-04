/*data una stringa in entrata ed un numero n, creare una funzione che restituisca una nuova stringa ns costituita dalle concatenazione
di n copie di s. esempio:   stringa-> casa  n->3    output-> casacasacasa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

char*concatena(char*s,int n);

int main ()
{
    int dim;
    char*a=(char*)malloc(max);

    printf("digitare la tua stringa:  ");
    scanf("%s",a);

    printf("quante volte la vuoi ripetere?  ");
    scanf("%d",&dim);

    a=concatena(a,dim);
    printf("\n%s",a);


    return 0;
}

char*concatena(char*s,int n)
{
    char*a;
    if(n!=0)
    {
        a=concatena(s,n-1);
        strcat(a,s);
    }
    else
    {
        a=(char*)malloc(max);
        a[0]='\0';
    }
    return a;

}
