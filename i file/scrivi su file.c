/*questo programma serve a scrivere una stringa su file. il programma successivo,serve a leggere la stringa scritta sul file.
la cosa buffa e divertente è che se la stringa la do di default (riga 20) il programma di lettura legge tranquillamente
tutta la stringa(spazi inclusi). se invece decido di scrivere una stringa da tastiera,il programma di lettura leggerà
soltanto la prima parola in quanto,giustamente,c'è lo spazio. tutto ciò non ha senso ma ok. */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE*pf;
    char a[50];
    int f=5;

    //printf("scrivi una frase (max 50 caratteri) da inserire nel file:\n");
    //scanf("%s",&a);

    pf=fopen("file.txt","w");
    if(pf)
    {
        printf("\nno problemo\n");
       fprintf(pf,"puttana merda tua madre",a); // serve se non voglio far digitare all'utente la stringa.
       //fprintf(pf,"%s",a);
       printf("\nho scritto sul file,imbecille");
    }

    else
    {
        printf("vir ca ce sta cacc probbbbblem.");
    }
      fclose(pf);


    return 0;
}
