#include <stdio.h>

int main()
{
    int i,sum=0;
    // 1~100求和
    for(i = 0; i <= 100; i ++)
        // 加上
        sum += i;
    printf("1~100的和为: %d\n",sum);
    return 0;
}