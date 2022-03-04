#include <stdio.h>

int somma(int *x1,int *x2)
{
    int xs;
    xs=*x1+*x2;
   return xs;

}


int main ()
{
int x1,x2;
int ris;
printf("digitare due valori interi\n");
scanf("%d %d",&x1,&x2);

ris=somma(&x1,&x2);
printf("somma: %d ",ris);





    return 0;
}
