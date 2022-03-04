#include <stdio.h>
#include <stdlib.h>
int main ()
{
    char frase[100];
    FILE*fp;
    char *controllo;

    fp=fopen("righe.txt","r");
    if(fp==NULL)
    {
        printf("errore di apertura");
        return 1;
    }

    while(1)
    ///questa condizione vuol dire: finchè è vero (ogni valore diverso da 0 è vero,in booleano) fai questo.
    ///essendo 1 sempre vero,questo ciclo si azionerà sempre. potrei metterci qualsiasi valore.
    ///tecnicamente,potrei evitare di fare il  ciclo semplicemente mettendo nell'if un return 1 (come il controllo sopra)
    ///funzionano entrambi bene. N.B. la funzione fgets prende tutto quello che trova,anche i caratteri a capo
    {
        controllo=fgets(frase,100,fp);
    /*Si faccia attenzione al fatto che il valore di ritono della funzione fgets
    (che serve per capire quando il file è finito) è di tipo puntatore a carattere
    (ossia char *), e non intero come nel caso di fscanf. Questo puntatore non deve ovviamente venire inizializzato.*/
        if(controllo==NULL)
        {
            //return 1;
            break;
        }
        printf("la frase nel file e': %s",frase);
    }

    fclose(fp);

    return 0;
}

