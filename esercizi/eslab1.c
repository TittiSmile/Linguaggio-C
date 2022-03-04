#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verifica(char password[]);


int main ()
{
  char password[]="Mai6";
  int funz;

  //printf("inserisci una password di max 29 caratteri che contenga almeno:\nuna lettera maiuscola\nun numero\nun segno\n");
  //scanf("%29s",password);
  funz=verifica(password);




 return 0;
}



int verifica(char password[])
{
    int flag=0;


    if(isdigit(password))
    {
     printf("c'è un numero\n");

    }
        else
        {
            printf("NON c'è un numero");
        }




return flag;
}
