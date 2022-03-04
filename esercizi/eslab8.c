#include <stdio.h>

int main ()
{
    char parola[10]={"divano"}; ///parola NON palindroma.se la si cambia in 'osso',il programma riconosce che è palindromo
    int i=0,j=0;
    int palindromo;   ///in c++ avremmo potuto usare anche il tipo bool
    for(i=0,j=strlen(parola)-1;i<strlen(parola)/2;i++,j--);
     {
         if(parola[i]!=parola[j])
         {
             palindromo=0; ///viene considerato,quindi,come falso
         }
     }

     if(palindromo)
     {
         printf("la parola e' palindroma");
     }
     else
     {
         printf("la parola NON e' palindroma");
     }




    return 0;
}
