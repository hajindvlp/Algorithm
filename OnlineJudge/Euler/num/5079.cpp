#include <stdio.h>

char a[101];
int b[101], d[100][100], h[100][100], path[100][100], n;

void Trace(int i, int j) 
{
  if (i < j) 
  {
    if (path[i][j] == -1) 
    {
      b[i] = j;
      b[j] = i;
      Trace(i + 1, j - 1);
    } 
    else 
    {
      Trace(i, path[i][j]);
      Trace(path[i][j] + 1, j);
    }
  }
}
int main(void) 
{
    int i, j, k, s;

    scanf("%d", &n);
    scanf("%s", a);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) d[i][j] = -1;

    for (i = 0; i + 1 < n; i++)
        if (a[i] != a[i + 1]) 
        {
            d[i][i + 1] = 3;
            h[i][i + 1] = 1;
            path[i][i + 1] = -1;
        }
    for (s = 2; s < n; s++) 
    {
        for (i = 0; i + s < n; i++) 
        {
            j = i + s;
            if (a[i] != a[j]) 
            {
                if (d[i + 1][j - 1] == -1) 
                    continue;
                d[i][j] = d[i + 1][j - 1] + (h[i + 1][j - 1] + 1) * 2 + j - i;
                h[i][j] = h[i + 1][j - 1] + 1;
                path[i][j] = -1;
            }
            for (k = i + 1; k < j; k++) 
            {
                if (d[i][k] == -1 || d[k + 1][j] == -1) 
                    continue;
                if (d[i][j] == -1 || d[i][j] > d[i][k] + d[k + 1][j]) 
                {
                    d[i][j] = d[i][k] + d[k + 1][j];
                    h[i][j] = h[i][k];
                    if (h[i][j] < h[k + 1][j]) 
                        h[i][j] = h[k + 1][j];
                    path[i][j] = k;
                }
        }
        }
    }
    printf("%d\n", d[0][n - 1]);
    Trace(0, n - 1);
    for (i = 0; i < n; i++)
        if (i < b[i]) printf("%d %d\n", i + 1, b[i] + 1);
}