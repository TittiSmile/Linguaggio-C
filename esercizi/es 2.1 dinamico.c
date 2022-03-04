#include <stdio.h>
#include <stdlib.h>

int figura(int base,int altezza);

int main ()
{
    int a,b;
    
    figura(a,b);
    
    return 0;
}

int figura(int base,int altezza)
{
    int area,perimetro;
    printf("inserisci la base del rettangolo:   ");
    scanf("%d",&base);
    //base=(int*)malloc(sizeof(int));
    printf("Inserisci l'altezza del rettangolo:   ");
    scanf("%d",&altezza);
    printf("altezza: %d\t\tbase:%d",altezza,base);
    //altezza=(int*)malloc(sizeof(int));
    area=(base*altezza)/2;
    perimetro=base+base+altezza+altezza;
    printf("\n\narea: %d\t\t\tperimetro: %d",area,perimetro);
 
    
    
    
}
