#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

int level[200001];
queue<int> Q;

int main(void)
{
    int N, K;

    for (int i = 0; i <= 100000; i++) level[i] = INF;

    scanf("%d %d", &N, &K);
    Q.push(N);
    level[N] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int arr[3] = { cur + 1, cur - 1, cur * 2 };
        for (int i = 0; i < 3; i++) 
            if (arr[i] >= 0 && arr[i] <= 100000 && level[arr[i]] > level[cur] + (i != 2)) {
                level[arr[i]] = level[cur] + (i != 2);
                Q.push(arr[i]);
            }
    }
    printf("%d", level[K]);
}