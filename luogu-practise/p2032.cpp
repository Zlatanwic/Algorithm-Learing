#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
int a[N]={0};
int l=1;int r=0;
int q[N]={0};
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while(a[q[r]]<a[i]&&l<=r){
            r--;
        }
        q[++r]=i;
        if(i-q[l]>=k){
            l++;
        }
        if(i>=k)
            printf("%d\n",a[q[l]]);
    }
    return 0;
}