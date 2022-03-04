#include <stdio.h>
#include <stdlib.h>
typedef struct OGGETTI
{
    int peso;
    int prezzo;
}obj;

void stampa(obj v[]);
obj*insert(obj v[]);

int main ()
{
    obj v[1];
    printf("ecco peso e prezzo: \n\n\n");
    insert(v);
    stampa(v);


return 0;
}

void stampa(obj v[])
{
    int i=0;
   for(i=0;i<1;i++)
   {
       printf("peso:%d\nprezzo:%d\n",v[i].peso,v[i].prezzo);
   }

}

obj*insert(obj v[])
{
    int i=0;
    for(i=0;i<1;i++)
    {
        v[i].peso=12;
        v[i].prezzo=4;
    }
    return v;
}
