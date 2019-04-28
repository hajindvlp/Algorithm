#include <stdio.h>
int max(int a, int b) {
    return (a>b) ? a : b;
}
int min(int a, int b) {
    return (a<b) ? a : b;
}
int dp_min[100001][3], dp_max[100001][3];
int max_gab, min_gab, i, j, n,a,b,c;
int main() {
    scanf("%d", &n);
    for(i = 1; i<=n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(i == 1) {
            dp_min[i][0] = dp_max[i][0] = a;
            dp_min[i][1] = dp_max[i][1] = b;
            dp_min[i][2] = dp_max[i][2] = c;
        }
        else {
            for (j = 0; j<3; j++) {
                if (j == 0) {
                    dp_max[i][j] = max(dp_max[i-1][j], dp_max[i-1][j+1]) + a;
                    dp_min[i][j] = min(dp_min[i-1][j], dp_min[i-1][j+1]) + a;
                }
            else if (j == 2) {
                dp_max[i][j] = max(dp_max[i - 1][j], dp_max[i - 1][j - 1]) + c;
                dp_min[i][j] = min(dp_min[i - 1][j], dp_min[i - 1][j - 1]) + c;
            }
            else {
                dp_max[i][j] = max(max(dp_max[i-1][j-1], dp_max[i-1][j]), dp_max[i-1][j+1]) + b;
                dp_min[i][j] = min(min(dp_min[i-1][j-1], dp_min[i-1][j]), dp_min[i-1][j+1]) + b;
            }
        }
        }
    }
    max_gab = dp_max[n][0]; min_gab = dp_min[n][0];
    for(i = 1; i<3; i++) {
        if(max_gab<dp_max[n][i])max_gab=dp_max[n][i];
        if(min_gab>dp_min[n][i])min_gab=dp_min[n][i];
    }
    printf("%d %d", max_gab, min_gab);
    return 0;
}
