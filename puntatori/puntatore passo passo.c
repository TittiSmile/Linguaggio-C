#include <stdio.h>
int main ()
{
    int a=5;
    int *p;
    printf("puntatore: %d \n(indirizzo di memoria del puntatore *p)", p);

    p=a;
    printf("\npuntatore: %d \n( p=a, ovvero associo a 'p' il valore di 'a')", p);

    p=&a;
    printf("\npuntatore: %d \n(p=&a, associo a 'p' l'indirizzo di memoria di 'a'", p);

    p=11;
    printf("\npuntatore: %d \n(p=11, il valore di 'p' cambia ma,più in particolar modo, cambia il valore di 'a') ", p);
    ///potrei anche semplicemente fare la printf di '*p' che sarebbe 5 perchè punta al valore 5(di 'a')

    printf("\nnumero: %d \n(è cambiato anche il valore di 'a' perchè abbiamo scritto 'p=a'",a);

    return 0;
}
