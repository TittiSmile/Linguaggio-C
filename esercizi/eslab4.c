#include <stdio.h>
#include <string.h>

int main ()
{
    char parola[5];
    int cont;
    printf("inserisci una stringa di max 4 caratteri: ");
    scanf("%s",parola);
    cont=strlen(parola);
    printf("la lunghezza della parola e': %d ",cont);


    return 0;
}
