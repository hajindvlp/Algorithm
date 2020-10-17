#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int func[9][2]={{3,2},{1,1},{4,1},{1,0},{5,1},{5,6},{3,7},{8,7},{5,0}};
int main(){
    string n;
    int r=0;
    cin>>n;
    int here=0;
    for(int i=0;i<n.length();i++)
        here=func[here][n[i]-'0'];
    if(here==0||here==6||here==7)
        r=1;
    printf("%s\n",r?"SUBMARINE":"NOISE");
}