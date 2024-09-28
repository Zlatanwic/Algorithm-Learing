#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int h[N];int ans[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    stack<int>st;
    for(int j=n;j>=1;j--){
        while(!st.empty()&&h[st.top()]<=h[j])st.pop();
        
        if(st.empty())
            ans[j]=0;
        else{
            ans[j]=st.top();
        }
        st.push(j);
    }
    for(int t=1;t<=n;t++){
        printf("%d\n",ans[t]);
    }
    return 0;
}