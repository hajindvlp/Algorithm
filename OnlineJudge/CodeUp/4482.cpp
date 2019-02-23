#include<iostream>
using namespace std;

int main() {
    int N, cnt=0;
    int a, b=1, c=1;
    int tr[500001];
    cin >> N;

    for(a=N; a>=b; b++) {
        a -= b+c;
        for(; a>=c; c++, a--) {
            if(a<b) break;
            if(a<b+c) {
                tr[cnt++] = a*b*c;
            }
        }
        a=N;
        c = 1;
    }

    int ca = 0;

    for(int i = 0; i < cnt; i++) {
        for(int j = i+1; j < cnt; j++) {
            if(tr[i] == tr[j]) {
                ca++;
                break;
            }
        }
    }
    cout << cnt - ca << endl;
    return 0;
}
