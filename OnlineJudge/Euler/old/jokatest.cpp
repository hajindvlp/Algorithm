#include <stdio.h>

/*int main() // 1��
{
    int a, b, c, d;

    printf("������ �Է��Ͻÿ� : ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a>b && a>c && a>d)
        printf("%d", a);
    else if(b>a && b>c && b>d)
        printf("%d", b);
    else if(c>a && c>b && c>d)
        printf("%d", c);
    else
        printf("%d", d);
    return 0;
}

int main() // 2��
{
    int x, y;

    scanf("%d", &x);

    y = (3*x*x - 7*x + (float)9/(2*x));
    printf("%d", y);
}


int result[101]; // 3��

int main()
{
    int n, i, x;

    scanf("%d %d", &n, &x);

    for(i=1 ; n>0 ; i++)
    {
        result[i] = n%2;
        n/=2;
    }

    printf("%d", result[x]);
    return 0;
}


int result[101], spd[9]; // result = 2���� �迭 // 3��

int main()
{
    int n, i, sum = 0, k = 1;

    scanf("%d", &n);

    for(i=1 ; n>0 ; i++)
    {
        result[i] = n%2;
        n/=2;
    }

    for(i=10 ; i>=2 ; i--)
    {
        printf("%d ", result[i]); //10���� 2 ���� bit
    }

    printf("\n");

    for(i=2; i<=10; i++)
    {
        if(result[i]%2==0)
            sum+=0;
        else{
            sum+=k;
        }
        k*=2;
    }
    printf("%d", sum);
}
*/
