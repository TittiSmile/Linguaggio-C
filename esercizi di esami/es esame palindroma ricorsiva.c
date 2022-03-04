#include <stdio.h>
#include <stdlib.h>


int *acquisisci(int n);
int palindroma(int a[],int n);
void stampa(int a[],int n);



int main ()
{
    int *a=NULL;
    int dim=0;

    printf("inserisci le dimensioni dell'array\n");
    scanf("%d",&dim);
    a=acquisisci(dim);

    stampa(a,dim);

    if(palindroma(a,dim))
    {
        printf("Palindroma");
    }
    else
    {
        printf("NON palindroma");
    }

free(a);

    return 0;
}



int *acquisisci(int n)
{
    int *a;
    int i=0;
    a=(int*)malloc(sizeof(int)*n); //mettiamo *n perchè dobbiamo tenere conto la grandezza dell'array (dim nel main)
    for(i=0;i<n;i++);
    {
        printf("inserisci numero\n");
        scanf("%d",&a[i]);
    }
    return a;
}


int palindroma(int a[],int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else  if(a[0]!=a[n-1])
        {
            return 0;
        }
    else
 {
  return palindroma(&a[1],n-2);
 }

}

void stampa(int a[],int n)
{
    int i=0;
     printf("La sequenza e' \n");
    for(i=0;i<n;i++)
    {
        scanf("%d ",a[i]);
    }
}










