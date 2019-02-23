#include <stdio.h>

int main(void) {
    int i;
    int n;
    int mul = 1, rem;
    scanf("%d", &n);
    for (i=2; i<=n; ++i) {
    	rem = i;
    	while (rem % 10 == 0) { // rem이 10의 배수가 아닐 때까지
    		rem /= 10; // 10으로 나눈다
    	}
        mul = mul * rem; // 서로 곱한다
        while (mul % 10 == 0) { // mul이 10의 배수가 아닐 때까지
            mul /= 10; // 나눈다
        }
        mul %= 100000; // 오버플로우를 방지하기 위해 필요한 자릿수만 남긴다
//      printf("%d!\t: %d\n", i, mul);
    }
    printf("%d", mul % 10); // 남은 mul의 마지막 자리수만 출력한다
    return 0;
}
