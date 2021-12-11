#include <stdio.h>
#include <stdlib.h>
int main()
{                                       // n条直线最多可有(n-1)*n/2个交点，20条直线最多190个交点
    int a[21][191] = {0};               //初始化数组全为0
    for (int i = 0; i < 21; i++)
    {
        a[i][0] = 1;                    //令列坐标为0的值都为1（全平行）
    }
    for (int x = 2; x <= 20; x++)                       //总直线数x的循环
    {
        for (int n = 0; n <= x; n++)                    //不平行部分n的循环
        {
            for (int j = 0; j <= (n - 1) * n / 2; j++)  // n的列下标循环【0，(n-1)*n/2】
            {
                if (a[n][j] == 1)                       //若存在n条直线j个交点
                {
                    a[x][(x - n) * n + j] = 1;          //则存在x条直线(x-n)*n+j个交点
                }
            }
        }
    }
 
    int n;
    while (scanf("%d", &n) != EOF)                      //输入n
    {
        for (int i = 0; i <= (n - 1) * n / 2; i++)      //循环列下标i【0,(n-1)*n/2】
        {
            if (a[n][i] == 1)                           //a[n][i]==1表示n条直线可以存在i个交点
            {
                printf("%d ", i);
            }
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}