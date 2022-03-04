#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main ()
{
    int *a;
    int dim=0;
    int i=0;
    printf("quanto vuoi grande il tuo array? ");
    scanf("%d",&dim);
    a=malloc(dim*sizeof(int));

    printf("ecco l'array allocato dinamicamente (con malloc) inizializzato a 0:");
    for(i=0;i<dim;i++)
    {
        a[i]=0;
        printf("\n%d",a[i]);
    }


    return 0;
}
