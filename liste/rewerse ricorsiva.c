#include <stdio.h>

int rewerser(int numero);
int rewerse (int numero);

int main ()
{
    int n=9364;

    printf("%d\n",n);
    printf("%d\n",rewerse(n));
    printf("%d\n",rewerser(n));


    return 0;
}


int rewerser(int numero)
{
  if(numero==0)
    return 1;
  else
    return rewerser(numero%10)/10;



}

int rewerse (int numero)
{
    int ris = 0;

    while(numero)
    {
      ris = ris * 10 + numero % 10;
      numero /= 10;
    }

return ris;
}
