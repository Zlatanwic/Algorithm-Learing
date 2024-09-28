#include <bits/stdc++.h>
using namespace std;

const int N=2000005;
int s[N];
int a[N];
deque<int>dq;
int main()
{
    int n;int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=n+1;i<=n+n-1;i++){
        a[i]=a[i-n];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n+n-1;i++){
        while(!dq.empty()&&max(i-n+1,1)>dq.front())
            dq.pop_front();
        while(!dq.empty()&&s[dq.back()]>=s[i])
            dq.pop_back();
        dq.push_back(i);
        
        if(i-n+1>0&&s[dq.front()]-s[i-n]>=0)
            ans++;
    }
    cout<<ans;
    return 0;

}