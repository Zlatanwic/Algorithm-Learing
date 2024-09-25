#include <bits/stdc++.h>
using namespace std;
//deque<int>q;
const int N=2000005;
int  a[N]={0};
int q[N];
int l=1;
int r=1;
int main()
{
    int n,m;
    cin>>n>>m;
    printf("0\n");
    //cout<<0<<endl;
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        //cin>>a[i];
       
            while(r>l&&a[q[r-1]]>=a[i]){
                r--;
            }
            q[r++]=i;
            if(i-q[l]>m-1){
                l++;
            }
            printf("%d\n",a[q[l]]);
            //cout<<a[q[l]]<<endl;
        
    }
    return 0;
}