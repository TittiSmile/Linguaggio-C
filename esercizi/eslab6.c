#include <stdio.h>
#include <string.h>

int main ()
{
    char parola1[10];
    char parola2[10];
    int compara;

    printf("digitare una parola: ");
    scanf("%s",parola1);
    printf("\ndigitare una seconda parola: ");
    scanf("%s",parola2);

    compara=strcmp(parola1,parola2);

    if(compara==0)
        {
            printf("\nle stringhe sono uguali");
        }
            else if(compara<0)
            {
                printf("\nla prima parola e' piu' PICCOLA della seconda [parola1<parola2]");
            }
             else
             {
                 printf("\nla prima parola e' piu' GRANDE della seconda [parola1>parola2]");
             }



    return 0;
}
