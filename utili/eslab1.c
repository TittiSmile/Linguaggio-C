#include <stdio.h>

int rewerse(int numero);

int main ()
{

int n=1234;
printf("%d \n",n);
printf("%d",rewerse(n));



    return 0;
}


int  rewerse(int numero)
{
   int ris = 0;

    while(numero)
    {
    ris = ris * 10 + numero % 10;
    numero /= 10;
    }

return ris;

}
