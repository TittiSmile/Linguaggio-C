#include <stdio.h>
#include <stdlib.h>

int main ()
{
    FILE*pf;
    int i=0;
    char array[20];
    char s[20];

    pf=fopen("file.txt","r");
    for(i=0;i<20;i++)
    {
        fgets(s,20,pf);
        array[i];
    }

    for(i=0;i<20;i++)
    {
        printf("questo e' l'array: %\n", array[i]);
    }


    fclose(pf);




    return 0;
}
