#include <bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int maxsum=-INF;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        
        sum+=a;
        if(sum>maxsum){
            maxsum=sum;
        }
        
        if(sum<0){
            
            sum=0;
        }
    }
    cout<<maxsum<<endl;

    return 0;

}
