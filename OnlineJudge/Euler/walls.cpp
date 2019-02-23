#include <stdio.h>
void input(void);
void run(void);
const int MAXREGION=201;
const int MAXTOWN=251;
const int MAXPEOPLE=30;
int region, town, people;
int live[MAXPEOPLE];
int wallside[MAXTOWN][MAXTOWN];
int touch[MAXTOWN][MAXREGION];
int touchnum[MAXTOWN];
int map[MAXREGION][MAXREGION];
int main(void)
{
 input();
 run();
 return 0;
}
void input(void)
{
    int i, p, k, t, last, first;
    scanf("%d%d%d", &region, &town, &people);

    for(i=0; i<people; ++i)
        scanf("%d", &live[i]);

    for(i=1; i<=region; ++i)
        for(k=1; k<=region; ++k)
            map[i][k] = 10000000;

    for(i=1; i<=region; ++i)
        map[i][i] = 0;
    for(i=0; i<region; ++i) {
        scanf("%d", &p);
        for(k=0; k<p; ++k) {
             last = t;
             scanf("%d", &t);
             touch[t][touchnum[t]] = i+1;
             ++touchnum[t];
             if(k>0) {
             if(wallside[last][t]!=0) {
             map[wallside[last][t]][i+1] = 1;
             map[i+1][wallside[last][t]] = 1;
             }
             else {
             wallside[last][t] = i+1;
             wallside[t][last] = i+1;
             }
             }
             else
             first = t;
             }
         if(wallside[first][t]!=0) {
         map[wallside[first][t]][i+1] = 1;
         map[i+1][wallside[first][t]] = 1;
         }
         else {
         wallside[first][t] = i+1;
         wallside[t][first] = i+1;
         }
     }
}
void run(void)
{
int i, k, t;
//all pair shortest path
for(t=1; t<=region; ++t)
for(i=1; i<=region; ++i)
for(k=1; k<=region; ++k) {
 if((int)map[i][t]+(int)map[t][k]<(int)map[i][k])
 map[i][k] = map[i][t]+map[t][k];
 }
int sum, minsum, p, now, meet;
minsum = -1;
for(t=1; t<=region; ++t) {
 sum = 0;
for(i=0; i<people; ++i) {
 p = 10000000;
 now = live[i];
 for(k=0; k<touchnum[now]; ++k)
 if(map[touch[now][k]][t]<p)
 p = map[touch[now][k]][t];
 sum += p;
 }
if(minsum==-1 || sum<minsum) {
 minsum = sum;
 meet = t;
 }
 }
printf("%d\n%d\n", minsum, meet);
}
