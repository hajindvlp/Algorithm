#include <cstdio>

using namespace std;



int T, a, b, res;



int main() {

    scanf("%d", &T);



    while (T--) {

        res = 1;

        scanf("%d %d", &a, &b);



        while (b--) {

            res = res * a % 10;

        }



        if (res == 0) printf("10\n");

        else printf("%d\n", res);

    }



    return 0;

}
