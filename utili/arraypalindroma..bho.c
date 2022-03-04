#include <stdio.h>
#define max 20

int *acquisisci(int n);
int palindroma(int a[],int n);
void stampa(int a[],int n);

int main ()
{
    int a[max] ;
    int dim;
    int i=0;
    printf("quanto e' grande il tuo array?\n");
    scanf("%d",&dim);

   for(i=0;i<dim;i++)
   {
       printf("inserisci numero\n");
       scanf("%d",&a[i]);
   }

   if(palindroma(a,dim))
   {
       printf("Palindroma\n");
   }
   else
   {
       printf("NON palindroma\n");
   }

  ////////Stampa/////
   /*printf("La sequenza e' \n");
   for(i=0;i<dim;i++)
   {
       printf("%d",&a[i]);
   }*/
   stampa(a,dim);

/////////////////////////NON SO PERCHè LA STAMPA,STAMPA MALE!!!!

    return 0;
}

int *acquisisci(int n)
{
    int *a;
    int i=0;
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++);
    {
        printf("inserisci numero");
        scanf("%d",&a[i]);
    }

/*int *a, i=0;

    a=(int *)malloc(sizeof(int)*n);

    for(i=0; i<n; i++)
    {
        printf("inserire il valore\n");
        scanf("%d",&a[i]);
    }*/
return a;

}




int palindroma(int a[],int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else if (a[0]!=a[n-1])
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
    printf("i numeri sono:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf("\n");
    }

}

