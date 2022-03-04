#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE*  pf ;///dichoiaro puntatore a file
    FILE*  fp ;///dichoiaro puntatore a file
    char a[100], c;


    ///apro il file in scrittura....
pf = fopen ( "test.txt" , "w" ) ;

if ( pf == NULL)
{
printf ( " Impossibile aprire il file " ) ;
exit ( 1 ) ;
}

///scrivo sul file


fprintf ( pf , "ciao come stai?" ) ;

fclose(pf);///lo chiudo

///leggo..riapro in lettura...

fp = fopen("test.txt","r");

if ( fp == NULL)
{
printf ( " Impossibile aprire il file " ) ;

 system("PAUSE");
 exit ( 1 ) ;
}

///ogni volta che leggo si autoincrementa il puntatore alla locazione corrente del file
///la funzione feof() torna null quando trova EOF (end of file)...ossia la fine del file
///la uso in un awhile per scandire e leggere tutto il file...
while(!feof(fp))
   {
      c = fgetc(fp); ///preleva e stampa un carattere per volta..

      printf("%c", c);
   }
  fclose(fp);///lo chiudo
  system("PAUSE");
  return 0;
}
