#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    FILE*pf;
    int max=0;
    char *cont;
    char parola[100];

    pf=fopen("lunga.txt","r");
    if(pf==NULL)
    {
        printf("errore di apertura");
        return 1;
    }

    while(1)
    {
        cont=fgets(parola,"100",pf);
          if(cont==NULL)
          {
              break; ///il break,in questo caso,posso usarlo perch� sono in un ciclo while. (per spiegazioni apri 'leggo caratteri da file(uso fgets)
          }
         if(strlen(parola)-1>max)
         {
             max=strlen(parola)-1;
             /*
             Si noti che la lunghezza della linea letta � strlen(buf)-1 e non strlen(buf) come ci si potrebbe aspettare.
             Per capire come mai il programma funziona in questo modo, osserviamo che la funzione fgets legge una intera
             linea incluso il carattere di fine linea. Questo significa che se una linea � lunga dieci caratteri, la stringa
             che viene memorizzata � lunga undici caratteri, cio� i dieci che compongono effettivamente la linea pi� il
             carattere di ritorno a capo '\n'. La funzione strlen ritorna la lunghezza complessiva della stringa memorizzata,
             metre per noi la lunghezza di una linea di testo � il numero di caratteri nella linea, escluso quindi il carattere
              di ritorno a capo.
             */
         }
    }
    fclose(pf);

    printf("la parola pi� lunga � alla riga: %d",max);


    return 0;
}

/*
#include<stdlib.h>
#include<stdio.h>

int main() {
  FILE *fd;
  char buf[200];
  char *res;
  int max;


		/* apre il file */
/* fd=fopen("lunga.txt", "r");
  if( fd==NULL ) {
    perror("Errore in apertura del file");
    exit(1);
  }*/


		/* lettura per righe */
  /*max=0;
  while(1) {
    res=fgets(buf, 200, fd);
    if( res==NULL )
      break;
    if( strlen(buf)-1 > max )
      max=strlen(buf)-1;
  }
*/

		/* chiude il file */
 /* fclose(fd);
*/

		/* stampa la massima lunghezza */
 /* printf("Lunghezza massima di linea: %d\n", max);

  return 0;
}
*/
