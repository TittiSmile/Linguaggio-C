#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int *a;
    int dim=0;
    int i=0;

    printf("quanto vuoi grande il tuo array?  ");
    scanf("%d",&dim);
    a=malloc(dim*sizeof(int));

    for(i=0;i<dim;i++)
    {
        printf("inserisci l'elemento %d: ",i+1);
        scanf("%d",&a[i]);
    }

    printf("ecco l'array allocato con malloc con gli elementi da te decisi: ");
    for(i=0;i<dim;i++)
    {
        printf("\n%d",a[i]);
    }

    return 0;
}
