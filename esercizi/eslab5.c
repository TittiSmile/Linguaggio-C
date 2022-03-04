#include <stdio.h>
#include <string.h>
int main ()
{

    //char parola1[10]={"ciao"};  /////strcat funziona sia se mettiamo noi una parola
    //char parola2[10]={"TUTTI"};

    char parola1[10];
    char parola2[10];


    printf("digita una parola: ");       ///sia se la chiediamo all'utente
    scanf("%s",parola1);
    printf("\ndigita una seconda parola: ");
    scanf("%s",parola2);

    //strcat(parola1,"ciao");              //sia se la scriviamo così anche se bho,esce una lettera a scazzo
    //strcat(parola1,"PUPO");

    //strcat(parola1,parola2);

     printf("le due stringhe concatenate sono: %s",parola1); /// funziona in tutti i casi.


    return 0;
}
