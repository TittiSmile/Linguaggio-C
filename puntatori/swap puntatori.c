#include <stdio.h>

int swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;

}

int main ()
{
    int a,b;

    printf("inserisci due numeri:  ");
    scanf("%d %d",&a,&b);
    printf("a: %d\nb:%d ",a,b);
    printf("\nfaccio lo scambio!!\n");
    swap(&a,&b);
    printf("\na: %d\nb:%d ",a,b);


    return 0;
}
