/*stampa stringhe simili*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simili(char*s1,char*s2);

int main ()
{
    char s1[20];
    char s2[20];
    int res;
    printf("digita la prima parola: ");
    scanf("%s",s1);
    printf("digita la seconda parola: ");
    scanf("%s",s2);
    res=simili(s1,s2);
    printf("\n%d",res);


    return 0;
}


int simili(char*s1,char*s2)
{
    int res=0;
    int l1=strlen(s1);
    int l2=strlen(s2);
    if(strcmp(s1,s2)==0)
    {
        res=0;
    }
    else
    {
        if(l1!=l2)
        {
            res=-1;
        }
        else
        {
            if(s1[0]!=s2[0])
            {
                res=simili(s1+1,s2+1)+1;
            }
            else
            {
                res=simili(s1+1,s2+1);
            }
        }
    }

    if(res>1)
    {
        res=-1;
    }
    return res;
}
