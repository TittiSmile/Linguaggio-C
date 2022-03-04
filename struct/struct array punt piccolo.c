/*definire una funzione che prenda in input un array di puntatori a struct Date e ne restituisca la data più piccola*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct DATA
{
    int giorno;
    int mese;
    int anno;
}dat;

typedef struct PUNT
{
    dat *elemento[20];
    int dimpunt;
}arr;


dat array_piccolo(dat *a);
arr compila();


int main ()
{
    dat x;
    int dim;
    dat vet[10];
    int i=0;
    arr a;

   /* printf("quante date vuoi inserire? ");
    scanf("%d",&dim);

    for(i=0;i<dim;i++)
    {
        printf("giorno? ");
        scanf("%d",&x.giorno);
        printf("mese? ");
        scanf("%d",&x.mese);
        printf("anno? ");
        scanf("%d",&x.anno);
        printf(" la data e': %d/%d/%d\n",x.giorno,x.mese,x.anno);
    }*/




    return 0;
}

dat array_piccolo(dat *a)
{
    /*

    for(i=0;i<dim;i++)
    {
       if(a.anno[i]<a.anno)
       {
         return data[i]
       }
       else if(a.mese[i]<a.mese)
       {return data[i]}
       else if(a.giorno[i]<a.giorno)
       return data[i]
    }
    */
}

arr compila()
{
    dat num;
    arr num;
    int i;

    printf("quante date vuoi inserire? ");
    scanf("%d",&num.dimpunt);
    for(i=0;i<num.dimpunt;i++)
    {
        printf("giorno? ");
        scanf("%d",&num.giorno);
        printf("mese? ");
        scanf("%d",&num.mese);
        printf("anno? ");
        scanf("%d",&num.anno);
        printf(" la data e': %d/%d/%d\n",num.giorno,num.mese,num.anno);
    }

    return num;
}
