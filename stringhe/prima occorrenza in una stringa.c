#include <stdio.h>
#include <string.h>
#define max 30

int posizione (char str[],char c );   ///posso anche dichiararla come int posizione (char *str,char c)

int main ()
{
    char stringa[max];
    char c;
    char variabile;

    printf("digita la stringa\n");
    scanf("%s",stringa);///N.B.!!!! Non so perchè,in alcuni esercizi mettono con le stringhe anche l'operatore '&'. in questo caso metterlo o meno è INDIFFERENTE
    c=getchar();
    printf("di quale carattere contare l'occorrenza?\n");
    scanf("%c",&c);
    variabile=posizione(stringa,c);
    printf("la prima occorrenza e': %d ",variabile);
    printf("\nla stringa digitata e': %s ",stringa);

    return 0;
}


int posizione (char str[],char c )
{
    int app;
    ///N.B.!!! sono due if uno dopo l'altro e senza parentesi e si può fare!! poitrei scrivere anche if(..) return 0 e if (..) return 0
    ///ma ciò mi complicherebbe la vita!!!
 if(str[0] != '\0')
    if(str[0] == c)
      return 0;
    else{
       app = posizione(str+1,c);
      //return app != -1 ? ++app : app;            ho "parafrasato" l'operatore ternario
      if(app!=-1)
      {
           app++;
      }
      else
      {
           app;
      }
return app;
    }
  else
    return -1;






/* ESEMPIO di scrittura dell'operatore ternario!
if (alfa > beta)
  max = alfa;
else
  max = beta;

// che corrisponde a…
max = (alfa > beta) ? alfa : beta;*/




}
