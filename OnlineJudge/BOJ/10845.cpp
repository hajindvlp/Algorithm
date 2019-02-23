#include <iostream>
using namespace std;

class queue{
private:
    int q[10001]={0};
    int head=0, tail=0;
public:
    void push(int x){
        q[tail++] = x;
    }
    void pop(){
        head++;
    }
    int front(){
        return q[head];
    }
    int back(){
        return q[tail-1];
    }
    int size(){
        return tail - head;
    }
    int empty(){
        return (tail - head == 0) ? 1 : 0;
    }
};

int main() {
    int t;
    queue q;
    scanf("%d", &t);
    while(t--){
        char arr[10]={0};
        scanf("%s", arr);
        if(arr[0] == 'p' && arr[1] == 'u'){
            int x; scanf("%d", &x);
            q.push(x);
        }
        else if(arr[0] == 'p' && arr[1] == 'o'){
            if(!q.empty()){
                printf("%d\n", q.front());
                q.pop();
            }
            else{
                printf("-1\n");
            }
        }
        else if(arr[0] == 'f'){
            if(!q.empty()){
                printf("%d\n", q.front());
            }
            else{
                printf("-1\n");
            }
        }
        else if(arr[0] == 'b'){
            if(!q.empty()){
                printf("%d\n", q.back());
            }
            else{
                printf("-1\n");
            }
        }
        else if(arr[0] == 's'){
            printf("%d\n", q.size());
        }
        else{
            printf("%d\n", q.empty());
        }
    }

    return 0;
}
