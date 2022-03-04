#include <stdio.h>
int minimor(int a[],int n);


int main ()
{
    int array[10],i,n;

    printf("quanti numeri vuoi nell'array? (max 10) ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("inserisci l'elemento %d:  ",i+1);
        scanf("%d",&array[i]);
    }

    printf("il numero piu' piccolo e': %d ",minimor(array,n));
    return 0;
}


int minimor(int a[],int n)
{
   int min;
   n--;
   if(n==0)
   {
       return a[0];
   }
  min=minimor(a,n);
  if(min<a[n])
  {
      return min;
  }
return a[n];

}
