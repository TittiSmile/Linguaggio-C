#include <stdio.h>
#define max 30

int occorrenza(char c,char *s,int h,int k);

int main ()
{
    char c;
    char stringa[max];
    int h=0;
    int k=0;



    printf("\ninserisci carattere\n");
    scanf("%c",&c);
    ///N.B.!!! NON so perchè ma se metti prima il printf dell'inserimento stringa,non va l'inserimento del carattere.
    /// per questo motivo ho chiesto di inserire prima un carattere.
    ///EDIT: va usato fflush(stdin).
    printf("Inserisci la stringa\n");
    scanf("%s",stringa);
    printf("\ninserisci indice 'h' \n");
    scanf("%d",&h);
    printf("\ninserisci indice 'k' \n");
    scanf("%d",&k);

    printf("La stringa digitata e': %s ",stringa);

    printf("\nIl numero di occorrenze di %c degli indici h=%d e k=%d e':   %d",c,h,k,occorrenza(c,stringa,h,k));



    return 0;
}

int occorrenza(char c,char *s,int h,int k)
{
    int trovato=0;
    if(h<=k)
    {
        if(s[h]==c)
        {
            trovato=1+occorrenza(c,s,h+1,k);
        }
        else
        {
            trovato=occorrenza(c,s,h+1,k);
        }

    }
    return trovato;
}
