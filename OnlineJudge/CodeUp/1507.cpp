#include <stdio.h>
#include <string.h>
char stack[210];
int top;
void push(char p){
    stack[top]=p;
    top++;
}
void pop(){
    top--;
}
int main(){
    int n,i,j;
    char a[210];
    scanf("%d\n",&n);
    gets(a);
    for(i=n-1 ; i>=0 ; i--){
        push(a[i]);
        if(i%3==0 && i!=0)
            push(',');
    }
    i=top-1;
    while(top!=0){
        printf("%c",stack[i]);
        i--;
        pop();
    }
}
