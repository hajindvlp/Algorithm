#include <iostream>
#include <string>
using namespace std;
int main() {
    int i=0,respos;
    string s,shifted,res,z="";
    cin>>s;
    res = shifted = s +"0000";
    respos=res.size();
    for(i=s.size()-1;i>=0;i--){
        respos--;
        if(s[i]=='0')  continue;
        res[respos]++;
    }
    for(i=res.size()-1;i>0;i--){
        if(res[i]>='2'){
            res[i-1] += (res[i]-'0')/2;
            res[i] = ((res[i]-'0')%2)+'0';
 
        }
    }
    if(res[0]=='2') res[0]='0',cout<<"1";
    else if(res[0]=='3') res[0]='1',cout<<"1";
    else if(res[0]=='4') res[0]='0',cout<<"10";
    cout<<res;
}