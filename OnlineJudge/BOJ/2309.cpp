#include<iostream>
#include<algorithm>
using namespace std;

#define N 9
#define MAX 100

//아홉 난쟁이 키 값의 합을 리턴하는 함수
int GetSum(const int *arr){
    int sum =0;
    for(int i=0; i<N; i++){
        sum += arr[i];
    }
    return sum;
}

//아홉 난쟁이 키 값에서 두명의 난쟁이의 키를 뺸 합이 100인 것을 판별
int Solution(int *arr){
    int sum = GetSum(arr);

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(sum - (arr[i] + arr[j]) == MAX){
                arr[i] = -1;
                arr[j] = -1;
                return 0;
            }
        }
    }

    return -1;
}

int main(void){

    //입력
    int arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }


    Solution(arr);  //알고리즘

    sort(arr, arr+N); //오름차순으로 정렬

    //출력
    for(int i=2; i<N; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
