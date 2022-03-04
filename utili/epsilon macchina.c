#include <stdio.h>
#include <stdlib.h>

/* programma per calcolo dell'epsilon macchina assoluto ovvero la precisione della macchina stessa dato che
 In informatica l'epsilon di macchina è il più piccolo numero
 appartenente a un dato insieme F di numeri in virgola mobile, diverso in valore assoluto da zero,
 che sommato all' unità, dà un risultato diverso da 1. */

float epsilon_macchina(int,float);

int main()
{
    int base=2; //diamo valore 2 alla base
    float E=1.0; //diamo valore 1.0 ad E

    printf("Epsilon macchina = %.16f\nby nicola leccisi\n",epsilon_macchina(base,E));

system("pause");
return 0;
}

float epsilon_macchina(int base, float E)
{
    float result=0, flag=0;

    while(flag!=1)
    {
        result=E;
        E=E/(float)base;
        flag=E+1;
    }
return result;
}
