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
    int sum,arrSize,num;
    int arr[100];
    //遍历
    for(int i = 2; i <= 100; i ++)
    {
        // 判断是否是素数
        if(isPrime(i))
        {
            // 是素数，加到数组中
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

    // 1~100求和
    for(int i = 1; i <= 100; i ++)
    {
        // 加上
        sum += i;
    }
    printf("1~100的和为: %d\n",sum);
    return 0;
}