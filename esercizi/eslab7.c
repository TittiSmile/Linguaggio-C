#include <stdio.h>

int main ()
{
    char parola[10]={"treno"};/// puoi anche prendere la parola da input
    int i=0,j=0,temp,lunghezza;

    lunghezza=strlen(parola);
    j=lunghezza-1;
    while(i<j)
    {
        temp=parola [i];
        parola[i]=parola[j];
        parola[j]=temp;
        i++;
        j--;
    }
    printf("la parola al contrario e': %s ",parola);



/*
   printf("la parola e': %s",parola);

   for(i=strlen(parola)-1;i>=0;i--)
    {
            printf("\nparola al contrario: %c",parola[i]);
    }

*/
///questo metodo è pur sempre VALIDO. l'unica pecca è che la parola non viene scritta in una sola riga.






    return 0;
}
