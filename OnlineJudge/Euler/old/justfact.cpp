#include <stdio.h>

int main(void) {
    int i;
    int n;
    int mul = 1, rem;
    scanf("%d", &n);
    for (i=2; i<=n; ++i) {
    	rem = i;
    	while (rem % 10 == 0) { // rem�� 10�� ����� �ƴ� ������
    		rem /= 10; // 10���� ������
    	}
        mul = mul * rem; // ���� ���Ѵ�
        while (mul % 10 == 0) { // mul�� 10�� ����� �ƴ� ������
            mul /= 10; // ������
        }
        mul %= 100000; // �����÷ο츦 �����ϱ� ���� �ʿ��� �ڸ����� �����
//      printf("%d!\t: %d\n", i, mul);
    }
    printf("%d", mul % 10); // ���� mul�� ������ �ڸ����� ����Ѵ�
    return 0;
}
