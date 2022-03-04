#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct STUDENTE
{
    char nome[MAX];
    char cognome[MAX];
    char corso[MAX];
    int anni;

}stud;

//typedef struct STUDENTE stud;

int main ()
{
    stud var;
    int i=0;
    strcpy(var.nome,"cacca");         ///uso strcpy perchè si tratta di copiare una stringa
    strcpy(var.cognome,"pipì");
    strcpy(var.corso,"nullafacenza");
    var.anni=33;

    printf("nome: %s \ncognome: %s\ncorso: %s\nanni: %d\n",var.nome,var.cognome,var.corso,var.anni);

    fflush(stdin);

    printf("\n\n\nqual è il tuo nome?");
    scanf("%s",&var.nome);
    printf("\n\n\nqual è il tuo cognome?");
    scanf("%s",&var.cognome);
    printf("\n\n\nqual è il tuo corso?");
    scanf("%s",&var.corso);
    printf("\n\n\nqual è la tua eta'?");
    scanf("%d",&var.anni);



    printf("nome: %s \ncognome: %s\ncorso: %s\nanni: %d\n",var.nome,var.cognome,var.corso,var.anni);


    return 0;
}
