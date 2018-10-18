#include <stdio.h>
#include <math.h>

// 判断数字是否是素数
int isPrime(int n)
{
    int i;
    // 从2到算数平方根遍历
    for(i = 2; i <= (int)sqrt(n); i ++)
        if(n%i == 0) 
        {
            return 0;
        }
    // 素数，返回1.
    return 1;
}

int main()
{
    int i,sum,arrSize,num;
    int arr[100];
    //遍历
    for(i = 2; i <= 100; i ++)
    {
        // 1~100求和
        sum += i;
        // 1~100 的所有素数
        if(isPrime(i))
        {
            arr[arrSize++]=i;
        }
    }
    // 输出所有素数
    printf("1~100的所有素数为:\n");
    for (int j=0;j<arrSize;j++)
    {
        printf("%d ", arr[j]);
        num += j;
    }
    printf("\n");
    printf("1~100所有素数个数为: %d\n",arrSize);
    printf("1~100所有素数的和为: %d\n",num);
    printf("1~100的和为: %d\n",sum+1);
    return 0;
}