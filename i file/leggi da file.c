#include <stdio.h>
#include <stdlib.h>

int main ()
{

    FILE*pf;
    char a[50];


    pf=fopen("file.txt","r");
    while(1)
    {
        fgets(a,50,pf);
        printf("%s",a);
        break;
    }

    /*while(!feof(pf))
    {
        fgets(a,50,pf);
        printf("%s",a);
    }                           sono due cicli uguali*/

    fclose(pf);

    return 0;
}
