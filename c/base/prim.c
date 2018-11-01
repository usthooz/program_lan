# include <stdio.h>

int main()
{
    int a,b;
    int k=0;
    for (a=2;a<200;a++)
    {
        int t=1;
        for (b=2;b<a;b++)
        {
            if(a%b==0)
            {
                t=0;
                break;
            }
        }
        if(t==1)
        {
            k++;
            printf("%d ",a);
            if (k%3==0)
            {
                printf("\n");
            }
        }
    }
    return 0;
}