#include <stdio.h>
int n, cnt;

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        printf("%d %d %d\n", n, from, to);
        cnt++;
    }
    else
    {
        hanoi(n - 1, from, to, by);
        printf("%d %d %d\n", n, from, to);
        cnt++;
        hanoi(n - 1, by, from, to);
    }
}

int main()
{
    scanf("%d", &n);

    hanoi(n, 1, 2, 3);
    printf("%d", cnt);
    return 0;
}
