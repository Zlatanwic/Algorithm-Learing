#include<bits/stdc++.h>
using namespace std;
const int N=1030;
char s[N];

void buildtree(int b,int e)
{
    int mid=(b+e)/2;
    if(b<e){
        buildtree(b,mid);
        buildtree(mid+1,e);
    }
    int zero=0,one=0;
    for(int i=b;i<=e;i++){
        if(s[i]=='0')zero++;
        else
            one++;
    }
    if(zero&&one)printf("%c",'F');
    else if(zero)printf("%c",'B');
    else printf("%c",'I');
    
}

int main()
{
    int n;
    cin>>n;
    scanf("%s", s+1);
    buildtree(1,pow(2,n));
    return 0;
}
