#include <bits/stdc++.h>
using namespace std;
deque<int>dq;
const int N=500005;
int s[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    for(int i=1;i<=n;i++)s[i]=s[i]+s[i-1];  //计算器前缀和
    int ans=-1e8;
    dq.push_back(0);
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&dq.front()<i-m)
            dq.pop_front();
        if(dq.empty())
            ans=max(ans,s[i]);
        else
            ans=max(ans,s[i]-s[dq.front()]);
        while(!dq.empty()&&s[dq.back()]>=s[i])dq.pop_back();
        dq.push_back(i);
        
    }
    printf("%d",ans);
    return 0;
}