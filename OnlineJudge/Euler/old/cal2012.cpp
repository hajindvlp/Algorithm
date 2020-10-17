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
		case 2: printf("월요일"); break;
		case 3: printf("화요일"); break;
		case 4: printf("수요일"); break;
		case 5: printf("목요일"); break;
		case 6: printf("금요일"); break;
		case 0: printf("토요일"); break;
		case 1: printf("일요일"); break;
	}

    return 0;
}
