#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 10000006
int a[MAX+1], b[MAX+1];

void print(int* a, int n)
{
    int i, j;
    for(i = 1, j = 0; i <= n; i+=j)
    {
        for(j = 0; j < 10 && i + j <= n; j++)
            printf("%d ", a[i+j]);
        printf("\n");
    }
    /*for(int i = 1; i <= n; i++)
        printf("%10d\n", a[i]);*/
    printf("\n");
}

bool judge(int *a, int n, int p)
{
    int m = pow(10, p);
    for(int i = 1; i <= n; i++)
        if(a[i] / m > 0)
            return true;
    return false;
}

void radix_sort(int *a, int n, int p)
{
    int c[10];
    int m = pow(10, p);

    for(int i = 0; i < 10; i++)  //初始化
        c[i] = 0;
    for(int i = 1; i <= n; i++)   //统计
    {
        int q = (a[i] / m) % 10;
        c[q]++;
    }
    for(int i = 1; i < 10; i++)    //计算每个数的位置
        c[i] += c[i-1];
    for(int i = n; i > 0; i--)  //重新排位置
    {
        int q = (a[i] / m) % 10;
        b[c[q]] = a[i];
        c[q]--;
    }
    for(int i = 1; i <= n; i++)      //重新覆盖a
        a[i] = b[i];
    //print(a, n);
}

int main()
{
    int n;
    printf("输入数据的数量：");
    scanf("%d", &n);

    srand((int)time(0));
    for(int i = 1; i <= n; i++)
        a[i] = rand();
    //print(a, n);

    for(int i = 0; judge(a, n, i) == true; i++)
        radix_sort(a, n, i);

    //print(a, n);
    return 0;
}
