#include <stdio.h>

int main()
{
    char a,b,c,tmp;
    printf("start...\n");
    while(scanf("%c%c%c%*c",&a,&b,&c)!=EOF)
    {
        if(a>b) tmp=a,a=b,b=tmp;
        if(a>c) tmp=a,a=c,c=tmp;
        if(b>c) tmp=b,b=c,c=tmp;
        printf("%c %c %c\n",a,b,c);
    }
    return 0;
}