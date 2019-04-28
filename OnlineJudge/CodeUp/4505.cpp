#include <stdio.h>
#include <string.h>

int num[200], renum[5][4], cnt, acnt;
char a[15], b[15], ans[15];
int alen, blen, anum, bnum, sum;

int main()
{
    int i, j, tmp;

    num['I'] = 1, num['V'] = 5, num['X'] = 10, num['L'] = 50;
    num['C'] = 100, num['D'] = 500, num['M'] = 1000;
    renum[1][1] = 'I', renum[1][2] = 'V', renum[1][3] = 'X';
    renum[2][1] = 'X', renum[2][2] = 'L', renum[2][3] = 'C';
    renum[3][1] = 'C', renum[3][2] = 'D', renum[3][3] = 'M';
    renum[4][1] = 'M';

    scanf("%s %s", &a[1], &b[1]);
    alen = strlen(&a[1]);
    blen = strlen(&b[1]);

    for(i=1 ; i<=alen ; i++)
    {
        if(num[a[i]]<num[a[i+1]])
            anum+=num[a[i+1]]-num[a[i]], i++;
        else
            anum+=num[a[i]];
    }
    for(i=1 ; i<=blen ; i++)
    {
        if(num[b[i]]<num[b[i+1]])
            bnum+=num[b[i+1]]-num[b[i]], i++;
        else
            bnum+=num[b[i]];
    }
    sum = anum+bnum;
    printf("%d\n", sum);

    while(sum)
    {
        tmp = sum%10;
        sum/=10;
        cnt++;
        if(tmp<=3)
            for(i=1 ; i<=tmp ; i++)
                ans[++acnt] = renum[cnt][1];
        else if(tmp==4)
            ans[++acnt] = renum[cnt][2], ans[++acnt] = renum[cnt][1];
        else if(tmp>=5 && tmp<=8)
        {
            for(i=1 ; i<=tmp-5 ; i++)
                ans[++acnt] = renum[cnt][1];
            ans[++acnt] = renum[cnt][2];
        }
        else if(tmp == 9)
            ans[++acnt] = renum[cnt][3], ans[++acnt] = renum[cnt][1];
    }

    for(i=acnt ; i>=1 ; i--)
        printf("%c", ans[i]);
}
