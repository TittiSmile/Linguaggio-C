#include <stdio.h>
#define max 50
int main ()
{
    FILE*pf;
    int x=5;
    int y=33;
    char nome[max];

    /*in questo caso,ho voluto che venisse digitato da tastiera il nome del file. così facendo, viene creato un file
    dove ci sono questi numeri.
    ATTENZIONE! il file digitato da tastiera (quidni pf=fopen(nome,"w") non è visualizzato
    come file di testo (.txt) ma il pc lo visualizza con un'estensione a caso (ti dice: apri con... e metti block notes)
    SE invece,utilizzo la scrittura pf=fopen("prova.txt","w") e il file prova.txt esiste già,va a scrivere su quello.
    OPPURE se pf=fopen("lol.txt","w") non esiste,te lo crea e ci scrive i numeri.*/
    printf("come si chiama il tuo file di testo?  ");
    scanf("%s",nome);

    pf=fopen(nome,"w");
     //pf=fopen("provaa.txt","w");
    if(pf==NULL)
    {
        printf("errore di apertura");
    }

    fprintf(pf," %d \n ",x);

    fprintf(pf," \n %d ",y);

    fclose(pf);

    ///se il nome non lo fai digitare da tastiera,questa printf non va bene. puoi scrivere,però, è stato scritto sul file...
    printf("ho scritto sul file '%s'",nome);

    return 0;
}
