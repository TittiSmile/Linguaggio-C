///questo programma ha qualche problema ma non so quale. probabilmente bisogna utilizzare 'eof'
#include <stdio.h>
#include <stdlib.h>
#define max 10
int main ()
{
    FILE*fp;
    int i=0;
    int n;  //grandezza dell'array
    int v[max];
    int controllo;   ///l'ho aggiunto dopo cercando di capire perchè non inserisse un numero

    fp=fopen("provaa.txt","r");
    if(fp==NULL)
    {
        printf("errore di apertura");
        return 1; /// in questo caso, se c'è un errore,non va avanti ma si ferma (è come se fosse un 'break')
    }
    fscanf(fp,"%d",&n); ///legge quanti numeri ci sono nel file
    if(n>=10)
    {
        printf("troppi numeri");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            controllo=fscanf(fp,"%d",&v[i]);
            if(controllo==EOF)    ///scorre ciò che c'è nel file fino alla fine e poi,quando finisce,si ferma
            {
                break;
            }
        }
    }
        for(i=0;i<n;i++)
            {
               printf("\n %d",v[i]);
            }
    fclose(fp);

    return 0;
}
