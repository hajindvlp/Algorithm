#include <stdio.h>

int main(){
    int x,y,sum = 0;
    scanf("%d %d",&x,&y);

    for (int i = 1; i<x; i++){
    	switch (i){
    		case 1: case 3: case 5: case 7: case 8: case 10: case 12: sum += 31; break;
    		case 4: case 6: case 9: case 11: sum += 30; break;
    		case 2: sum += 29; break;
    	}
    }

    sum += y;
	sum %= 7;

	switch (sum){
		case 2: printf("������"); break;
		case 3: printf("ȭ����"); break;
		case 4: printf("������"); break;
		case 5: printf("�����"); break;
		case 6: printf("�ݿ���"); break;
		case 0: printf("�����"); break;
		case 1: printf("�Ͽ���"); break;
	}

    return 0;
}
