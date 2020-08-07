#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

pair<vector<string>, int> erase(int n, int m, vector<string> a) {
    int i, j, k;
    bool beErase[35][35];
    int sum;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            beErase[i][j] = false;

    for (i = 1; i < n; i++)
        for (j = 1; j < m; j++)
            if (a[i][j] != 0 && a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j - 1])
                beErase[i][j] = beErase[i - 1][j] = beErase[i][j - 1] = beErase[i - 1][j - 1] = true;

    sum = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (beErase[i][j])
                a[i][j] = 0, sum++;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%c ", (a[i][j] == 0) ? ' ' :a[i][j] );
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        for (j = n - 2; j >= 0; j--) {
            if (a[j][i] != 0 && a[j+1][i] == 0) {
                k = j + 1;
                while (1) {
                    if (k>=n || a[k][i] != 0) break;
                    k++;
                }

                a[k - 1][i] = a[j][i];
                a[j][i] = 0;
            }
        }
    }

    return { a, sum };
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1) {
        pair<vector<string>, int> t = erase(m, n, board);
        if (t.second == 0) break;
        else {
            answer += t.second;
            board = t.first;
        }
        printf("\n");
    }

    return answer;
}

int main() {
    vector<string> a;
    a.push_back("CCBDE");
    a.push_back("AAADE");
    a.push_back("AAABF");
    a.push_back("CCBBF");
    solution(4, 5, a);
}